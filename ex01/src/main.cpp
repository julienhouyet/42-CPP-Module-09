#include <iostream>
#include <fstream>
#include "../include/RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error: wrong number of arguments." << std::endl;
        return 1;
    }

    RPN rpn;

    std::cout << "Hello RPN ! => " << argv[1] << std::endl;

    return 0;
}