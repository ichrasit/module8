#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <iterator>

class Span{
    private:
        unsigned int _maxSize;
        std::vector<int> _numbers;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int number);
        int shortestSpan() const;
        int longestSpan() const;

        template <typename Iterator>
        void addNumbers(Iterator begin, Iterator end){
            if(std::distance(begin, end) > _maxSize - _numbers.size())
                throw SpanFullException();
            _numbers.insert(_numbers.end(), begin, end);
        }
        class SpanFullException : public std::exception{
            public:
                virtual const char* what() const throw();
        };
        
        class SpanNoSpanException : public std::exception{
            public:
                virtual const char* what() const throw();
        };
};

#endif