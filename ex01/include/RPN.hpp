#ifndef __RPN_HPP__
#define __RPN_HPP__

#include <stack>
#include <map>
#include <fstream>

class RPN
{
private:
	std::stack<int> _stack;
public:
	RPN(void);
	RPN(const RPN &copy);
	RPN &operator=(const RPN &copy);
	~RPN(void);
};

#endif