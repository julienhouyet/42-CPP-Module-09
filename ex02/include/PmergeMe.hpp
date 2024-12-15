#ifndef __PMERGEME_HPP__
#define __PMERGEME_HPP__

#include <stack>
#include <map>
#include <fstream>

class PmergeMe
{
public:
	PmergeMe(void);
	PmergeMe(const PmergeMe &copy);
	PmergeMe &operator=(const PmergeMe &copy);
	~PmergeMe(void);
};

#endif