// Контейнеры STL: 
//stack, queue, priority_queue
//set, multiset, map, multimap

// #include "stdafx.h"
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <cstring>
#include <clocale>

#include <iostream>

using namespace std;

//#define stop __asm nop
class myless {
public:

    bool operator()(const char * a_s1, const char * a_s2 ) const{

        return strcmp(a_s1, a_s2) < 0;
    }

};


class Point {
private:
    int m_x;
    int m_y;
public:
    Point() : m_x(0), m_y(0) {}
    Point(int a_x, int a_y):m_x(a_x), m_y(a_y){}
    friend std::ostream &operator<<( std::ostream &a_out, const Point &a_pnt );

    int getMX() const{ return m_x; }
    int getMY() const{ return m_y; }

    bool operator==(const Point &rhs) const;
    bool operator!=(const Point &rhs) const;
    bool operator<(const Point &rhs) const;
};

// Перегрузка оператора вывода объекта типа Point
std::ostream &operator<<(std::ostream &a_out, const Point &a_pnt) {
    a_out << "X: " << a_pnt.m_x << ", Y: " << a_pnt.m_y;
    return a_out;
}

// Перегрузка оператора вывода объекта типа Point
std::ostream &operator<<(std::ostream &a_out, const Point* a_pnt) {
    a_out << "[X: " << a_pnt->getMX() << ", Y: " << a_pnt->getMY() << "]";
    return a_out;
}

ostream &operator<<(ostream &output, const char **str)
{
    output << *str;
    return output;
}

bool Point::operator<(const Point &rhs) const {
    int leftDist = m_y*m_y + m_x*m_x;
    int rightDist = rhs.m_y*rhs.m_y + rhs.m_x*rhs.m_x;
    return leftDist < rightDist;
}

bool Point::operator==(const Point &rhs) const {
    return m_x == rhs.m_x && m_y == rhs.m_y;
}

bool Point::operator!=(const Point &rhs) const {
    return !(rhs == *this);
}

template <typename T>
void print(T a_con)
{
    using IT = typename T::iterator;
    IT itb = a_con.begin();
    IT ite = a_con.end();

    for ( int i = 0; itb != ite; ++i ) {
        cout << "[" << i << "] = " << *itb << endl;
        ++itb;
    }
}

template <typename T>
const typename T::value_type& getTop(const T& a_con) {
    return a_con.top();
}

template <typename T, typename C>
const T& getTop(const queue<T,C>& a_con) {
    return a_con.front();
}

template <typename T, typename C, typename CMP>
std::ostream &operator<<(std::ostream &os, const priority_queue<T,C,CMP> &a_pq) {
    auto pq(a_pq);
    while (!pq.empty())
    {
        os << getTop(pq) << ", ";
        pq.pop();
    }
    return os;
}

template <typename T, typename C>
std::ostream &operator<<(std::ostream &os, const pair<T,C> &a_pair) {
    os << "[" << a_pair.first << " : " << a_pair.second << "]";
    return os;
}

template <typename T, typename CMP, typename A>
std::ostream &operator<<(std::ostream &os, const set<T,CMP,A> &a_pair) {
    auto itb = a_pair.begin();
    while (itb != a_pair.end() ) {
        os << "[" << *itb << "]";
        ++itb;
    }
    return os;
}

template <typename T, typename CMP>
std::ostream &operator<<(std::ostream &os, const multiset<T,CMP> &a_mulm) {
    auto itb = a_mulm.begin();
    while (itb != a_mulm.end() ) {
        os << *itb;
        ++itb;
        if (itb != a_mulm.end() ){
            os << ", ";
        }
    }
    return os;
}

template <typename T>
void printSQP(T a_con){
    while (!a_con.empty())
    {
        cout << getTop(a_con) << " ";
        a_con.pop();
    }
    std::cout << std::endl;
}

int main(int argc, char* argv[]) {


    //Напишите шаблон функции для вывода значений stack, queue, priority_queue
    //обратите внимание на то, что контейнеры предоставляют РАЗНЫЕ методы для
    //получения значений

    {
        std::stack<int> sInt;
        sInt.push(3);
        sInt.push(1);
        sInt.push(2);
        printSQP(sInt);
        cout << "stack size() " << sInt.size() << endl;

        std::queue<int> qInt;
        qInt.push(3);
        qInt.push(1);
        qInt.push(2);
        printSQP(qInt);
        cout << "queue size() " << qInt.size() << endl;

        std::priority_queue<int> pqInt;
        pqInt.push(3);
        pqInt.push(1);
        pqInt.push(2);
        printSQP(pqInt);
        cout << "priority_queue size() " << pqInt.size() << endl;
    }

    ////////////////////////////////////////////////////////////////////////////////////
    //stack

    //Создайте стек таким образом, чтобы
    //а) элементы стека стали копиями элементов вектора
    //б) при выводе значений как вектора, так и стека порядок значений был одинаковым

    {
        cout << "[Copy vector to stack ?]" << endl;

        vector<int> vInt = {5, 6, 2, 7, 3, 8, 4, 9};
        cout << "vector size() " << vInt.size() << endl;
        print(vInt);
        std::stack<int, vector<int>> sInt(vector<int>(vInt.rbegin(), vInt.rend()));
        printSQP(sInt);
    }


    ////////////////////////////////////////////////////////////////////////////////////
    //queue

    //Создайте очередь, которая содержит указатели на объекты типа Point,
    //при этом явно задайте базовый контейнер.
    //Измените значения первого и последнего элементов посредством front() и back()
    //Подумайте, что требуется сделать при уничтожении такой очереди?

    {
        cout << "[ Очередь, которая содержит указатели на объекты типа Point ]" << endl;

        queue<Point *, list<Point *>> qptrPoint;
        qptrPoint.push(new Point(1, 1));
        qptrPoint.push(new Point(2, 2));
        qptrPoint.push(new Point(3, 4));
        qptrPoint.push(new Point(4, 4));
        printSQP(qptrPoint);
        *qptrPoint.front() = Point(99, 99);
        *qptrPoint.back() = Point(11, 11);
        printSQP(qptrPoint);
        while (!qptrPoint.empty()) {
            delete qptrPoint.front();
            qptrPoint.pop();
        }
    }

    ////////////////////////////////////////////////////////////////////////////////////
    //priority_queue
    //а) создайте очередь с приоритетами, которая будет хранить адреса строковых литералов - const char*
    //б) проинициализируйте очередь при создании с помощью вспомогательного массива с элементами const char*
    //в) проверьте "упорядоченность" значений (с помощью pop() ) - если они оказываются не упорядоченными, подумайте:
    //		что сравнивается при вставке?

    {
        cout << "[ очередь с приоритетами, которая будет хранить адреса строковых литералов - const char*  ]" << endl;

        const char *c1 = "aaa";
        const char *c4 = "aab";
        const char *c3 = "aabс";
        const char *c2 = "abac";
        const char *c5 = "";
        const char *chArr[] = {"aaa", "bac", "caba", "aab", "abacb", "abc", "cab" "aabс", "abac"};
        priority_queue<const char *, deque<const char *>, myless> chPqueue(chArr, chArr + size(chArr));
        printSQP(chPqueue);
    }

    ////////////////////////////////////////////////////////////////////////////////////
    //set
    //  a) создайте множество с элементами типа Point - подумайте, что необходимо определить
    //	в классе Point (и каким образом)
    //  б) распечатайте значения элементов с помощью шаблона, реализованного в предыдущей лаб. работе
    //  в) попробуйте изменить любое значение...
    //  г) Создайте два множества, которые будут содержать одинаковые значения
    //		типа int, но занесенные в разном порядке
    //  д) Вставьте в любое множество диапазон элементов из любого другого
    //	контейнера, например, элементов массива	(что происходит, если в массиве имеются дубли?)

    {
        cout << "[ SET ]" << endl;

        set<Point> sPoint;
        sPoint.insert(Point(1, 1));
        sPoint.insert(Point(2, 2));
        sPoint.insert(Point(3, 3));
        cout << "sPoint" << endl;
        print(sPoint);

        set<Point> sPoint2;
        sPoint2.insert(Point(3, 3));
        sPoint2.insert(Point(1, 1));
        sPoint2.insert(Point(2, 2));

        cout << "sPoint2" << endl;
        print(sPoint2);
        sPoint.insert(Point(5, 1));
        sPoint.insert(Point(4, 2));
        sPoint.insert(Point(3, 6));

        sPoint2.insert(sPoint.begin(), sPoint.end());
        cout << "Point2.insert(sPoint.begin(), sPoint.end())" << endl;
        print(sPoint2);

    }


    ////////////////////////////////////////////////////////////////////////////////////
    //map, multiset
    //а) создайте map, который хранит пары "фамилия, зарплата" - pair<const char*, int>,
    //	при этом строки задаются строковыми литералами
    //б) заполните контейнер значениями посредством operator[] и insert()
    //в) распечатайте содержимое
    //г) замените один из КЛЮЧЕЙ на новый (была "Иванова", вышла замуж => стала "Петрова")


    {
        cout << "[ map, multiset ]" << endl;

        map<const char *, int, myless> mSurSal;
        mSurSal["Иванова"] = 15000;
        mSurSal["Петров"] = 11000;
        mSurSal["Семенов"] = 8000;
        cout << "map:" << endl;
        print(mSurSal);

        const char *oldSur = "Иванова";
        const char *newSur = "Петрова";

        auto it = mSurSal.find(oldSur);
        if (it != mSurSal.end()) {
            mSurSal[newSur] = it->second;
            mSurSal.erase(it);
        }
        cout << "map after change [" << oldSur << "] on [" << newSur << "]" << endl;
        print(mSurSal);

    }

    //д) Сформируйте любым способом вектор с элементами типа string.
    //Создайте (и распечатайте для проверки) map<string, int>, который будет
    //содержать упорядоченные по алфавиту строки и
    //количество повторений каждой строки в векторе

    {
        cout << "[ map<>, который содержит упорядоченные по алфавиту строки и количество повторений ]" << endl;

        vector<string> strVec = {"Иванов", "Аава", "Баранов", "Абрамов", "Афанасьев", "Иванов", "Баранов", "Баранова",
                                 "Григорьев", "Иванов"};
        map<string, int> strMap;
        for (int i = 0; i < strVec.size(); ++i) {
 //           strMap.insert_or_assign(strVec[i], strMap[strVec[i]] + 1);
            strMap[strVec[i]]++;
        }
        print(strMap);
    }

    //е)
    //задан массив:
    //const char* words[] = {"Abba", "Alfa", "Beta", "Beauty" ,...};
    //создайте map, в котором каждой букве будет соответствовать совокупность
    //лексиграфически упорядоченных слов, начинающихся с этой буквы.
    //Подсказка: не стоит хранить дубли одной и той же строки

    //'A' -  "Abba" "Alfa"
    //'B' -  "Beauty" "Beta"  ...
    //...
    {
        cout << "[ map, в котором каждой букве соответствует совокупность лексиграфически упорядоченных слов, начинающихся с этой буквы. ]"
            << endl;

        const char *words[] = {"abba", "Alfa", "Alfa", "Beta", "Beauty"};
        map<char, set<string> > priStrMap;
        for (int i = 0; i < size(words); ++i) {
            char let = toupper(words[i][0]);
            priStrMap[let].insert(words[i]);
        }

        print(priStrMap);

    }
    //ж)
    //создайте структуру данных, которая будет хранить информацию о студенческих группах.
    //Для каждой группы должны хранится фамилии студентов (по алфавиту). При этом
    //фамилии могут дублироваться
    //Сами группы тоже должны быть упорядочены по номеру
    //
    //номера

    map<int, multiset<string> > StudyGroup;
    multiset<string> group1010;
    group1010.insert("abba");
    group1010.insert("Alfa");
    group1010.insert("Alfa");

    multiset<string> group2010;
    group2010.insert("Beta");
    group2010.insert("Beauty");
    group2010.insert("Alfa");

    StudyGroup[1010] = group1010;
    StudyGroup[2010] = group2010;

    print(StudyGroup);
    ////////////////////////////////////////////////////////////////////////////////////
    //multimap
    //а) создайте "англо-русский" словарь, где одному и тому же ключу будут соответствовать
    //		несколько русских значений - pair<string,string>, например: strange: чужой, странный...
    //б) Заполните словарь парами с помощью метода insert или проинициализируйте с помощью
    //		вспомогательного массива пара (пары можно конструировать или создавать с помощью шаблона make_pair)
    //в) Выведите все содержимое словаря на экран
    //г) Выведите на экран только варианты "переводов" для заданного ключа. Подсказка: для нахождения диапазона
    //		итераторов можно использовать методы lower_bound() и upper_bound()


    {

    multimap<string, string> dictionary;

    dictionary.insert(pair<string, string>(string("strange"), string("чужой")));
    dictionary.insert(pair<string, string>(string("strange"), string("странный")));
    dictionary.insert(pair<string, string>(string("walk"), string("ходить")));
    dictionary.insert(pair<string, string>(string("walk"), string("глять")));
    dictionary.insert(pair<string, string>(string("run"), string("бежать")));
    dictionary.insert(pair<string, string>(string("run"), string("запускать")));
    dictionary.insert(pair<string, string>(string("run"), string("вести")));

    //cout << dictionary;
    print(dictionary);
    multimap<string, string>::iterator itlow = dictionary.lower_bound("run");
    multimap<string, string>::iterator itup = dictionary.upper_bound("run");

    cout << "This is the defs for 'strang': ";
    for (multimap<string, string>::iterator it = itlow; it != itup; ++it) {
        cout << (*it).second << '\n';
    }

    }

	return 0;
}

