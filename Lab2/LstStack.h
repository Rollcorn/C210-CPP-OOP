//
// Created by rollcorn on 15.04.2022.
//

#define once


template<typename T>
class LstStack {

private:
    // Вспомогательный класс звена списка
    class ListNode {
    public:
        T m_val;
        ListNode* m_next = nullptr;
        ListNode() = default;
        ListNode( ListNode& a_after, const T& a_el) : m_val(a_el) {
            m_next = a_after.m_next;
            a_after.m_next = this;
        }
    };

    // Конец стека
    ListNode m_head;

public:
    // Стнадартный конструктор
    LstStack() {
        m_head.m_next = nullptr;
    }

    friend std::ostream &operator<<(std::ostream &a_out, const LstStack<T> &a_lst);

        // Конструктор копирования
    LstStack( const LstStack<T>& a_other ){
        ListNode* curNode = a_other.m_head.m_next;
        while ( curNode != nullptr ) {
            new ListNode( m_head, curNode->m_val );
        }
    }

    // Перемещающий конструктор
    LstStack( LstStack<T>&& a_other) {
        this->m_head.m_next = a_other.m_head.m_next;
        a_other.m_head.m_next = nullptr;
    }

    // Вставка элемента в конец стека
    void push(const T& a_elem) {
        new ListNode(m_head, a_elem);
    }

    // Вернуть последний элемент из стека
    T pop() {
        if (m_head.m_next != nullptr ) {
            ListNode* tmp = m_head.m_next;
            m_head.m_next = m_head.m_next->m_next;
            T val = std::move(tmp->m_val);
            delete tmp;
            return val;
        } else {
            throw "Stack is empty";
        }
    }

    void print(std::ostream &a_out, const LstStack<T> &a_lst) const{
        ListNode* curNode = a_lst.m_head.pNext;
        while ( curNode != nullptr ) {
            a_out << "[" << *curNode->m_val << "] " ;
            curNode = curNode->pNext;
        }
    }


};

std::ostream &operator<<(std::ostream &a_out, const LstStack<T> &a_lst) {
    return <#initializer#>;
}