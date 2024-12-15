#ifndef __PMERGEME_HPP__
#define __PMERGEME_HPP__

#include <stack>
#include <map>
#include <fstream>
#include <vector>
#include <deque>

class PmergeMe
{
public:
	PmergeMe(void);
	PmergeMe(const PmergeMe &copy);
	PmergeMe &operator=(const PmergeMe &copy);
	~PmergeMe(void);

    void fillContainers(char **argv);
    void printVector() const;
    void printDeque() const;
    void sortVector();
    void sortDeque();

private:
    std::vector<int> _vector;
    std::deque<int> _deque;
};

#endif