#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <cstddef>   

template <typename T>
class Array {
public:
    Array();                         
    explicit Array(unsigned int n);  
    Array(const Array& other);       
    Array& operator=(const Array&);  
    ~Array();                        

    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;

    unsigned int size() const;

private:
    T*            _data;
    unsigned int  _size;
};

#include "Array.tpp"

#endif
