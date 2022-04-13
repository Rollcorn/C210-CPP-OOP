//
// Created by rollcorn on 01.04.2022.
//

#include "Circle.h"

Circle::Circle( Shape::colors color, int a_xAxis, int a_yAxis, int a_radius) : Shape(color), m_xAxis(a_xAxis),
                m_yAxis(a_yAxis), m_radius(a_radius) {
}

Shape *Circle::Clone() const {
    return new Circle( static_cast<const Circle&>(*this) );
}

bool Circle::setRadius(int a_radius) {
    m_radius = a_radius;
    return true;
}

int Circle::AreaCalc() const {

    return 2 * s_pi * m_radius * m_radius;
}

bool Circle::operator==(const Shape &rhs) const {
    try {
        const Circle& mRec = dynamic_cast<const Circle&>(rhs);

        return  this->m_xAxis == mRec.m_xAxis && this->m_yAxis == mRec.m_yAxis &&
                this->m_radius == mRec.m_radius && Shape::operator==(rhs);
    }
    catch(std::bad_cast) {
        return false;
    }
}

bool Circle::operator!=(const Shape &rhs) const {
    return Shape::operator!=(rhs);
}

void Circle::print(std::ostream &out) const {
    Shape::print(out);
    out << " R:" << m_radius << " X:" << m_xAxis << "   Y:" << m_yAxis;
}

std::ostream &operator<<(std::ostream &os, const Circle &circle) {
    circle.print(os);
    return os;
}
