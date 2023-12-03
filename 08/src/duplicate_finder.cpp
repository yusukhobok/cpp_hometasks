#include <iostream>
#include <sys/stat.h>

#include <boost/filesystem.hpp>
#include <boost/regex.hpp>
#include <boost/range/iterator_range.hpp>

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

void DuplicateFinder::print() {
    std::cout << "Dirs: ";
    for (const auto &dir: directories) {
        std::cout << dir << "; ";
    }
    std::cout << std::endl;

    std::cout << "Excepts: ";
    for (const auto &dir: excluded_directories) {
        std::cout << dir << "; ";
    }
    std::cout << std::endl;

    std::cout << "Level: " << level << std::endl;
    std::cout << "Minimum size: " << minimum_size << std::endl;
    std::cout << "Mask: " << mask << std::endl;
    std::cout << "Block size: " << block_size << std::endl;
    std::cout << "Hash function: " << hash_function << std::endl;
    std::cout << std::endl;
}

std::vector<std::string> DuplicateFinder::get_files(std::vector<std::string> analyzed_directories) {
    std::vector<std::string> files;

    for (const auto &directory: analyzed_directories) {
        if (level == 0) {
            fs::directory_iterator it_begin(directory);
            fs::directory_iterator it_end;
            for (auto &dir_entry: boost::make_iterator_range(it_begin, it_end)) {
                if (is_regular_file(dir_entry)) {
                    files.push_back(dir_entry.path().native());
                }
            }
        } else {
            fs::recursive_directory_iterator it_begin_recursive(directory);
            fs::recursive_directory_iterator it_end_recursive;
            for (auto &dir_entry: boost::make_iterator_range(it_begin_recursive, it_end_recursive)) {
                if (is_regular_file(dir_entry)) {
                    files.push_back(dir_entry.path().native());
                }
            }
        }
    }
    return files;
}

std::unordered_map<size_t, std::vector<std::string>>
DuplicateFinder::get_files_by_size(std::vector<std::string> files) {
    std::unordered_map<size_t, std::vector<std::string>> files_by_size;
    for (const auto &file: files) {
        struct stat buf;
        stat(file.c_str(), &buf);
        files_by_size[buf.st_size].push_back(file);
    }
    return files_by_size;
}

std::set<std::string> DuplicateFinder::filter_files(
        const std::vector<std::string> &included_files, const std::vector<std::string> &excluded_files
) {
    std::set<std::string> files;
    for (const auto& included_file : included_files) {
        files.insert(included_file);
    }
    for (const auto& excluded_file : excluded_files) {
        files.erase(excluded_file);
    }

    std::set<std::string> filtered_by_size_files;
    for (const auto& file : files) {
        struct stat buf;
        stat(file.c_str(), &buf);
        std::cout << file << " " << buf.st_size << " " << minimum_size << std::endl;
        if (buf.st_size >= minimum_size) {
            filtered_by_size_files.insert(file);
        }
    }

    std::set<std::string> filtered_by_mask_files;
    boost::smatch what;
    for (const auto& file : filtered_by_size_files) {
        const boost::regex re(mask);
        if (boost::regex_match(file, what, re)) {
            filtered_by_mask_files.insert(file);
        }
    }

    return filtered_by_mask_files;
}


void DuplicateFinder::find() {
    std::vector<std::string> included_files = get_files(directories);
    std::vector<std::string> excluded_files = get_files(excluded_directories);
    std::set<std::string> files = filter_files(included_files, excluded_files);
    for (const auto &x: files) {
        std::cout << x << std::endl;
    }

//    std::unordered_map<size_t, std::vector<std::string>> files_by_size = get_files_by_size(files);
//    for (const auto& x : files_by_size) {
//        std::cout << x.first << std::endl;
//        for (const auto& y : x.second) {
//            std::cout << y << std::endl;
//        }
//        std::cout << "=====================" << std::endl;
//    }
}