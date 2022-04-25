// Iter_Alg.cpp : Defines the entry point for the console application.
//
//Итераторы. Стандартные алгоритмы. Предикаты.

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>


#include "Point.h"
#include "Rectangle.h"

using namespace std;	
//#define	  stop __asm nop
template <typename T, typename C>
std::ostream &operator<<(std::ostream &os, const pair<T,C> &a_pair) {
    os << "[" << a_pair.first << "] : [" << a_pair.second << "]";
    return os;
}

template <typename T>
void printEl(const T& elm)
{
    std::cout << elm << endl;
}



template <typename T>
class ChangePoint
{
    T m_newX;
    T m_newY;
public:
    ChangePoint(T x = T(), T y = T()) : m_newX(x), m_newY(y){}
    void operator() (Point& p) { p.setMX(m_newX); p.setMY(m_newY);}
};

template <typename T>
class ChangeAny
{
    T m_new;

public:
    ChangeAny(const T& x = T() ) : m_new(x) {}
    void operator() (T& p) { p = m_new;}
};

template <typename T>
void print(const T& a_con)
{
    using IT = typename T::const_iterator;
    IT itb = a_con.begin();
    IT ite = a_con.end();

    for ( int i = 0; itb != ite; ++i ) {
        cout << "[" << i << "] = " << *itb << endl;
        ++itb;
    }
}

template<typename T>
class isPointBetween
{
    T m_n;
    T m_m;
public:
    isPointBetween(T n = T(), T m = T()) : m_n(n), m_m(m){}
    bool operator() (Point& p) {
        return ( p.getMX() >= -m_n ) ? ( (p.getMX() <= m_m)?( (p.getMY() >= -m_n)?( (p.getMY() <= m_m)?1:0):0):0):0;}
};



struct transToLower {
    string operator()(string s){
        transform(s.begin(), s.end(), s.begin(), static_cast<int (*)(int)>(tolower));
        return s;
    }
};

int main(int argc, char * argv[])
{
	
///////////////////////////////////////////////////////////////////

	//Задание 1. Итераторы

	//Реверсивные итераторы. Сформируйте set<Point>. Подумайте, что
	//нужно перегрузить в классе Point. Создайте вектор, элементы которого 
	//являются копиями элементов set, но упорядочены по убыванию


        Point p1(3.3, 3.9);
        Point p2(17, 9);
        Point p3(15, -4);
        Point p4(8, -7);
        vector<Point> vpPoint(4);

        vpPoint[0] = p1;
        vpPoint[1] = p2;
        vpPoint[2] = p3;
        vpPoint[3] = p4;

        set<Point> setP(vpPoint.begin(), vpPoint.end());

        vector<Point> vpPointbw(setP.rbegin(), setP.rend());

        //Потоковые итераторы. С помощью ostream_iterator выведите содержимое
        //vector и set из предыдущего задания на экран.

        ostream_iterator<Point> it(cout, "\n\t * ");
        cout << "Outputing the set:";
        copy(setP.begin(), setP.end(), it);

        cout << "Outputing the vector:";
        copy(vpPointbw.begin(), vpPointbw.end(), it);


        //Итераторы вставки. С помощью возвращаемых функциями:
        //back_inserter()
        //front_inserter()
        //inserter()
        //итераторов вставки добавьте элементы в любой из созданных контейнеров. Подумайте:
        //какие из итераторов вставки можно использовать с каждым контейнером.

        copy(setP.begin(), setP.end(), back_inserter(vpPointbw));

        cout << "Outputing the vector:";
        copy(vpPointbw.begin(), vpPointbw.end(), it);

///////////////////////////////////////////////////////////////////

	//Задание 2. Обобщенные алгоритмы (заголовочный файл <algorithm>). Предикаты.

	// алгоритм for_each() - вызов заданной функции для каждого элемента любой последовательности
	//(массив, vector, list...)
	//С помощью алгоритма for_each в любой последовательности с элементами любого типа
	//распечатайте значения элементов
	//Подсказка : неплохо вызываемую функцию определить как шаблон


        cout << "[ for_each ]" << endl;
        for_each(vpPointbw.begin(), vpPointbw.end(), printEl<Point>);


	//С помощью алгоритма for_each в любой последовательности с элементами типа Point
	//измените "координаты" на указанное значение (такой предикат тоже стоит реализовать 
	//как шаблон) и выведите результат с помощью предыдущего предиката


        cout << "for_each mod" << endl;
        for_each(vpPointbw.begin(), vpPointbw.end(), ChangePoint<int>(1, 1));
        for_each(vpPointbw.begin(), vpPointbw.end(), printEl<Point>);
        cout << "for_each mod T()" << endl;
        for_each(vpPointbw.begin(), vpPointbw.end(), ChangePoint<int>());
        for_each(vpPointbw.begin(), vpPointbw.end(), printEl<Point>);



	//С помощью алгоритма find() найдите в любой последовательности элементов Point
	//все итераторы на элемент Point с указанным значением.

    {
        vector<Point> vpPointbw3(setP.rbegin(), setP.rend());

        auto it = vpPointbw3.begin();

        while(it != vpPointbw3.end())
        {
            it = find(it, vpPointbw3.end(), Point(15, -4));
            if(it == vpPointbw3.end())
                break;
            cout << *it;
            it++;
        }
    }

	
	
	//С помощью алгоритма sort() отсортируйте любую последовательность элементов Point. 
	////По умолчанию алгоритм сортирует последовательность по возрастанию.
	//Что должно быть определено в классе Point?
	// Замечание: обобщенный алгоритм sort не работает со списком, так как
	//это было бы не эффективно => для списка сортировка реализована методом класса!!!

    {
        cout << endl;

        vector<Point> pVector;
        pVector.push_back(p1);
        pVector.push_back(p2);
        pVector.push_back(p3);
        pVector.push_back(p4);
        cout << "before sort" << endl;
        print(pVector);

        sort(pVector.begin(), pVector.end());
        cout << "after sort" << endl;
        print(pVector);

    }


	//С помощью алгоритма find_if() найдите в любой последовательности элементов Point
	//итератор на элемент Point, удовлетворяющий условию: координаты x и y лежат в промежутке
	//[-n, +m].
    {
        cout << "find_if() isPointBetween" << endl;
        vector<Point> vpPointbw3(setP.rbegin(), setP.rend());

        auto it = vpPointbw3.begin();

        while (it != vpPointbw3.end()) {
            it = find_if(it, vpPointbw3.end(), isPointBetween<int>(15, 15));
            if (it == vpPointbw3.end())
                break;
            cout << *it;
            it++;
        }
    }
	//С помощью алгоритма sort() отсортируйте любую последовательность элементов Rect,
	//располагая прямоугольники по удалению центра от начала координат.
	
    {
        cout << "[ Rect sort() ]" << endl;
        Rectangle arR[] = {{11, 15},
                           {3, 25},
                           {14, 2},
                           {3, 17},
                           {2, 2}};

        for_each(begin(arR), end(arR), printEl<Rectangle>);

        sort(begin(arR),
             end(arR),
             [](const Rectangle& a, const Rectangle& b) {return a.dist() < a.dist();}
        );
        cout << "Rect sorted";
        for_each(begin(arR), end(arR), printEl<Rectangle>);
    }


	{//transform
		//Напишите функцию, которая с помощью алгоритма transform переводит 
		//содержимое объекта string в нижний регистр.
		//Подсказка: класс string - это "почти" контейнер, поэтому для него
		// определены методы begin() и end()

        string str("hello");
        transform(str.begin(), str.end(), str.begin(), static_cast<int (*)(int)>(toupper));
        cout << str;


		//Заполните list объектами string. С помощью алгоритма transform сформируте
		//значения "пустого" set, конвертируя строки в нижний регистр


        list<string> lStr;
        lStr.push_back("ASD");
        lStr.push_back("ASDF");
        lStr.push_back("OIUYT");
        lStr.push_back("MNBVC");

        set<string>  sStr;
        list<string> lStr2;
        insert_iterator<set<string>> b_it(sStr, sStr.begin());

        transform(lStr.begin(), lStr.end(), b_it, transToLower() );

        for_each(begin(sStr), end(sStr), printEl<string>);


	}

    {
        //copy_if
        //Дан вектор с элементами типа string. С помощью copy_if() требуется
        //вывести сначала строки, начинающиеся с буквы "А" или "а", затем с "Б"...
        //При этом порядок строк в исходном векторе менять не нужно!
/*
        vector<string> sVec;
        sVec.push_back("ASD");
        sVec.push_back("ASDF");
        sVec.push_back("OIUYT");
        sVec.push_back("MNBVC");

*/

        //Дан multimap, содержаций пары: "месяц - количество денй в месяце"
        //pair<string, int>. С помощью copy_if сформируйте ДВА map-а: первый -
        //с парами, содержащими четное количество дней, 2-ой - нечетное.

    {
        std::multimap<string, int> month{
                {"January",   31},
                {"February",  28},
                {"February",  29},
                {"March",     31},
                {"April",     30},
                {"May",       31},
                {"June",      30},
                {"July",      31},
                {"August",    31},
                {"September", 30},
                {"October",   31},
                {"November",  30},
                {"December",  31}
        };

        cout << "[Even days month map]" << endl;
        map<string, int> evenMap;
        copy_if(month.begin(), month.end(), inserter(evenMap, evenMap.begin()),
                                           [](const pair<string,int>& p) {return p.second % 2 == 0;} );
        for_each(begin(evenMap), end(evenMap),
                 [](const pair<string,int>& p) {cout << p.first << ":" << p.second << endl;}
        );

        cout << "[Odd days month map]" << endl;
        map<string, int> oddMap;
        copy_if(month.begin(), month.end(), inserter(oddMap, oddMap.begin()),
                [](const pair<string,int>& p) {return p.second % 2 == 1;} );
        for_each(begin(oddMap), end(oddMap),
                 [](const pair<string,int>& p) {cout << p.first << endl;}
        );


		//Распечатайте multimap и map-ы, используя написанный вами ранее шаблон
		//функции, выводящей элементы ЛЮБОГО контейнера на печать.
		//Что нужно сделать дополнительно для вывода пары?

		cout << "[Output]" << endl;
        for_each(begin(oddMap), end(oddMap), printEl<pair<string,int>>);

	}

	return 0;
    }
}