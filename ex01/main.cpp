#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define DIM     "\033[2m"
#define CYAN    "\033[36m"
#define BLUE    "\033[34m"
#define GREY    "\033[90m"
#define RED     "\033[31m"

int main() {
    std::srand(std::time(NULL));

    std::cout << BOLD << CYAN << "\n[ SYSTEM INITIATED: SPAN ANALYSIS ]\n" << RESET << std::endl;

    std::cout << BOLD << GREY << "--- Phase 1: Subject Core Test ---" << RESET << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << BLUE << "> Shortest Span: " << RESET << sp.shortestSpan() << std::endl;
    std::cout << BLUE << "> Longest Span : " << RESET << sp.longestSpan() << std::endl;

    std::cout << BOLD << GREY << "\n--- Phase 2: Exception Protocols ---" << RESET << std::endl;
    Span tinySpan = Span(1);
    tinySpan.addNumber(42);
    
    try {
        std::cout << DIM << "[Attempting to find span with 1 element...]" << RESET << std::endl;
        tinySpan.shortestSpan();
    } catch (std::exception &e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }

    try {
        std::cout << DIM << "[Attempting to breach capacity limit...]" << RESET << std::endl;
        tinySpan.addNumber(43);
    } catch (std::exception &e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }

    std::cout << BOLD << GREY << "\n--- Phase 3: High-Fidelity Stress Test (15,000 Elements) ---" << RESET << std::endl;
    
    Span megaSpan(15000);
    std::vector<int> heavyData;
    
    for (int i = 0; i < 15000; i++) {
        heavyData.push_back(std::rand());
    }

    std::cout << DIM << "[Injecting data via iterator range...]" << RESET << std::endl;
    
    try {
        megaSpan.addNumbers(heavyData.begin(), heavyData.end());
        std::cout << CYAN << "Data injection successful." << RESET << std::endl;

        std::cout << BLUE << "> Shortest Span: " << RESET << megaSpan.shortestSpan() << std::endl;
        std::cout << BLUE << "> Longest Span : " << RESET << megaSpan.longestSpan() << std::endl;
        
    } catch (std::exception &e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }

    std::cout << BOLD << CYAN << "\n[ SYSTEM TERMINATED ]\n" << RESET << std::endl;

    return 0;
}