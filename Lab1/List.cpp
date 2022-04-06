//
// Created by rollcorn on 01.04.2022.
//

#include "List.h"

List::List() : m_size(0) {
    m_head.pNext = &m_tail;
    m_tail.pPrevious = &m_head;
}


void List::addToBegin(const Shape& a_shape){
    new Node(&(m_head), a_shape );
    ++m_size;
}


void List::addToEnd(const Shape &a_shape) {
    new Node( (m_tail.pPrevious), a_shape );
    ++m_size;
}


int List::removeAll(const Shape &a_shape) {
    Node* currentNode = m_head.pNext;
    int removeCount = 0;

    while ( currentNode != &m_tail ){
        if( currentNode->pShape == &a_shape ) {
            Node* tempNode = currentNode->pNext;
            currentNode->pNext->pPrevious = currentNode->pPrevious;
            currentNode->pPrevious->pNext = currentNode->pNext;
            ++removeCount;
        } else {
            currentNode = currentNode->pNext;
        }
    }
    return removeCount;
}

List::List(const List &a_list) {


}


List::Node::Node( Node* a_prevNode, const Shape& a_shape ){
    pShape = a_shape.Clone();
}

List::Node::Node() {

}

List::Node::~Node() {

}
