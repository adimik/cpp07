/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 16:08:34 by didimitr          #+#    #+#             */
/*   Updated: 2026/03/16 19:12:50 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstdlib>
#include <iostream>
#include <exception>

template <typename T>

class Array{
    private:
        size_t arrSize;
        T* data;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& other); 
        Array& operator=(const Array& other);
        T& operator[](size_t index);
        const T& operator[](size_t index) const;
        ~Array();
        size_t size() const;
};

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    if(this == &other)
        return(*this);
    this->arrSize = other.arrSize;
    delete[] this->data;
    this->data = new T[this->arrSize];
    for (size_t i = 0; i < this->arrSize; i++)
    {
        this->data[i] = other.data[i];
    }
    return(*this);
}

template <typename T>
Array<T>::Array(const Array<T>& other){
    this->arrSize = other.arrSize;
    this->data = new T[this->arrSize];
    size_t i = 0;
    while (i < this->arrSize)
    {
        this->data[i] = other.data[i];
        i++;
    }
    
}

template <typename T>
Array<T>::Array() {
    this->data = NULL;
    this->arrSize = 0;
}

template <typename T>
Array<T>::Array(unsigned int n){
    this->arrSize = n;
    this->data = new T[n];
}

template <typename T>
Array<T>::~Array() {
    delete[] data;
}

template <typename T>
T& Array<T>::operator[](const size_t index){
    if(index >= this->arrSize)
        throw(std::out_of_range("Index out of range."));
    return(this->data[index]);
}

template <typename T>
const T& Array<T>::operator[](size_t index) const{
    if(index >= this->arrSize)
        throw(std::out_of_range("Index out of range."));
    return(this->data[index]);
}

template <typename T>
size_t Array<T>::size() const{
    return(this->arrSize);
}