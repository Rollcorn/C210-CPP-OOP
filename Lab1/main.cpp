//
// Created by rollcorn on 06.04.2022.
//
#include "List.h"
#include "Rectangle.h"


int main(){
    List mylist1;

    Rectangle rect1(Shape::colors::green, 1, 3, 3, 1 );
    Rectangle rect2(Shape::colors::red, 4, 5, 7, 1 );
    Circle circ1( Shape::colors::green, 1, 1, 2 );

    mylist1.addToBegin(rect1);
    mylist1.addToEnd(circ1);
    mylist1.addToEnd(rect2);

    List mylist2;

    Rectangle rect3(Shape::colors::black, 2, 4, 5, 2 );
    Rectangle rect4(Shape::colors::red, 4, 5, 7, 1 );
    Circle circ2( Shape::colors::wight, 2, 2, 5 );

    mylist2.addToBegin(rect3);
    mylist2.addToEnd(rect4);
    mylist2.addToEnd(circ2);
    mylist2.addToEnd(rect2);

    std::cout << "1) "<< std::endl;
    std::cout << mylist1 << " Size: " << mylist1.getMSize() << std::endl;
    //rect1 = rect2;
    std::cout << mylist2 << " Size: " << mylist2.getMSize() << std::endl;

    std::cout << "2) "<< std::endl;
    mylist1 = mylist2;
    std::cout << mylist1 << " Size: " << mylist1.getMSize() << std::endl;
    std::cout << mylist2 << " Size: " << mylist2.getMSize() << std::endl;
    std::cout << "Remove " << mylist1.removeAll(rect1);

    std::cout << "2) Конструктор копирования"<< std::endl;
    List* mylist3 = new List(mylist2);
    std::cout << *mylist3 << " Size: " << mylist3->getMSize() << std::endl;


    return 0;
}