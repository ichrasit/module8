#include <iostream>
#include <vector>
#include <list>
#include <cstddef>
#include "easyfind.hpp"

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define RED     "\033[31m"
#define CYAN    "\033[36m"
#define MAGENTA "\033[35m"

int main()
{
    std::cout << BOLD << CYAN << "\n=== PART 1: std::vector & Exception Testing ===" << RESET << std::endl;
    
    std::vector<int> v;
    v.push_back(42);
    v.push_back(43);
    v.push_back(44);

    std::vector<int>::iterator it_v = v.begin();
    std::vector<int>::iterator prev_v = it_v;
    
    while (it_v != v.end())
    {
        std::cout << GREEN << "Vector Node -> " << YELLOW << "Val: " << *it_v << MAGENTA << " | Addr: " << &(*it_v);
        if (it_v != v.begin())
        {
            ptrdiff_t diff = (char*)&(*it_v) - (char*)&(*prev_v);
            std::cout << BOLD << CYAN << " | Dist: " << diff << " bytes";
        }
        std::cout << RESET << std::endl;
        prev_v = it_v;
        it_v++;
    }

    try {
        std::cout << "\nLooking for 43 in vector..." << std::endl;
        std::vector<int>::iterator res = easyfind(v, 43);
        std::cout << GREEN << "Success! Found " << *res << " at memory location: " << &(*res) << RESET << std::endl;

        std::cout << "Looking for 99 in vector..." << std::endl;
        easyfind(v, 99);
    } catch (const std::exception& e) {
        std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }

    std::cout << BOLD << CYAN << "\n=== PART 2: std::list & Exception Testing ===" << RESET << std::endl;

    std::list<int> l;
    l.push_back(42);
    l.push_back(43);
    l.push_back(44);

    std::list<int>::iterator it_l = l.begin();
    std::list<int>::iterator prev_l = it_l;

    while (it_l != l.end())
    {
        std::cout << GREEN << "List Node   -> " << YELLOW << "Val: " << *it_l << MAGENTA << " | Addr: " << &(*it_l);
        if (it_l != l.begin())
        {
            ptrdiff_t diff = (char*)&(*it_l) - (char*)&(*prev_l);
            std::cout << BOLD << CYAN << " | Dist: " << diff << " bytes";
        }
        std::cout << RESET << std::endl;
        prev_l = it_l;
        it_l++;
    }

    try {
        std::cout << "\nLooking for 44 in list..." << std::endl;
        std::list<int>::iterator res = easyfind(l, 44);
        std::cout << GREEN << "Success! Found " << *res << " at memory location: " << &(*res) << RESET << std::endl;

        std::cout << "Looking for -5 in list..." << std::endl;
        easyfind(l, -5);
    } catch (const std::exception& e) {
        std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }
    
    std::cout << std::endl;
    return 0;
}