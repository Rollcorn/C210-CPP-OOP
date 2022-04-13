//
// Created by rollcorn on 01.04.2022.
//
#pragma once

#include <cstddef>

#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "typeinfo"

class Node;

class List {

public:
    // Стандартный конструктор
    List();

    // Конcтруктор копирования
    List( const List &a_list );

    // Перемещающий конcтруктор
    List( List &&a_list );

    // Вставка элемента в начало списка
    void addToBegin(const Shape& a_shape);

    // Вставка элемента в конец списка
    void addToEnd(const Shape& a_shape);

    // Удаление из списка всех элементов по ключу
    int removeAll(const Shape& a_shape);

    // Копирующий оператор присванивания
    List& operator=(const List& a_other);

    // Перемещающий оператор присваивания
    List& operator=(const List&& a_other);

    // Оператор вывода
    friend std::ostream& operator<<( std::ostream &out, const List& i );

    // Получить размер списка
    size_t getMSize() const;

    // Сортировака списка
    List& sort( bool (*)( Node, Node ) );


private:
    class Node {
    public:
        Node*   pPrevious = nullptr;
        Node*   pNext = nullptr;
        Shape*  pShape = nullptr;

        friend std::ostream& operator<<( std::ostream &out, const List& i );

        Node() = default;
        Node( Node* a_prevNode, const Shape& a_shape );
        ~Node();
    };



    Node  m_head;
    Node    m_tail;
    size_t  m_size;

};

std::ostream& operator<<( std::ostream &out, const List& i );
