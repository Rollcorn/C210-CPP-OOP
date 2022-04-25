//
// Created by rollcorn on 06.04.2022.
//
#include "List.h"
#include "Rectangle.h"

// ������� ��������� ����� �� ����������� �������
struct AreaShapeCompare
{
    bool operator()( const Shape& sh1 , const Shape& sh2 ) const {
        return sh1.AreaCalc() > sh2.AreaCalc();
    }
};

// ������� ��������� ����� �� ����� �� ������ � �������
struct ColorShapeCompare
{
    bool operator()( const Shape& sh1 , const Shape& sh2 ) const {
        return sh1.getColor() < sh2.getColor();
    }
};

//struct CoordinatesShapeCompare
//{
//    bool operator()( const Shape& sh1 , const Shape& sh2 ) const {
////            return sh1.getColor() < sh2.getColor();
//    }
//};


int main(){
    List mylist1;

    Rectangle rect1(Shape::colors::green, 1, 3, 3, 1 );
    Rectangle rect2(Shape::colors::red, 4, 5, 7, 1 );
    Rectangle rect3(Shape::colors::black, 2, 4, 5, 2 );
    Rectangle rect4(Shape::colors::yellow, 4, 5, 7, 1 );
    Circle circ1( Shape::colors::wight, 1, 1, 2 );
    Circle circ2( Shape::colors::blue, 2, 2, 5 );
    Circle circ3( Shape::colors::green, 3, 3, 4 );

    mylist1.addToBegin(rect1);
    mylist1.addToEnd(circ1);
    mylist1.addToEnd(rect2);

    List mylist2;

    mylist2.addToBegin(rect3);
    mylist2.addToEnd(rect4);
    mylist2.addToEnd(circ2);

    std::cout << "1 - List "<< std::endl;
    std::cout << mylist1 << " Size: " << mylist1.getMSize() << std::endl;
//    rect1 = rect2;
    std::cout << "2 - List"<< std::endl;
    std::cout << mylist2 << " Size: " << mylist2.getMSize() << std::endl;
    std::cout << std::endl;

    std::cout << "2) Copy Constructor mylist1 = mylist2"<< std::endl;
    mylist1 = mylist2;
    std::cout << mylist1 << " Size: " << mylist1.getMSize() << std::endl;
    std::cout << std::endl;

    std::cout << "Remove all rectangles" << mylist1.removeAll(rect1);
    std::cout << mylist1 << " Size: " << mylist1.getMSize() << std::endl;
    std::cout << std::endl;

    std::cout << "2) Move Constructor"<< std::endl;
    List* mylist3 = new List( std::move(mylist2) );
    std::cout << *mylist3 << " Size: " << mylist3->getMSize() << std::endl;
    std::cout << std::endl;

    std::cout << "3) Sort by color"<< std::endl;
    std::cout << *mylist3 << std::endl;
    ColorShapeCompare pred;
    mylist3->sort(pred);
    std::cout << *mylist3 << std::endl;
    std::cout << std::endl;

    mylist3->addToEnd(rect1);
    mylist3->addToEnd(circ1);
    mylist3->addToEnd(rect2);

    std::cout << "4) Sort list 3 by area"<< std::endl;
    AreaShapeCompare pred2;
    std::cout << *mylist3 <<  std::endl;
    mylist3->sort(pred2);
    std::cout << *mylist3 <<  std::endl;
    std::cout << std::endl;

    std::cout << "5) Sort list 3 by color"<< std::endl;
    mylist3->sort(pred);
    std::cout << (*mylist3) << std::endl;
    std::cout << std::endl;

    return 0;
}