/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 16:07:33 by didimitr          #+#    #+#             */
/*   Updated: 2026/04/20 16:31:01 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Array.hpp"

static void printHeader(const std::string& title)
{
    std::cout << "\n--- " << title << " ---" << std::endl;
}

int main()
{
    int *a = new int();
    std::cout << a << std::endl;
    printHeader("Default constructor");
    Array<int> empty;
    std::cout << "Empty array created." << std::endl;

    printHeader("Constructor with size + indexing");
    Array<int> numbers(5);
    for (size_t i = 0; i < 5; i++)
        numbers[i] = static_cast<int>(i * 10);

    for (size_t i = 0; i < 5; i++)
        std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;

    printHeader("Copy constructor");
    Array<int> copy(numbers);

    std::cout << "Original before change: " << numbers[0] << std::endl;
    std::cout << "Copy before change:     " << copy[0] << std::endl;

    numbers[0] = 999;

    std::cout << "Original after change:  " << numbers[0] << std::endl;
    std::cout << "Copy after change:      " << copy[0] << std::endl;

    if (copy[0] == 999)
        std::cout << "ERROR: shallow copy in copy constructor" << std::endl;
    else
        std::cout << "OK: deep copy in copy constructor" << std::endl;

    printHeader("Assignment operator");
    Array<int> assigned(3);
    assigned[0] = 1;
    assigned[1] = 2;
    assigned[2] = 3;

    assigned = numbers;

    std::cout << "Assigned after operator= :" << std::endl;
    for (size_t i = 0; i < 5; i++)
        std::cout << "assigned[" << i << "] = " << assigned[i] << std::endl;

    numbers[1] = 555;

    std::cout << "numbers[1] after change  = " << numbers[1] << std::endl;
    std::cout << "assigned[1] after change = " << assigned[1] << std::endl;

    if (assigned[1] == 555)
        std::cout << "ERROR: shallow copy in operator=" << std::endl;
    else
        std::cout << "OK: deep copy in operator=" << std::endl;

    printHeader("Self-assignment");
    Array<int>& ref = numbers;
    numbers = ref;
    std::cout << "Self-assignment survived." << std::endl;

    printHeader("Out of bounds");
    try
    {
        std::cout << numbers[100] << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    try
    {
        std::cout << numbers[-1] << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    printHeader("String test");
    Array<std::string> words(3);
    words[0] = "hello";
    words[1] = "template";
    words[2] = "world";

    for (size_t i = 0; i < 3; i++)
        std::cout << "words[" << i << "] = " << words[i] << std::endl;

    printHeader("End");
    return 0;
}




// #include <Array.hpp>

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }