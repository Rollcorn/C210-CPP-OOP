#pragma once

#include "typeinfo"
#include "iostream"

class Shape
{

public:
    enum colors  {
        wight = 0,
        red = 1,
        green = 2,
        black = 3
    } ;

    Shape() : color(colors::red){}

    Shape( colors color ) : color(color){}

    // установить цвет фигуры
    void SetColor(colors newColor);

    // установить цвет фигуры
    std::string getColor() const;

    // Расчет площади фигуры
    virtual int AreaCalc() const = 0;

    virtual Shape * Clone() const = 0;

    virtual bool operator==( const Shape &rhs) const;

    virtual bool operator!=( const Shape &rhs) const;

    virtual void print(std::ostream &out) const;

    virtual Shape& operator=(const Shape& a_other);

private:
    colors color;
    std::string colorStrArr[4] = {"wight", "red", "green", "black" };

};

std::ostream& operator<<( std::ostream &out, const Shape& i );
