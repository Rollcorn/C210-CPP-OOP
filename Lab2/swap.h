//
// Created by rollcorn on 15.04.2022.
//

#pragma once

#include <algorithm>

template<typename T>
void Swap( T& a_first, T& a_second ) {
    T tmp(std::move(a_first));
    a_first = std::move(a_second);
    a_second = std::move(tmp);
}


