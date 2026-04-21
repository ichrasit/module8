#include <iostream>
#include <list>
#include <string>
#include "MutantStack.hpp"

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define CYAN    "\033[36m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define MAGENTA "\033[35m"
#define BLUE    "\033[34m"

int main()
{
    std::cout << BOLD << CYAN << "\n[ Phase 1: PDF SUBJECT TEST - MUTANTSTACK ]" << RESET << std::endl;
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    
    std::cout << GREEN << "Top element: " << RESET << mstack.top() << std::endl;
    mstack.pop();
    std::cout << GREEN << "Size after pop: " << RESET << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    
    std::stack<int> s(mstack);

    std::cout << BOLD << CYAN << "\n[ Phase 2: PDF SUBJECT TEST - STD::LIST ]" << RESET << std::endl;
    std::list<int> mlist;
    
    mlist.push_back(5);
    mlist.push_back(17);
    
    std::cout << GREEN << "Top element: " << RESET << mlist.back() << std::endl;
    mlist.pop_back();
    std::cout << GREEN << "Size after pop: " << RESET << mlist.size() << std::endl;
    
    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    mlist.push_back(0);

    std::list<int>::iterator itList = mlist.begin();
    std::list<int>::iterator iteList = mlist.end();

    ++itList;
    --itList;
    
    while (itList != iteList)
    {
        std::cout << *itList << std::endl;
        ++itList;
    }

    std::cout << BOLD << MAGENTA << "\n[ Phase 3: ADVANCED TEST - REVERSE ITERATOR ]" << RESET << std::endl;
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    
    while (rit != rite)
    {
        std::cout << *rit << std::endl;
        ++rit;
    }

    std::cout << BOLD << BLUE << "\n[ Phase 4: ADVANCED TEST - TEMPLATE FLEXIBILITY ]" << RESET << std::endl;
    MutantStack<std::string> strStack;
    
    strStack.push("Kocaeli");
    strStack.push("42");
    strStack.push("Network");
    strStack.push("System");

    MutantStack<std::string>::iterator strIt = strStack.begin();
    MutantStack<std::string>::iterator strIte = strStack.end();
    
    while (strIt != strIte)
    {
        std::cout << *strIt << std::endl;
        ++strIt;
    }

    std::cout << std::endl;
    return 0;
}