#include "Shape.h"

class Circle : public Shape
{
private:
    int m_xAxis;
    int m_yAxis;
    int m_radius;

public:
    Circle( int a_xAxis, int a_yAxis, int a_radius );
    ~Circle();

    // Инициализация параметров
    bool initCirle();

    // Расчет площади фигуры

    // Изменить радиус
    bool setRadius(int a_radius);


};

