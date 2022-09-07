#include "map.hpp"
#include "stack.hpp"
#include "vector.hpp"

#include <iostream>
#include <string>
#include <deque>
#include <map>
#include <stack>
#include <vector>

# define NOC      	"\033[0m"
# define BLACK  	"\033[30m"
# define RED    	"\033[31m"
# define GREEN  	"\033[32m"
# define YELLOW 	"\033[33m"
# define BLUE   	"\033[1m\033[34m"
# define WHITE  	"\033[37m"

void printStackInt(ft::stack<int> stack)
{
	if (stack.empty())
		return ;

	int x = stack.top(); 
	stack.pop();
	printStackInt(stack);
	std::cout << x << std::endl;
 
	stack.push(x);
}

void	printVector(ft::vector<int> vec)
{
    ft::vector<int>::iterator begin;
    ft::vector<int>::iterator end;

    begin = vec.begin();
    end = vec.end();

    while (begin != end)
	{
		std::cout << *begin << std::endl;
		begin++;
	}
}

void	printVectorstd(std::vector<int> vec)
{
    std::vector<int>::iterator begin;
    std::vector<int>::iterator end;

    begin = vec.begin();
    end = vec.end();

    while (begin != end)
	{
		std::cout << *begin << std::endl;
		begin++;
	}
}

int main()
{
    std::cout << BLUE << std::endl << "-----------------------------------------------------------------" << NOC;
    std::cout << BLUE << std::endl << "------------------------- TESTS  STACK --------------------------" << NOC;
    std::cout << BLUE << std::endl << "-----------------------------------------------------------------" << NOC << std::endl << std::endl;

	std::cout << YELLOW << "default constructor" << NOC << std::endl;
	ft::stack<int> stk1;
    std::stack<int> std1;
	std::cout << "ft size(): " << stk1.size() << std::endl;
    std::cout << "std size(): " << std1.size() << std::endl;
    std::cout << std::endl;

    std::cout << YELLOW << "empty()" << NOC << std::endl;
    std::cout << "ft empty(): " << stk1.empty() << std::endl;
    std::cout << "ft size(): " << stk1.size() << std::endl;
    std::cout << "std empty(): " << std1.empty() << std::endl;
    std::cout << "std size(): " << std1.size() << std::endl;
    std::cout << std::endl;

    std::cout << YELLOW << "push()" << NOC << std::endl;
    stk1.push(42);
    std1.push(42);
    std::cout << "ft empty(): " << stk1.empty() << std::endl;
    std::cout << "ft size(): " << stk1.size() << std::endl;
    std::cout << "std empty(): " << std1.empty() << std::endl;
    std::cout << "std size(): " << std1.size() << std::endl;
    std::cout << std::endl;

    std::cout << YELLOW << "operator==" << NOC << std::endl;
	ft::stack<int> stk2;
    std::stack<int> std2;
    std::cout << "(ft1 == ft2): " << (stk1 == stk2) << std::endl;
    std::cout << "(std1 == std2): " << (std1 == std2) << std::endl;
    std::cout << std::endl;

    std::cout << YELLOW << "operator>" << NOC << std::endl;
	std::cout << "(ft1 > ft2): " << (stk1 > stk2) << std::endl;
	std::cout << "(stk1 > stk2): " << (std1 > std2) << std::endl;
    std::cout << std::endl;

    std::cout << BLUE << std::endl << "-----------------------------------------------------------------" << NOC;
    std::cout << BLUE << std::endl << "------------------------- TESTS  VECTOR -------------------------" << NOC;
    std::cout << BLUE << std::endl << "-----------------------------------------------------------------" << NOC << std::endl << std::endl;

    std::cout << YELLOW << "fill && delault constructor" << NOC << std::endl;
    std::cout << "ft::vector<int> ftvec1;" << std::endl;
    ft::vector<int> ftvec1;
    std::cout << "std::vector<int> stdvec1;" << std::endl;
    std::vector<int> stdvec1;
    std::cout << "ft::vector<int> ftvec2(3, 42);" << std::endl;
    ft::vector<int> ftvec2(3, 42);
    std::cout << "std::vector<int> stdvec2(3, 42);" << std::endl;
    std::vector<int> stdvec2(3, 42);
    std::cout << std::endl;

    std::cout << YELLOW << "pop_back(): " << NOC << std::endl;
    ftvec2.pop_back();
	std::cout << "ftvec2.pop_back(): " << std::endl;
    printVector(ftvec2);
    stdvec2.pop_back();
	std::cout << "stdvec2.pop_back(): " << std::endl;
    printVectorstd(stdvec2);
    std::cout << std::endl;

    std::cout << YELLOW << "erase()" << NOC << std::endl;
	std::cout << "ftvec2.erase(ftvec2.begin());" << std::endl;
	ftvec2.erase(ftvec2.begin());
    printVector(ftvec2);
    std::cout << "stdvec2.erase(stdvec2.begin());" << std::endl;
	stdvec2.erase(stdvec2.begin());
    printVectorstd(stdvec2);
    std::cout << std::endl;

}
