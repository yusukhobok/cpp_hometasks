#include <iostream>
#include <sys/stat.h>

#include <boost/filesystem.hpp>
#include <boost/regex.hpp>
#include <boost/range/iterator_range.hpp>
#include <boost/algorithm/hex.hpp>
#include <boost/crc.hpp>

#include "duplicate_finder.h"


namespace fs = boost::filesystem;


DuplicateFinder::DuplicateFinder(std::vector<std::string> directories) : directories(std::move(directories)) {}


void DuplicateFinder::set_excluded_directories(std::vector<std::string> excluded_directories_) {
    this->excluded_directories = std::move(excluded_directories_);
}

void DuplicateFinder::set_level(int level_) {
    this->level = level_;
}

void DuplicateFinder::set_minimum_size(int minimum_size_) {
    this->minimum_size = minimum_size_;
}

void DuplicateFinder::set_mask(std::string mask_) {
    this->mask = std::move(mask_);
}

void DuplicateFinder::set_block_size(int block_size_) {
    this->block_size = block_size_;
}

void DuplicateFinder::set_hash_function(std::string hash_function_) {
    this->hash_function = std::move(hash_function_);
}

std::vector<std::string> DuplicateFinder::get_filenames(const std::vector<std::string> &analyzed_directories) const {
    std::vector<std::string> filenames;
    for (const auto &directory: analyzed_directories) {
        if (level == 0) {
            fs::directory_iterator it_begin(directory);
            fs::directory_iterator it_end;
            for (auto &dir_entry: boost::make_iterator_range(it_begin, it_end)) {
                if (is_regular_file(dir_entry)) {
                    filenames.push_back(dir_entry.path().native());
                }
            }
        } else {
            fs::recursive_directory_iterator it_begin_recursive(directory);
            fs::recursive_directory_iterator it_end_recursive;
            for (auto &dir_entry: boost::make_iterator_range(it_begin_recursive, it_end_recursive)) {
                if (is_regular_file(dir_entry)) {
                    filenames.push_back(dir_entry.path().native());
                }
            }
        }
    }
    return filenames;
}

std::unordered_map<size_t, std::vector<std::string>>
DuplicateFinder::get_filenames_by_size(const std::set<std::string> &filenames) {
    std::unordered_map<size_t, std::vector<std::string>> filenames_by_size;
    for (const auto &filename: filenames) {
        struct stat buf{};
        stat(filename.c_str(), &buf);
        filenames_by_size[buf.st_size].push_back(filename);
    }
    return filenames_by_size;
}

std::set<std::string> DuplicateFinder::filter_filenames(
        const std::vector<std::string> &included_filenames, const std::vector<std::string> &excluded_filenames
) const {
    std::set<std::string> filenames;
    for (const auto &included_file: included_filenames) {
        filenames.insert(included_file);
    }
    for (const auto &excluded_file: excluded_filenames) {
        filenames.erase(excluded_file);
    }

    std::set<std::string> filtered_by_size_filenames;
    for (const auto &filename: filenames) {
        struct stat buf{};
        stat(filename.c_str(), &buf);
        if (buf.st_size >= minimum_size) {
            filtered_by_size_filenames.insert(filename);
        }
    }

    std::set<std::string> filtered_by_mask_filenames;
    boost::smatch what;
    for (const auto &filename: filtered_by_size_filenames) {
        const boost::regex re(mask);
        if (boost::regex_match(filename, what, re)) {
            filtered_by_mask_filenames.insert(filename);
        }
    }

    return filtered_by_mask_filenames;
}


size_t DuplicateFinder::hash_using_crc32(const std::string &text) const {
    boost::crc_32_type digest;
    digest.process_bytes(text.data(), text.length());
    return digest.checksum();
}


void DuplicateFinder::print_duplicates(const std::vector<std::string> &filenames) const {
    if (filenames.size() < 2) {
        return;
    }

    std::unordered_map<size_t, std::vector<std::ifstream *>> hash_to_descriptors;
    std::unordered_map<std::ifstream *, std::string> descriptor_to_filename;
    for (const auto &filename: filenames) {
        std::ifstream *file = new std::ifstream(filename, std::ios::in);
        descriptor_to_filename[file] = filename;
        hash_to_descriptors[0].push_back(file);
    }

    while (true) {
        for (auto it = hash_to_descriptors.begin(); it != hash_to_descriptors.end();) {
            if (it->second.size() < 2) {
                it = hash_to_descriptors.erase(it);
            } else {
                ++it;
            }
        }

        std::set<std::ifstream *> not_read_files;
        std::unordered_map<size_t, std::vector<std::ifstream *>> updated_hash_to_descriptors;
        for (const auto &[hash, descriptors]: hash_to_descriptors) {
            for (const auto &file: descriptors) {
                std::vector<char> buffer(block_size);
                file->read(&buffer[0], block_size);
                if (!file->eof()) {
                    not_read_files.insert(file);
                }
                if (hash_function == "crc32") {
                    std::string buffer_string(buffer.begin(), buffer.end());
                    size_t new_hash = hash_using_crc32(buffer_string);
                    updated_hash_to_descriptors[new_hash].push_back(file);
                } else {
                    throw std::runtime_error("Недопустимая хеш-функция.");
                }
            }
        }

        hash_to_descriptors = updated_hash_to_descriptors;
        if (hash_to_descriptors.empty()) {
            return;
        }
        if (not_read_files.empty()) {
            break;
        }
    }

    for (const auto &[hash, descriptors]: hash_to_descriptors) {
        for (const auto &file: descriptors) {
            std::cout << descriptor_to_filename[file] << std::endl;
        }
        std::cout << std::endl;
    }
}


void DuplicateFinder::find() {
    std::vector<std::string> included_filenames = get_filenames(directories);
    std::vector<std::string> excluded_filenames = get_filenames(excluded_directories);
    std::set<std::string> filenames = filter_filenames(included_filenames, excluded_filenames);
    std::unordered_map<size_t, std::vector<std::string>> filenames_by_size = get_filenames_by_size(filenames);
    for (const auto &[_, filenames_with_same_size]: filenames_by_size) {
        print_duplicates(filenames_with_same_size);
    }
}
