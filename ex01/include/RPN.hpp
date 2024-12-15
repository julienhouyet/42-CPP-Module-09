#ifndef __RPN_HPP__
#define __RPN_HPP__

#include <stack>
#include <map>
#include <fstream>

class RPN
{
public:
	RPN(void);
	RPN(const RPN &copy);
	RPN &operator=(const RPN &copy);
	~RPN(void);

	void calculate(const std::string &expression);
};

#endif