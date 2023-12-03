#ifndef HOMETASK_08_BAYAN_DUPLICATE_FINDER_H
#define HOMETASK_08_BAYAN_DUPLICATE_FINDER_H


#include <vector>
#include <string>


class DuplicateFinder {
private:
    std::vector<std::string> directories;
    std::vector<std::string> excluded_directories;
    int level = 0;
    int minimum_size = 0;
    std::string mask = "";
    int block_size = 1;
    std::string hash_function = "md5";

    void print();

    std::vector<std::string> get_files(std::vector<std::string> analyzed_directories);

    std::unordered_map<size_t, std::vector<std::string>> get_files_by_size(std::vector<std::string> files);

    std::set<std::string> filter_files(
            const std::vector<std::string> &included_files, const std::vector<std::string> &excluded_files
    );

public:
    explicit DuplicateFinder(std::vector<std::string> directories);

    void set_excluded_directories(std::vector<std::string> excluded_directories_);

    void set_level(int level_);

    void set_minimum_size(int minimum_size_);

    void set_mask(std::string mask_);

    void set_block_size(int block_size_);

    void set_hash_function(std::string hash_function_);

    void find();
};


#endif //HOMETASK_08_BAYAN_DUPLICATE_FINDER_H
