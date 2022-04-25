//
// Created by rollcorn on 25.04.2022.
//

#pragma once

#include <iostream>
using namespace std;


class Point {
private:
    int m_x;
    int m_y;
public:
    Point() : m_x(0), m_y(0) {}
    Point(int a_x, int a_y):m_x(a_x), m_y(a_y){}
    friend std::ostream &operator<<( std::ostream &a_out, const Point &a_pnt );
    friend std::ostream &operator<<( std::ostream &a_out, const Point* a_pnt );

    void setMX(int mX) {
        m_x = mX;
    }

    void setMY(int mY) {
        m_y = mY;
    }

    int getMX() const{ return m_x; }
    int getMY() const{ return m_y; }

    bool operator==(const Point &rhs) const;
    bool operator!=(const Point &rhs) const;
    bool operator<(const Point &rhs) const;
};


