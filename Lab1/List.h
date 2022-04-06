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

public:
    List();

    /*
     * Кончтруктор копирования
     */
    List( const List &a_list );

    /*
     * Вставка элемента в начало списка
     */
    void addToBegin(const Shape& a_shape);

    /*
     * Вставка элемента в конец списка
     */
    void addToEnd(const Shape& a_shape);

    /*
    * Удаление из списка всех элементов по ключу
    */
    int removeAll(const Shape& a_shape);

    // Конструктор копирования
    //    Оптимизированный вариант когда сравниваем совпадают ли текущие элементы и если они совпадают

    // Конструктор перемещающий
    //      Оставляем head и tail а весь кусок между ними замеяем другим списком

    // Оператор присваивания: копирующий(глубокий) и перемещающий

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

    Node    m_head;
    Node    m_tail;
    size_t  m_size;

};