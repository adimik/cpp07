/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 13:21:15 by didimitr          #+#    #+#             */
/*   Updated: 2026/03/11 14:38:26 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/iter.hpp"

void removeOne(int &a){
    a--;
}

void lookAtConst(const int &a){
    std::cout << "Im looking at const." << a << std::endl; 
}

void changeLetters(std::string &str)
{
    for (size_t i = 0; i < str.size(); i++)
    {
        str.at(i)--;
    }
}

int main(void){

    std::string arr2[2] = {"bcdef", "23456"};
    int arr[5] = {1, 12, 83, 34, 51};
    const int arr3[5] = {1, 12, 83, 34, 51};
    for (size_t i = 0; i < 5; i++)
    {
        std::cout << arr[i] << std::endl;
    }
    ::iter(arr, 5, removeOne);
    for (size_t i = 0; i < 5; i++)
    {
        std::cout << arr[i] << std::endl;
    }
    ::iter(arr2, 2, changeLetters);
    for (size_t i = 0; i < 2; i++)
    {
        std::cout << arr2[i] << std::endl;
    }
    ::iter(arr3, 5, lookAtConst);
    return(0);
}