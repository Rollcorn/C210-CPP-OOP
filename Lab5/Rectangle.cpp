// Created by rollcorn on 01.04.2022.
//

#include "Rectangle.h"


int Rectangle::AreaCalc() const {
    return (m_xBotRight - m_xTopLeft) * (m_yTopLeft - m_yBotRight);
}

Shape *Rectangle::Clone() const {
    return new Rectangle( static_cast<const Rectangle&>(*this) );
}

void Rectangle::print(std::ostream &out) const {
   Shape::print(out);
   out << ", [ a:" << (m_xBotRight - m_xTopLeft) << ", b:" << (m_yTopLeft - m_yBotRight) << "]";
}


bool Rectangle::operator==(const Shape &rhs) const {
    if( const Rectangle* mRec = dynamic_cast<const Rectangle*>(&rhs) )
    {
        return this->m_xTopLeft == mRec->m_xTopLeft && this->m_yTopLeft == mRec->m_yTopLeft
               && this->m_xBotRight == mRec->m_xBotRight && this->m_yBotRight == mRec->m_yBotRight
               && Shape::operator==(rhs);
    }
    return false;
}

bool Rectangle::operator!=(const Shape &rhs) const {
    return Shape::operator!=(rhs);
}

Shape& Rectangle::operator=(const Shape &a_other) {
    //Shape::operator=(a_other);
    if( const Rectangle* mRec = dynamic_cast<const Rectangle*>(&a_other) )
    {
        *this = static_cast<const Rectangle&>(a_other);
    }
    return *this;
}

double  Rectangle::dist() const
{
    return sqrt(pow(this->getMXTopLeft(), 2) + pow(this->getMYTopLeft(), 2));
}


int Rectangle::getMXTopLeft() const {
    return m_xTopLeft;
}

void Rectangle::setMXTopLeft(int mXTopLeft) {
    m_xTopLeft = mXTopLeft;
}

int Rectangle::getMYTopLeft() const {
    return m_yTopLeft;
}

void Rectangle::setMYTopLeft(int mYTopLeft) {
    m_yTopLeft = mYTopLeft;
}

std::ostream &operator<<(std::ostream &os, const Rectangle &rectangle) {
    rectangle.print(os);
    return os;
}

