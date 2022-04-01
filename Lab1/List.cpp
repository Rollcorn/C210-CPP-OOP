//
// Created by rollcorn on 01.04.2022.
//

#include "List.h"
#include "Circle.h"

List::List() : m_size(0) {
    m_head.pNext = &m_tail;
    m_tail.pPrevious = &m_head;
}


void List::addToBegin(const Shape& shape){
    new Node( &m_head, shape );
    ++m_size;
}

void List::addToEnd(const Shape &a_shape) {
    new Node( (m_tail.pPrevious), a_shape );
    ++m_size;

}

int List::removeAll(const Shape &shape) {
    Node* currentNode = m_head.pNext;
    int removeCount = 0;

    while ( currentNode != &m_tail ){
        if( currentNode->pShape == &shape ) {
            Node* tempNode = currentNode->pNext;
            currentNode->pNext->pPrevious = currentNode->pPrevious;
            currentNode->pPrevious->pNext = currentNode->pNext;
        } else {
            currentNode = currentNode->pNext;
        }
    }
}


List::Node::Node( Node* a_prevNode, const Shape& a_shape ){
    pShape = a_shape.Clone();
}

List::Node::Node() {

}

List::Node::~Node() {

}


bool List::addToEnd(const Shape& shape);

bool List::removeAll(const Shape& shape);