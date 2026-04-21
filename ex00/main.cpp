#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int main()
{
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    try{
        std::cout << "Vector içinde 20 araniyor..." << std::endl;
        std::vector<int>::iterator it = easyfind(v, 20);
        std::cout << "Bulundu: " << *it << std::endl;

        std::cout << "Vector içinde 50 araniyor..." << std::endl;
        easyfind(v, 50);
    }catch(const std::exception &e){
        std::cerr << "Hata: " << e.what() << std::endl;
    }

    std::cout << "-----------------" << std::endl;

    std::list<int> l;
    l.push_back(1);
    l.push_back(2);

    try{
        std::cout << "List icinde 1 araniyor..." << std::endl;
        std::list<int>::iterator itL = easyfind(l, 1);
        std::cout << "Bulundu: " << *itL << std::endl;

        std::cout << "list icinde 100 araniyor..." << std::endl;
        easyfind(l, 100);
        
    }catch(const std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    return 0;
}