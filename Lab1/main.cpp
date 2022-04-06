//
// Created by rollcorn on 06.04.2022.
//
#include "List.h"
#include "Rectangle.h"


int main(){
    List mylist;

    Rectangle rect(Shape::colors::green, 1, 3, 3, 1 );
    Rectangle rect2(Shape::colors::green, 1, 3, 3, 1 );

    Circle circ( Shape::colors::green, 1, 1, 2 );

    mylist.addToBegin(rect);
    mylist.addToEnd(circ);
    mylist.addToEnd(rect2);

    mylist.
    std::cout << rect << ", " << circ;

    return 0;
}