#ifndef HOMETASK_08_BAYAN_DUPLICATE_FINDER_H
#define HOMETASK_08_BAYAN_DUPLICATE_FINDER_H


#include <vector>
#include <string>
#include <set>
#include <unordered_map>


class DuplicateFinder {
private:
    std::vector<std::string> directories;
    std::vector<std::string> excluded_directories;
    int level = 0;
    int minimum_size = 0;
    std::string mask;
    int block_size = 1;
    std::string hash_function = "md5";

    [[nodiscard]] std::vector<std::string> get_filenames(const std::vector<std::string> &analyzed_directories) const;

    static std::unordered_map<size_t, std::vector<std::string>>
    get_filenames_by_size(const std::set<std::string> &filenames);

    [[nodiscard]] std::set<std::string> filter_filenames(
            const std::vector<std::string> &included_filenames, const std::vector<std::string> &excluded_filenames
    ) const;

    void print_duplicates(const std::vector<std::string> &filenames) const;

    size_t hash_using_crc32(const std::string &text) const;

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
