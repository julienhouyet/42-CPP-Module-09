#include "../include/PmergeMe.hpp"
#include <iostream>

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error: No arguments provided." << std::endl;
        return 1;
    }

    try {
        PmergeMe sorter;
        sorter.fillContainers(argv);

        std::cout << "Before: ";
        sorter.printVector();

        clock_t start = clock();
        sorter.sortVector();
        clock_t end = clock();
        double timeVector = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;

        std::cout << "After: ";
        sorter.printVector();
        std::cout << "Time to process a range of 5 elements with std::vector : " << timeVector << " us" << std::endl;

        start = clock();
        sorter.sortDeque();
        end = clock();
        double timeDeque = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;

        std::cout << "Time to process a range of 5 elements with std::deque : " << timeDeque << " us" << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}