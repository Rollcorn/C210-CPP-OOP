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

std::ostream& operator<<(std::ostream &out, const Shape& i)
{
   i.print(out);
   return out;
}