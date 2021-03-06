#pragma once

#include <ostream>
#include "Shape.h"

class Circle : public Shape {
private:
    int m_xAxis;
    int m_yAxis;
    int m_radius;
    constexpr static const double s_pi = 3.14159265359;
public:
    Circle( Shape::colors color, int a_xAxis, int a_yAxis, int a_radius);

    Shape *Clone() const override;

    bool operator!=(const Shape &rhs) const override;

    void print(std::ostream &out) const override;

    // Расчет площади фигуры
    int AreaCalc() const override;

    // Изменить радиус
    bool setRadius(int a_radius);

    bool operator==(const Shape &rhs) const override;

};

std::ostream &operator<<(std::ostream &os, const Circle &circle);


