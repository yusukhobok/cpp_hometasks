#include <iostream>
#include <string>
#include <vector>

#include <boost/program_options/errors.hpp>
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/value_semantic.hpp>
#include <boost/program_options/variables_map.hpp>

#include "bayan.h"
#include "duplicate_finder.h"

namespace po = boost::program_options;


void start(int argc, char const *argv[]) {
    po::options_description description;
    description.add_options()
            ("help", "Справка")
            ("directories,D", po::value<std::vector<std::string>>(), "Директории для сканирования")
            ("excluded-directories,E", po::value<std::vector<std::string>>(), "Директории для исключения из сканирования")
            ("level,L", po::value<int>(), "Уровень сканирования")
            ("minimum-size,M", po::value<int>(), "Минимальный размер файла, байт")
            ("mask,K", po::value<std::string>(), "Маска имен файлов, разрешенных для сканирования")
            ("block-size,S", po::value<int>(), "Размер блока, байт")
            ("hash-function,H", po::value<std::string>(), "Алгоритм хеширования");

    try {
        po::variables_map vm;
        po::store(po::parse_command_line(argc, argv, description), vm);
        po::notify(vm);

        if (vm.count("help")) {
            std::cout << description << std::endl;
            return;
        }

        if (!vm.count("directories")) {
            throw po::error("There are no directories");
        }
        DuplicateFinder finder = DuplicateFinder(vm["directories"].as<std::vector<std::string>>());

        if (vm.count("excluded-directories")) {
            finder.set_excluded_directories(vm["excluded-directories"].as<std::vector<std::string>>());
        }
        if (vm.count("level")) {
            finder.set_level(vm["level"].as<int>());
        }
        if (vm.count("minimum-size")) {
            finder.set_minimum_size(vm["minimum-size"].as<int>());
        }
        if (vm.count("mask")) {
            finder.set_mask(vm["mask"].as<std::string>());
        }
        if (vm.count("block-size")) {
            finder.set_block_size(vm["block-size"].as<int>());
        }
        if (vm.count("hash-function")) {
            finder.set_hash_function(vm["hash-function"].as<std::string>());
        }
        finder.find();


    } catch (const po::error &exc) {
        std::cout << "Error: " << exc.what() << std::endl;
    }

    ;
}