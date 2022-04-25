#pragma once

#include "typeinfo"
#include "iostream"

class Shape
{

public:
    enum colors  {
        wight   = 0,
        red     = 1,
        yellow   = 2,
        green   = 3,
        blue    = 4,
        black   = 5
    };

    Shape() : color(colors::red){}

    virtual ~Shape();

    Shape(colors color) : color(color){}

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
    std::string colorStrArr[6] = {"wight", "red", "yellow", "green", "blue", "black" };

};

std::ostream& operator<<( std::ostream &out, const Shape& i );
