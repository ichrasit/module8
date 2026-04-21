#include "Span.hpp"
#include <limits>

Span::Span() : _maxSize(0){}
Span::Span(unsigned int N) : _maxSize(N){}
Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers) {}
Span& Span::operator=(const Span& other){
    if(this != &other){
        this->_maxSize = other._maxSize;
        this->_numbers = other._numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number){
    if(_numbers.size() >= _maxSize)
        throw SpanFullException();
    _numbers.push_back(number);
}

int Span::shortestSpan() const{
    if(_numbers.size() <= 1)
        throw SpanNoSpanException();
    
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    
    int min_span = std::numeric_limits<int>::max();

    for(size_t i = 1; i < sorted.size(); ++i){
        int span = sorted[i] - sorted[i - 1];
        if(span < min_span)
            min_span = span;
    }
    return min_span;
}

int Span::longestSpan() const{
    if(_numbers.size() <= 1)
        throw SpanNoSpanException();
    
    int max_val = *std::max_element(_numbers.begin(), _numbers.end());
    int min_val = *std::min_element(_numbers.begin(), _numbers.end());
    
    return max_val - min_val;
}

const char* Span::SpanFullException::what() const throw(){
    return "SYSTEM_ERR::CAPACITY_EXCEEDED --> Cannot add more elements.";
}

const char *Span::SpanNoSpanException::what() const throw(){
    return "SYSTEM_ERR::INSUFFICIENT_DATA --> At least 2 elements required.";
}