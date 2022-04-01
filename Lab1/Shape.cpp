#include "Shape.h";

Shape::Shape()
{}

Shape::~Shape()
{}

void Shape::SetColor( int newColor) {
    color = newColor;
}

int Shape::GetColor() {
    return color;
}



bool Shape::operator==( const Shape &rhs) const{
    return color == rhs.color;
}

bool Shape::operator!=( const Shape &rhs) const{
    return this == ;
}
