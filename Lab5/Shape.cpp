#include "Shape.h"

void Shape::SetColor(colors newColor) {
    color = newColor;
}

std::string Shape::getColor() const {
    return colorStrArr[color];
}

bool Shape::operator==( const Shape &rhs) const{
    return color == rhs.color;
}

bool Shape::operator!=( const Shape &rhs) const{
    return color != rhs.color;
}

void Shape::print(std::ostream &out) const {
    out << getColor();
}

Shape &Shape::operator=(const Shape &a_other) {
    this->color = a_other.color;
    return *this;
}

Shape::~Shape() {

}

std::ostream& operator<<(std::ostream &out, const Shape& i)
{
   i.print(out);
   return out;
}