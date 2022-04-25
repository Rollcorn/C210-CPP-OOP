#pragma once

#include <ostream>
#include "Shape.h"
#include "math.h"


class Rectangle : public Shape
{
private:
    int m_xTopLeft;
    int m_yTopLeft;
    int m_xBotRight;
    int m_yBotRight;
public:

    double dist() const;

    int getMXTopLeft() const;

    void setMXTopLeft(int mXTopLeft);

    int getMYTopLeft() const;

    void setMYTopLeft(int mYTopLeft);

    bool operator!=(const Shape &rhs) const override;

    Rectangle( ) : Shape(), m_xTopLeft(0), m_yTopLeft(0),
                   m_xBotRight(0), m_yBotRight(0){}

    Rectangle( int a_xTopLeft, int a_yTopLeft ) : Shape(), m_xTopLeft(a_xTopLeft), m_yTopLeft(a_yTopLeft),
                   m_xBotRight(0), m_yBotRight(0){}

    Rectangle(colors color, int a_xTopLeft, int a_yTopLeft,
              int a_xBotRight, int  a_yBotRight ) : Shape(color), m_xTopLeft(a_xTopLeft), m_yTopLeft(a_yTopLeft),
                                                    m_xBotRight(a_xBotRight), m_yBotRight(a_yBotRight) {
    }

    Shape * Clone() const override;

    virtual void print(std::ostream &out) const override;

    int AreaCalc() const override;

    virtual bool operator==( const Shape &rhs) const;

    virtual Shape& operator=(const Shape& a_other);

};

std::ostream &operator<<(std::ostream &os, const Rectangle &rectangle);


