#include "../include/PmergeMe.hpp"

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