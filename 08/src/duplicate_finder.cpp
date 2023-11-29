#include <iostream>
#include "duplicate_finder.h"


DuplicateFinder::DuplicateFinder(std::vector<std::string> directories): directories(std::move(directories)) {}

void DuplicateFinder::set_except_directories(std::vector<std::string> except_directories_) {
    this->except_directories = std::move(except_directories_);
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
    for (const auto& dir : directories) {
        std::cout << dir << "; ";
    }
    std::cout << std::endl;

    std::cout << "Excepts: ";
    for (const auto& dir : except_directories) {
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
