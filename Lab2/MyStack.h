//
// Created by rollcorn on 15.04.2022.
//

#pragma once

#include <cstddef>
#include <iostream>

template<typename T, size_t N>
class MyStack {
    size_t m_size = 0;
    T m_arr[N];

public:
    void push(T a_elem) {
        try {
            if (m_size == N) {
                throw "MyStack is Out Of Space!";
            }
            m_arr[m_size] = a_elem;
            m_size++;
        } catch (const char* msg){
            std::cout << msg << std::endl;
        }
    }

    T pop() {
        try {
            if ( m_size < 1 ) {
                throw "MyStack is empty";
            }
            --m_size;
            return m_arr[m_size];

        } catch (const char* msg){
            std::cout << msg << std::endl;
        }
    }

    const T& operator[]( int a_index ) const {
        try {
            if ( a_index >= m_size || a_index < 0 ) {
                throw "Out of range for Index: ";
            }
            return m_arr[a_index];

        } catch (const char* msg){
            std::cout << msg << a_index << std::endl;
        }
    }

     T& operator[]( int a_index )  {
        try {
            if ( a_index >= m_size || a_index < 0 ) {
                throw "Out of range for Index: ";
            }
            return m_arr[a_index];

        } catch (const char* msg){
            std::cout << msg << a_index << std::endl;
        }
    }
};

