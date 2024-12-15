#include "../include/PmergeMe.hpp"
#include <iostream>
#include <cstdlib>
#include <stdexcept>

// ************************************************************************** //
//                       Reverse Polish Notation Class                        //
// ************************************************************************** //

PmergeMe::PmergeMe(void)
{
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
  	*this = copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
	(void)copy;
	return *this;
}

PmergeMe::~PmergeMe(void)
{
}

// ************************************************************************** //
//                         Public Member Functions                            //
// ************************************************************************** //

/**
 * @brief Fill the containers with the arguments
 * 
 * @param argv 
 */
void PmergeMe::fillContainers(char **argv) {
    for (int i = 1; argv[i]; ++i) {
        int num = std::atoi(argv[i]);
        if (num <= 0) {
            throw std::invalid_argument("Error: Only positive integers are allowed.");
        }
        _vector.push_back(num);
        _deque.push_back(num);
    }
}

/**
 * @brief Print the vector
 * 
 */
void PmergeMe::printVector() const {
    std::cout << "Vector content: ";
    for (size_t i = 0; i < _vector.size(); ++i) {
        std::cout << _vector[i] << " ";
    }
    std::cout << std::endl;
}

/**
 * @brief Print the deque
 * 
 */
void PmergeMe::printDeque() const {
    std::cout << "Deque content: ";
    for (size_t i = 0; i < _deque.size(); ++i) {
        std::cout << _deque[i] << " ";
    }
    std::cout << std::endl;
}