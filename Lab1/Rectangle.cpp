//
// Created by rollcorn on 01.04.2022.
//

#include "Rectangle.h"

bool Rectangle::Draw() const {
    return false;
}

int Rectangle::AreaCulc() const {
    return 0;
}

Shape *Rectangle::Clone() const {
    return new Rectangle( static_cast<const Rectangle&>(this) );
}

Rectangle::Rectangle() {

}

bool Rectangle::operator==(const Shape &rhs) const {
    bool result;
    if( const Rectangle* mRec = dynamic_cast<const Rectangle*>(&rhs) ){
        return this->xAxis == mRec->xAxis && this->yAxis == mRec->yAxis && Shape::operator==(rhs);
    }

    return false;
}
