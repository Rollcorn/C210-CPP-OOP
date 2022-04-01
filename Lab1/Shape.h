#pragma once

#include "typeinfo"

class Shape
{


public:
    enum colors{
        red = 1,
        green = 2,
        black = 3
    };

    Shape();
    ~Shape();

    // установить цвет фигуры
    void SetColor( int newColor);
    // установить цвет фигуры
    int GetColor();
    // отрисовка фигуры
    virtual bool Draw() const = 0;
    // Расчет площади фигуры
    virtual int AreaCulc() const = 0;

    virtual Shape * Clone() const = 0;

    virtual bool operator==( const Shape &rhs) const;

    virtual bool operator!=( const Shape &rhs) const;

private:
    colors color;

private:


};

