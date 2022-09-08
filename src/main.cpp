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

void	printmap(ft::map<int, std::string> map)
{
    ft::map<int, std::string>::iterator begin;
    ft::map<int, std::string>::iterator end;

    begin = map.begin();
    end = map.end();

    while (begin != end)
	{
		std::cout << begin->first << " : " << begin->second << std::endl;
		begin++;
	}
}

void	printmapstd(std::map<int, std::string> map)
{
    std::map<int, std::string>::iterator begin;
    std::map<int, std::string>::iterator end;

    begin = map.begin();
    end = map.end();

    while (begin != end)
	{
		std::cout << begin->first << " : " << begin->second << std::endl;
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

    std::cout << YELLOW << "clear()" << NOC << std::endl;
	std::cout << "ftvec2.clear();" << std::endl;
	ftvec2.clear();
    printVector(ftvec2);
	std::cout << "stdvec2.clear();" << std::endl;
	stdvec2.clear();
    printVectorstd(stdvec2);
    std::cout << std::endl;

    std::cout << YELLOW << "empty()" << NOC << std::endl;
	std::cout << "ftvec2.empty() : " << ftvec2.empty() << std::endl;
	std::cout << "stdvec2.empty() : " << stdvec2.empty() << std::endl;
    std::cout << std::endl;

    std::cout << YELLOW << "insert() fill" << NOC << std::endl;
	std::cout << "ftvec2.insert(ftvec2.begin(), 2, 8);" << std::endl;
	ftvec2.insert(ftvec2.begin(), 2, 8);
    printVector(ftvec2);
    std::cout << "stdvec2.insert(stdvec2.begin(), 2, 8);" << std::endl;
	stdvec2.insert(stdvec2.begin(), 2, 8);
    printVectorstd(stdvec2);
    std::cout << std::endl;

    std::cout << YELLOW << "insert() single" << NOC << std::endl;
	std::cout << "ftvec2.insert(ftvec2.begin(), 42);" << std::endl;
	ftvec2.insert(ftvec2.begin(), 42);
    printVector(ftvec2);
    std::cout << "stdvec2.insert(stdvec2.begin(), 42);" << std::endl;
	stdvec2.insert(stdvec2.begin(), 42);
    printVectorstd(stdvec2);
    std::cout << std::endl;

    std::cout << YELLOW << "operator[]" << NOC << std::endl;
	std::cout << "ftvec2[3]: " << ftvec2[2] << std::endl;
	std::cout << "stdvec2[3]: " << stdvec2[2] << std::endl;
    std::cout << std::endl;

    std::cout << YELLOW << "front()" << NOC << std::endl;
    std::cout << "ftvec2.front(): " << ftvec2.front() << std::endl;
    std::cout << "stdvec2.front(): " << stdvec2.front() << std::endl;
    std::cout << std::endl;

    std::cout << YELLOW << "operator>" << NOC << std::endl;
	std::cout << "(ftvec1 > ftvec2): " << (ftvec1 > ftvec2) << std::endl;
	std::cout << "(stdvec1 > stdvec2): " << (stdvec1 > stdvec2) << std::endl;
    std::cout << std::endl;


    std::cout << BLUE << std::endl << "-----------------------------------------------------------------" << NOC;
    std::cout << BLUE << std::endl << "------------------------- TESTS  MAP ----------------------------" << NOC;
    std::cout << BLUE << std::endl << "-----------------------------------------------------------------" << NOC << std::endl << std::endl;

    std::cout << YELLOW << "default constructor" << NOC << std::endl;
    std::cout << "ft::map<int, std::string> ftmap1;" << std::endl;
    ft::map<int, std::string> ftmap1;
    printmap(ftmap1);
    std::cout << "std::map<int, std::string> stdmap1;" << std::endl;
    std::map<int, std::string> stdmap1;
    printmapstd(stdmap1);
    std::cout << std::endl;

    std::cout << YELLOW << "insert() // single element" << NOC << std::endl;
    std::cout << "ft::pair<int, std::string> pair_one = ft::make_pair(65, \"A\");" << std::endl;
    std::cout << "ft::pair<int, std::string> pair_two = ft::make_pair(66, \"B\");" << std::endl;
    std::cout << "ft::pair<int, std::string> pair_three = ft::make_pair(67, \"C\");" << std::endl;
    ft::pair<int, std::string> pair_one = ft::make_pair(65, "A");
    ft::pair<int, std::string> pair_two = ft::make_pair(66, "B");
    ft::pair<int, std::string> pair_three = ft::make_pair(67, "C");
    std::cout << "ftmap1.insert(pair_one);"	<< std::endl;
	std::cout << "ftmap1.insert(pair_two);"	<< std::endl;
	std::cout << "ftmap1.insert(pair_three);"	<< std::endl;
    ftmap1.insert(pair_one);
    ftmap1.insert(pair_two);
    ftmap1.insert(pair_three);
    printmap(ftmap1);
    std::cout << "std::pair<int, std::string> stdpair_one = std::make_pair(65, \"A\");" << std::endl;
    std::cout << "std::pair<int, std::string> stdpair_two = std::make_pair(66, \"B\");" << std::endl;
    std::cout << "std::pair<int, std::string> stdpair_three = std::make_pair(67, \"C\");" << std::endl;
    std::pair<int, std::string> stdpair_one = std::make_pair(65, "A");
    std::pair<int, std::string> stdpair_two = std::make_pair(66, "B");
    std::pair<int, std::string> stdpair_three = std::make_pair(67, "C");
    std::cout << "stdmap1.insert(stdpair_one);"	<< std::endl;
	std::cout << "stdmap1.insert(stdpair_two);"	<< std::endl;
	std::cout << "stdmap1.insert(stdpair_three);"	<< std::endl;
    stdmap1.insert(stdpair_one);
    stdmap1.insert(stdpair_two);
    stdmap1.insert(stdpair_three);
    printmapstd(stdmap1);
    std::cout << std::endl;

    std::cout << YELLOW << "swap()" << NOC << std::endl;
	std::cout << "ftmap2.swap(ftmap1);" << std::endl;
    ft::map<int, std::string> ftmap2;
	ftmap2.swap(ftmap1);
    printmap(ftmap2);
    std::cout << "stdmap2.swap(stdmap1);" << std::endl;
    std::map<int, std::string> stdmap2;
	stdmap2.swap(stdmap1);
    printmapstd(stdmap2);
    std::cout << std::endl;

    std::cout << YELLOW << "rbegin()" << NOC << std::endl;
    std::cout << "ftmap2.rbegin()->first : " << ftmap2.rbegin()->first << std::endl;
    std::cout << "stdmap2.rbegin()->first : " << stdmap2.rbegin()->first << std::endl;
    std::cout << std::endl;

    std::cout << YELLOW << "find()" << NOC << std::endl;
    std::cout << "ftmap2.find(66)->second: " << ftmap2.find(66)->second << std::endl;
    std::cout << "stdmap2.find(66)->second: " << stdmap2.find(66)->second << std::endl;
    std::cout << std::endl;

    std::cout << YELLOW << "lower_bound()" << NOC << std::endl;
	std::cout << "ftmap2.lower_bound(66)->second: " << ftmap2.lower_bound(66)->second << std::endl;
	std::cout << "stdmap2.lower_bound(66)->second: " << stdmap2.lower_bound(66)->second << std::endl;
    std::cout << std::endl;

    std::cout << YELLOW << "upper_bound()" << NOC << std::endl;
	std::cout << "ftmap2.upper_bound(66)->second: " << ftmap2.upper_bound(66)->second << std::endl;
	std::cout << "stdmap2.upper_bound(66)->second: " << stdmap2.upper_bound(66)->second << std::endl;
    std::cout << std::endl;
}
