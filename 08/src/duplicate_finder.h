#ifndef HOMETASK_08_BAYAN_DUPLICATE_FINDER_H
#define HOMETASK_08_BAYAN_DUPLICATE_FINDER_H


#include <vector>
#include <string>


class DuplicateFinder {
private:
    std::vector<std::string> directories;
    std::vector<std::string> except_directories;
    int level = 0;
    int minimum_size = 0;
    std::string mask = "";
    int block_size = 1;
    std::string hash_function = "md5";
public:
    DuplicateFinder(std::vector<std::string> directories);
    void set_except_directories(std::vector<std::string> except_directories_);
    void set_level(int level_);
    void set_minimum_size(int minimum_size_);
    void set_mask(std::string mask_);
    void set_block_size(int block_size_);
    void set_hash_function(std::string hash_function_);
    void print();
};


#endif //HOMETASK_08_BAYAN_DUPLICATE_FINDER_H
