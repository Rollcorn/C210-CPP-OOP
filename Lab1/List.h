//
// Created by rollcorn on 01.04.2022.
//

#pragma once

#include <cstddef>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"

#include "typeinfo"

class List {

private:

    class Node {
    public:
        Node* pPrevious = nullptr;
        Node* pNext = nullptr;
        Shape* pShape = nullptr;

        Node();
        ~Node();

        Node( Node* a_prevNode, const Shape& a_shape );
    };

    Node m_head;
    Node m_tail;
    size_t m_size;

public:
    void addToBegin(const Shape& shape);

    void addToEnd(const Shape& shape);

    int removeAll(const Shape& shape);

    // Конструктор копирования
    //    Оптимизированный вариант когда сравниваем совпадают ли текущие элементы и если они совпадают

    // Конструктор перемещающий

    List();
}