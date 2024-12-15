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

/**
 * @brief Sort the vector
 * 
 */
void PmergeMe::sortVector() {
    if (_vector.size() <= 1)
    {
        return;
    }

    std::vector<int> left(_vector.begin(), _vector.begin() + _vector.size() / 2);
    std::vector<int> right(_vector.begin() + _vector.size() / 2, _vector.end());

    PmergeMe leftSorter, rightSorter;
    leftSorter._vector = left;
    rightSorter._vector = right;

    leftSorter.sortVector();
    rightSorter.sortVector();

    _vector.clear();
    size_t i = 0, j = 0;
    while (i < leftSorter._vector.size() && j < rightSorter._vector.size())
    {
        if (leftSorter._vector[i] < rightSorter._vector[j])
        {
            _vector.push_back(leftSorter._vector[i++]);
        }
        else
        {
            _vector.push_back(rightSorter._vector[j++]);
        }
    }

    while (i < leftSorter._vector.size())
    {
        _vector.push_back(leftSorter._vector[i++]);
    }
    while (j < rightSorter._vector.size())
    {
        _vector.push_back(rightSorter._vector[j++]);
    }
}

/**
 * @brief Sort the deque
 * 
 */
void PmergeMe::sortDeque() {
    if (_deque.size() <= 1)
    {
        return;
    }

    std::deque<int> left(_deque.begin(), _deque.begin() + _deque.size() / 2);
    std::deque<int> right(_deque.begin() + _deque.size() / 2, _deque.end());

    PmergeMe leftSorter, rightSorter;
    leftSorter._deque = left;
    rightSorter._deque = right;

    leftSorter.sortDeque();
    rightSorter.sortDeque();

    _deque.clear();
    size_t i = 0, j = 0;
    while (i < leftSorter._deque.size() && j < rightSorter._deque.size())
    {
        if (leftSorter._deque[i] < rightSorter._deque[j])
        {
            _deque.push_back(leftSorter._deque[i++]);
        }
        else
        {
            _deque.push_back(rightSorter._deque[j++]);
        }
    }

    while (i < leftSorter._deque.size())
    {
        _deque.push_back(leftSorter._deque[i++]);
    }
    while (j < rightSorter._deque.size())
    {
        _deque.push_back(rightSorter._deque[j++]);
    }
}