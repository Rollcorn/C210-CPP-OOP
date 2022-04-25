//
// Created by rollcorn on 25.04.2022.
//

#include "Point.h"

// Перегрузка оператора вывода объекта типа Point
std::ostream &operator<<(std::ostream &a_out, const Point &a_pnt){
    a_out << "X: " << a_pnt.m_x << ", Y: " << a_pnt.m_y;
    return a_out;
}
// Перегрузка оператора вывода объекта типа Point
std::ostream &operator<<(std::ostream &a_out, const Point* a_pnt) {
    a_out << "[X: " << a_pnt->getMX() << ", Y: " << a_pnt->getMY() << "]";
    return a_out;
}

bool Point::operator<(const Point &rhs) const {
    int leftDist = m_y*m_y + m_x*m_x;
    int rightDist = rhs.m_y*rhs.m_y + rhs.m_x*rhs.m_x;
    return leftDist < rightDist;
}

bool Point::operator==(const Point &rhs) const {
    return m_x == rhs.m_x && m_y == rhs.m_y;
}

bool Point::operator!=(const Point &rhs) const {
    return !(rhs == *this);
}
