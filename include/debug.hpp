#pragma once

#include <iostream>


template <typename TYPE>
void print(TYPE data) {
    std::cout << "DEBUG: " << data << std::endl;
}

template <typename TYPE>
void print(const char* message, TYPE data) {
    std::cout << "DEBUG: " << message << " " << data << std::endl;
}