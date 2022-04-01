//
// Created by rollcorn on 01.04.2022.
//

#pragma once

#include "Circle.h"

Circle::Circle(int a_xAxis, int a_yAxis, int a_radius) {

}

Shape *Circle::Clone() const {
    return new Circle( static_cast<const Circle&>(this) );
}

bool Circle::setRadius(int a_radius) {
    return false;
}

bool Circle::Draw() const {
    return false;
}

int Circle::AreaCulc() const {
    return 0;
}

bool Circle::operator==(const Shape &rhs) const {
    try {
        const Circle& mRec = dynamic_cast<const Circle&>(rhs);

        return  this->xAxis == mRec.xAxis && this->yAxis == mRec.yAxis &&
                this->m_radius == mRec.m_radius && Shape::operator==(rhs);
    }
    catch(std::bad_cast) {
        return false;
    }
}
