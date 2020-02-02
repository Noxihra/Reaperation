/*
** EPITECH PROJECT, 2019
** Macro
** File description:
** Macro of the program
*/

#ifndef MACRO_HPP
#define MACRO_HPP

#include <iostream>

// --------------------------------------------------------- Errors
#define ABORT_CRITICAL_ERROR(message) \
    std::cerr << "[" << __FILE__ << ":" << __LINE__ << "] : " << message << std::endl;\
    std::abort();

#endif // MACRO_HPP
