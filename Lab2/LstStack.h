//
// Created by rollcorn on 15.04.2022.
//

#pragma once

#include <iostream>

template<typename T>
class LstStack {

private:
    // Вспомогательный класс звена списка
    class ListNode {
    public:
        T m_val;
        ListNode *m_next = nullptr;

        ListNode() = default;

        ListNode(ListNode &a_after, const T &a_el) : m_val(a_el) {
            m_next = a_after.m_next;
            a_after.m_next = this;
        }

        template<T>
        friend std::ostream &operator<<(std::ostream &a_out, const LstStack<T> &a_lst);
    };

    // Распечатать все звенья после данного
    void printNode(std::ostream &a_out, const ListNode &a_node) const {
        ListNode* curNode = a_node.m_next;
        if ( curNode == nullptr) {
            return;
        } else {
            printNode(a_out, *curNode);
            a_out << "[" << curNode->m_val << "] ";
        }
    }

    // Конец стека
    ListNode m_head;

public:
    // Стнадартный конструктор
    LstStack() = default;

    // Конструктор копирования
    LstStack(const LstStack<T> &a_other) {
        ListNode *curNode = a_other.m_head.m_next;
        while (curNode != nullptr) {
            new ListNode(m_head, curNode->m_val);
        }
    }

    // Перемещающий конструктор
    LstStack(LstStack<T> &&a_other) {
        this->m_head.m_next = a_other.m_head.m_next;
        a_other.m_head.m_next = nullptr;
    }

    // Вставка элемента в конец стека
    void push(const T &a_elem) {
        new ListNode(m_head, a_elem);
    }

    // Вернуть последний элемент из стека
    T pop() {
        if (m_head.m_next != nullptr) {
            ListNode *tmp = m_head.m_next;
            m_head.m_next = m_head.m_next->m_next;
            T val = std::move(tmp->m_val);
            delete tmp;
            return val;
        } else {
            throw "Exception: Stack is empty";
        }
    }

    // Сериализация элементов списка в поток
    std::ostream & print(std::ostream &a_out, const LstStack &a_lst) const {
        if (a_lst.m_head.m_next == nullptr) {
            a_out << "EMPTY";
        } else {
            printNode( a_out, a_lst.m_head );
        }
        return a_out;
    }

    template<T>
    friend std::ostream &operator<<(std::ostream &a_out, const LstStack<T> &a_lst);

    // Копирующий оператор присваивания
    LstStack& operator=(const LstStack &a_other) {
        ListNode* firstCurNode  = this->m_head.pNext;
        ListNode* otherCurNode  = a_other.m_head.pNext;
        ListNode* tempNode;

        while ( firstCurNode != nullptr && otherCurNode != nullptr ) {
            firstCurNode->m_val = otherCurNode->m_val;
            tempNode = firstCurNode;
            firstCurNode = firstCurNode->pNext;
            otherCurNode = otherCurNode->pNext;
        }

        // Если первый список короче
        if ( otherCurNode != nullptr ){
            firstCurNode = tempNode;
            while ( otherCurNode != nullptr ) {
                new ListNode(firstCurNode, otherCurNode->m_val);
                firstCurNode = firstCurNode->m_next;
                otherCurNode = otherCurNode->m_next;
            }
//            firstCurNode = firstCurNode->m_next;
        } else
        if ( firstCurNode != nullptr ) {
            tempNode->m_next = nullptr;

            while ( firstCurNode != nullptr ) {
                tempNode = firstCurNode;
                firstCurNode = firstCurNode->m_next;
                delete(tempNode);
            }
        }
        return *this;
    }

    // Перемещающий оператор присваивания
    LstStack& operator=(LstStack&& a_other){
        ListNode* cur = m_head.m_next;
        ListNode tmp;

        while ( cur != nullptr ) {
            ListNode* tmp = cur;
            cur = cur->m_next;
            delete tmp;
        }

        this->m_head.m_next = a_other.m_head.m_next;
        a_other.m_head.m_next = nullptr;
    }

};

template<typename T>
std::ostream &operator<<(std::ostream &a_out, const LstStack<T> &a_lst) {
    return a_lst.print(a_out, a_lst);;
}
/*// Brutforce
LstStack<T> tempStack;
while (curNode != nullptr ){
    tempStack.push(curNode->m_val);
    curNode = curNode->m_next;
}
curNode = tempStack.m_head.m_next;
while (curNode != nullptr) {
    a_out << "[" << curNode->m_val << "] ";
    ListNode* tmp = curNode;
    curNode = curNode->m_next;
    delete tmp;
}
*/