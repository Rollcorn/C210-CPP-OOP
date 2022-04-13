//
// Created by rollcorn on 01.04.2022.
//

#include "List.h"

// Стандартный конструктор
List::List() : m_size(0) {
    m_head.pNext = &m_tail;
    m_tail.pPrevious = &m_head;
}

// Копирующий конструктор копирования
List::List( const List &a_list ) {
    m_head.pNext = &m_tail;
    m_tail.pPrevious = &m_head;

    Node* firstCurNode  = &this->m_head;
    Node* otherCurNode  = a_list.m_head.pNext;

    while ( otherCurNode != &a_list.m_tail ) {
        new Node( firstCurNode, *otherCurNode->pShape );
        otherCurNode = otherCurNode->pNext;
        firstCurNode = firstCurNode->pNext;
    }
    m_size = a_list.m_size;
}

// Добавить элемент в начало списка
void List::addToBegin(const Shape& a_shape){
    new Node(&(m_head), a_shape );
    ++m_size;
}

// Добавить элемент в конец списка
void List::addToEnd(const Shape &a_shape) {
    new Node( (m_tail.pPrevious), a_shape );
    ++m_size;
}

// Удалить все элементы заданой фигуры из списка
int List::removeAll(const Shape &a_shape) {
    Node* currentNode = m_head.pNext;
    int removeCount = 0;

    while ( currentNode != &m_tail ){
        Node* tempNode = currentNode->pNext;

        if( *currentNode->pShape == a_shape ) {
            delete currentNode;
            ++removeCount;

        }
            currentNode = tempNode;

    }
    m_size -= removeCount;
    return removeCount;
}

// Копирующий оператор присваивания
List &List::operator=(const List &a_other) {

    Node* firstCurNode  = this->m_head.pNext;
    Node* otherCurNode  = a_other.m_head.pNext;

    while ( firstCurNode != &this->m_tail && otherCurNode != &a_other.m_tail ) {
        // Если фигуры в звеньях одинаковы
        if ( typeid( *firstCurNode->pShape) == typeid( *otherCurNode->pShape ) ) {
            *firstCurNode->pShape = *otherCurNode->pShape;
        } else {
            delete firstCurNode->pShape;
            firstCurNode->pShape = otherCurNode->pShape->Clone();
        }
        firstCurNode = firstCurNode->pNext;
        otherCurNode = otherCurNode->pNext;
    }
    // Если первый список короче или они равны
    for ( int i = a_other.m_size; i < this->m_size; ++i ){
        delete m_tail.pPrevious;
    }

    for ( int i = this->m_size; i < a_other.m_size; ++i ){
        new Node(m_tail.pPrevious, *otherCurNode->pShape);
        otherCurNode = otherCurNode->pNext;
    }

    m_size = a_other.m_size;

    return *this;
}

// TODO Перемещающий оператор присваивания
List &List::operator=(const List &&a_other) {
    this->m_head.pNext = a_other.m_head.pNext;
    this->m_tail.pPrevious = a_other.m_tail.pPrevious;
    this->m_size = a_other.m_size;
    a_other.m_head.pNext = nullptr;
    a_other.m_tail.pPrevious = nullptr;
    a_other.m_size = 0;

//    TODO delete nodes

    return *this;
}

// Оператор вывода списка
std::ostream &operator<<(std::ostream &out, const List &lst) {

    List::Node* curNode = lst.m_head.pNext;

    while ( curNode != &lst.m_tail ) {
        out << " { " << *curNode->pShape << " } ";
        curNode = curNode->pNext;
    }
    return out;
}

// Получить размер списка
size_t List::getMSize() const {
    return m_size;
}

// Перемещающий конструктор
List::List(List &&a_list) {
    this->m_head.pNext = a_list.m_head.pNext;
    this->m_tail.pPrevious = a_list.m_tail.pPrevious;
    this->m_size = a_list.m_size;
    a_list.m_head.pNext = nullptr;
    a_list.m_tail.pPrevious = nullptr;
    a_list.m_size = 0;
}

List &List::sort( bool (*)(Node, Node) ) {

    return <#initializer#>;
}


// Конструктор звена списка
List::Node::Node( Node* a_prevNode, const Shape& a_shape ){
    this->pPrevious = a_prevNode;
    this->pNext = a_prevNode->pNext;
    a_prevNode->pNext = this;
    pNext->pPrevious = this;

    pShape = a_shape.Clone();
}

// Деструктор
List::Node::~Node() {
    if ( this->pPrevious != nullptr ) {
        this->pPrevious->pNext = this->pNext;
    }
    if ( this->pNext != nullptr ) {
        this->pNext->pPrevious = this->pPrevious;
    }
    this->pPrevious = nullptr;
    this->pNext = nullptr;
    delete this->pShape;
}



