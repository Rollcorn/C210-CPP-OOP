//Исключения

//Шаблоны:
//		шаблоны функций,
//		шаблоны классов,


#include <stdexcept>
#include <iostream>
//#include "tchar.h"
#include "swap.h"
#include "MyStack.h"
#include "LstStack.h"

#define stop __asm nop

int main(int argc, char* argv[])
{


/*
////////////////////////////////////////////////////////////////////////////
	//Тема. Шаблоны функций.
	//Создайте шаблон функции перестановки местами двух
	//значений - Swap(). Проверьте работоспособность созданного
	//шаблона с помощью приведенного ниже фрагмента кода.
	//Подсказка 1: объявление шаблона корректнее поместить в .h-файл.




	//Подсказка 2: подумайте, что нужно реализовать, для того,
	//			чтобы следующий вызов работал с объектами MyString
	//			не только корректно, но и эффективно
//	MyString str1("One"), str2("Two");
//	Swap(str1, str2);

*/

    int iX = 1, iY = -1;
    std::cout << "iX: " << iX << ", iY: " << iY << std::endl;
    Swap(iX, iY);
    std::cout << "iX: " << iX << ", iY: " << iY << std::endl;

    double dX = 0.5, dY = -5.5;
    std::cout << "dX: " << dX << ", dY: " << dY << std::endl;
    Swap(dX, dY);
    std::cout << "dX: " << dX << ", dY: " << dY << std::endl;
/////////////////////////////////////////////////////////////////////

    //Тема. Шаблоны классов.
    //Задание 1.
    //Создайте шаблон класса MyStack для хранения элементов любого типа T.
    //Подсказка: 1.элементы нужно где-то хранить - простым и удобным средством
    //			для хранения последовательно расположенных в памяти элементов
    //			является массив,
    //			2.для задания максимального размера стека может быть использован
    //			параметр-константа шаблона
    //			3.обязательными операциями со стеком являются "push" и "pop". Для
    //			того, чтобы гарантировать корректное выполнение этих операций
    //			хорошо было бы генерировать исключение в аварийной ситуации
    //			4. дополнительно реализуйте operator[] таким образом, чтобы пользователь
    //			мог читать/изменять значения только тех элементов, которые он формировал


    //С помощью шаблона MyStack создайте стек из 5 элементов int - iStack и
    //стек из 10 элементов MyString - strStack и поэкспериментируйте с функциями
    //push() и pop(), operator[]



    MyStack<int, 10> iStack;
    iStack.push(1);

    for (int i = 0; i < 10; ++i ) {
        iStack.push(i);
    }

    //int a = iStack.pop();
    std::cout << "iStack.pop() " << iStack.pop() << std::endl;
    iStack.pop();
    iStack[5] = 25;

    for (int i = 10; i >= 0; --i ) {
        std::cout << "iStack.pop() " << iStack.pop() << std::endl;
    }


    //Задание 2. Реализуйте шаблон стека - MyStack2 таким образом, чтобы
    //для хранения элементов использовался ОДНОСВЯЗНЫЙ список.
    //Реализуйте возможность распечатать элементы стека в том порядке, в котором их заносил (push())
    //пользователь
    try {


    LstStack<int> iLstStack;

    for (int i = 0; i < 10; ++i ) {
        std::cout << "iLstStack.push(" << i << ")" << std::endl;
        iLstStack.push(i);
    }
    std::cout << std::endl;

    LstStack<int> iLstStack2( std::move(iLstStack) );

    std::cout << "Вытащили всё из iLstStack"<< std::endl;
    for (int i = 10; i >= 0; --i ) {
        std::cout << "iLstStack.pop() : " << iLstStack.pop() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Вытащили всё из iLstStack2"<< std::endl;
    for (int i = 10; i >= 0; --i ) {
        std::cout << "iLstStack2.pop() : " << iLstStack2.pop() << std::endl;
    }
    } catch (const char* msg) {
        std::cout << msg << std::endl;

    }
    return 0;
}
