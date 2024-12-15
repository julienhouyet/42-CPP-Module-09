#include "../include/PmergeMe.hpp"
#include <iostream>

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error: No arguments." << std::endl;
        return 1;
    }

    try {
        PmergeMe pmergeMe;

        pmergeMe.fillContainers(argv);

        std::cout << "Original: " << std::endl;
        pmergeMe.printVector();
        pmergeMe.printDeque();

        pmergeMe.sortVector();

        std::cout << "\nSorted: " << std::endl;
        pmergeMe.printVector();
        pmergeMe.printDeque();
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}