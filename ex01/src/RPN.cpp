#include "../include/RPN.hpp"
#include <iostream>
#include <sstream>
#include <stack>
#include <cctype>
#include <stdexcept>

// ************************************************************************** //
//                       Reverse Polish Notation Class                        //
// ************************************************************************** //

RPN::RPN(void)
{
}

RPN::RPN(const RPN &copy)
{
  	*this = copy;
}

RPN &RPN::operator=(const RPN &copy)
{
	(void)copy;
	return *this;
}

RPN::~RPN(void)
{
}

// ************************************************************************** //
//                         Public Member Functions                            //
// ************************************************************************** //

void RPN::calculate(const std::string &expression)
{
    std::stack<int> stack;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (isdigit(token[0])) {
            std::stringstream ss(token);
            int number;
            ss >> number;
            stack.push(number);
        } else {
            if (stack.size() < 2) {
                throw std::runtime_error("Invalid expression");
            }
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();

            if (token == "+") {
                stack.push(a + b);
            } else if (token == "-") {
                stack.push(a - b);
            } else if (token == "x" || token == "*") {
                stack.push(a * b);
            } else if (token == "/") {
                if (b == 0) {
                    throw std::runtime_error("Division by zero");
                }
                stack.push(a / b);
            } else {
                throw std::runtime_error("Unknown operator: " + token);
            }
        }
    }

    if (stack.size() != 1) {
        throw std::runtime_error("Invalid expression");
    }

    std::cout << stack.top() << std::endl;
}