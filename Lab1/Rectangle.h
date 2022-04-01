#include "Shape.h"


class Rectangle : public Shape
{
private:
    int xAxis;
    int yAxis;

public:
    Rectangle();

    Shape * Clone() const override;

    bool Draw() const override;

    int AreaCulc() const override;

    virtual bool operator==( const Shape &rhs) const;

};



