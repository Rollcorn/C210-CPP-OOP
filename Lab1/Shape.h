#pragma once


class Shape
{
public:
    Shape();
    ~Shape();

    // установить цвет фигуры
    virtual bool setColor();
    // отрисовка фигуры
    virtual bool draw();
    // Расчет площади фигуры
    virtual int areaCulc();
    
    enum colors{
        red,
        green,
        black
    };

private:


};

