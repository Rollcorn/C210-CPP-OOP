//Стандартная библиотека шаблонов - STL 
	//Контейнеры стандартной библиотеки - vector
	//Итераторы

#include <iostream>
#include <vector>


#pragma warning(disable: 4786)


using namespace std;

// Функция вывода вектора
template<typename T>
void printVector(const vector<T>& vec) {
	cout << "Size: " << vec.size() << ", Capacity: " << vec.capacity()
		 << ", Max Size: " << vec.max_size() << endl;
	for ( int i = 0; i < vec.size(); ++i ) {
		cout << "vec[" << i << "] = " << vec[i] << endl;
	}
}
template<typename T>
void printVector(const vector<T*>& vec) {
	cout << "Size: " << vec.size() << ", Capacity: " << vec.capacity() 
		 << ", Max Size: " << vec.max_size() << endl;
	for ( int i = 0; i < vec.size(); ++i ) {
		cout << "vec[" << i << "] = " << *vec[i] << endl;
	}
}

template<typename T>
std::ostream &operator<<(std::ostream &a_out, const vector<T> &a_vec) {
    for ( int i = 0; i < a_vec.size(); ++i ) {
        a_out << "vec[" << i << "] = " << a_vec[i] << " ";
    }
    a_out << endl;
    return a_out;
}

class Point {
private:
	int m_x;
	int m_y;
public:
	Point() : m_x(0), m_y(0) {}
	Point(int a_x, int a_y):m_x(a_x), m_y(m_x){}
	friend std::ostream &operator<<(std::ostream &a_out, const Point &a_pnt);
};
// Перегрузка оператора вывода объекта типа Point
std::ostream &operator<<(std::ostream &a_out, const Point &a_pnt) {
    a_out << "X: " << a_pnt.m_x << ", Y: " << a_pnt.m_y;
	return a_out;
}

// Вставить элемент если он отсутствует в контейнере
template<typename T>
bool insertIfAbsent( vector<T>& a_vec, const T& a_elem ) {
    typename std::vector<T>::iterator itbeg = a_vec.begin();

    while (itbeg != a_vec.end() && *itbeg != a_elem ) {
        ++itbeg;
    }
    if (itbeg == a_vec.end() ) {
        a_vec.insert(a_vec.begin(), a_elem);
        return true;
    }
    return false;
}

// Вставить элемент после каждого элемента контейнера
template<typename T>
void separateInsert( vector<T>& a_vec, const T& a_elem ) {
    typename std::vector<T>::iterator itbeg = a_vec.begin();

    while ( itbeg != a_vec.end() ) {
        a_vec.insert(itbeg, a_elem);
        ++itbeg;
    }
}


int main()
{
	// Контейнер стандартной библиотеки vector 

//////////////////////////////////////////////////////////////////////
	//Создание векторов. 

	//Создайте следующие вектора:
	//---------------------------
	//пустой вектор целых чисел - vInt и проверьте с помощью функции size(),
	//что его размер нулевой. 

	vector<int> vInt;

	cout << "vInt Size: " << vInt.size() << endl; 
	
	
	//Раскомментируйте следующий фрагмент, подумайте - все ли корректно
	//Если есть некорректности, - исправьте

	vInt.reserve(5);
	vInt.front()=1;
	cout << "vInt.front(): " << vInt.front() << endl; 

	//С помощью функции push_back() в цикле заполните вектор какими-либо значениями.
	//На каждой итерации цикла следите за размером вектора с помощью методов
	//size(), capacity(), max_size() и выводите значения элементов. 
	//
	//Подсказка: так как такая проверка понадобится Вам и в следующих заданиях,
	//напишите шаблон функции, которая для вектора, содержащего элементы любого типа
	//выводит его "реквизиты" и значения элементов на консоль.
	cout << "Size: " << vInt.size() << ", Capacity: " << vInt.capacity()
		 << ", Max Size: " << vInt.max_size() << endl; 
	for ( int i = 10; i < 17; ++i ) {
		vInt.push_back(i);
		cout << "vec.push_back(" << i << ")" << endl;
		cout << "Size: " << vInt.size() << ", Capacity: " << vInt.capacity()
			 << ", Max Size: " << vInt.max_size() << endl;  
	}
	printVector(vInt);



	//вектор вещественных - vDouble1 с заданным Вами начальным размером  и
	//проверьте результат с помощью созданного Вами шаблона. Как будут
	//проинициализированы элементы вектора?
	vector<double> vDouble1(10);
	printVector(vDouble1);


	//вектор объектов типа MyString с начальным размером - 5 элементов
	//и инициализацией каждого элемента строкой "A"
	//C помощью функции at() а также с помощью оператора
	//индексирования []  измените значения каких-либо элементов.
	//Попробуйте "выйти" за границы вектора с помощью at() и
	//с помощью [].
	vector<string> MyString(5, "A");
	printVector(MyString);
	// MyString.at(2) = "B"; // exception
	MyString[3] = "C";
	// MyString[6] = "D";  // seg fault
	// MyString.at(6) = "E";  // exception
	printVector(MyString);

	//вектор вещественных - vDouble3, который является копией элементов
	// [0,5) массива вещественных чисел dMas. Предворительно массив dMas 
	//нужно создать и проинициализировать!
	vector<double> dMas;
	for ( int i = 10; i < 20; ++i ) {
		dMas.push_back(i);
		cout << "dMas.push_back(" << i << ")" << endl;

	}
    printVector(dMas);

	vector<double> vDouble3(dMas.begin(), dMas.begin() + 5 );
	printVector(vDouble3);


	//вектор вещественных - vDouble4, который является копией элементов
	// [2,5) вектора vDouble3. 

    vector<double> vDouble4(dMas.begin() + 2, dMas.begin() + 5 );
    printVector(vDouble4);


	//вектор элементов типа Point - vPoint1 а) с начальным размером 3. Какой конструктор
	//будет вызван для каждого элемента?
	//b) vPoint2 с начальным размером 5 и проинициализируйте каждый элемент координатами (1,1).
	vector<Point> vPoint1(3);
	vector<Point> vPoint2(5);
	std::vector<Point>::iterator vBeg = vPoint2.begin();
	while ( vBeg != vPoint2.end() ) {
		*vBeg = Point(1,1);
		++vBeg;
	}

	printVector(vPoint2);

	//вектор указателей на Point - vpPoint с начальным размером 5
	//Подумайте: как корректно заставить эти указатели "указывать" на объекты Point
	{

	//Подсказка: для вывода на печать значений скорее всего Вам понадобится
		//а) специализация Вашей шаблонной функции
		//б) или перегрузка operator<< для Point*
        vector<Point *> vpPoint(5);
        std::vector<Point *>::iterator vBeg = vpPoint.begin();
        while ( vBeg != vpPoint.end() ) {
            *vBeg = new Point(1,1);
            ++vBeg;
        }
        printVector(vpPoint);
        while ( vBeg != vpPoint.end() ) {
            delete *vBeg;
            ++vBeg;
        }
	}//Какие дополнительные действия нужно предпринять для такого вектора?



	///////////////////////////////////////////////////////////////////////
	//Резервирование памяти.
	//Подумайте, всегда ли верны приведенные ниже проверки?
		/*
		{
		size_t n=...
		vector<int> v(n);
		v.resize(n/2);
		if(v.capacity() == n) //true?
		}
		*/
    {
        cout << "Резервирование памяти" << endl;
        cout << "Test 1" << endl;
        size_t n=10;
        vector<int> v(n);
        v.resize(n/2);
        if(v.capacity() == n) { //true?
            cout << "True. Capacity " << v.capacity() << endl;
        } else {
            cout << "False. Capacity " << v.capacity() << endl;
        }
    }
		/*
		{
		int n=...
		size_t m=...	
		vector<int> v(n);
		v.reserve(m);
		if(v.capacity() == m) //true?
		}
		*/
    {
        cout << "Test 2 n = 5, m = 10" << endl;
        int n=5;
        size_t m=10;
        vector<int> v(n);
        v.reserve(m);
        if(v.capacity() == m) { //true?
            cout << "True. Capacity " << v.capacity() << endl;
        } else {
            cout << "False. Capacity " << v.capacity() << endl;
        }
    }
    {
        cout << "Test 2 n = 10, m = 5" << endl;
        int n=10;
        size_t m=5;
        vector<int> v(n);
        v.reserve(m);
        if(v.capacity() == m) {//true?
            cout << "True. Capacity " << v.capacity() << endl;
        } else {
            cout << "False. Capacity " << v.capacity() << endl;
        }
    }
		/*
		{
		vector<int> v(3,5);
		v.resize(4,10); //значения?
		v.resize(5); //значения?
	
		}
		*/
    {
        cout << "Test 3" << endl;
        vector<int> v(3,5);
        printVector(v);
        v.resize(4,10); //значения?
        printVector(v);
        v.resize(5); //значения?
        printVector(v);

    }
	//Создайте два "пустых" вектора с элементами
	//любого (но одного и того же типа) типа. 
	//В первом векторе зарезервируйте память под 5 элементов, а потом заполните
	//его значениями с помощью push_back.
	//Второй вектор просто заполните значениями посредством push_back.
	//
	//Сравните размер, емкость векторов и значения элементов
    {
        cout << "Test 4" << endl;
        vector<int> vInt1;
        vector<int> vInt2;
        vInt1.reserve(5);
        printVector(vInt1);
        printVector(vInt2);
        for ( int i = 0; i < 10; ++i ) {
            vInt1.push_back(i);
        }
        for ( int i = 9; i >= 0; --i ) {
            vInt2.push_back(i);
        }
        printVector(vInt1);
        printVector(vInt2);
    }

	//!!! shrink_to_fit - Уменьшение емкости вектора.
	//Для любого вектора из предыдущего задания требуется уменьшить емкость
	//до size.

    {
        cout << "shrink_to_fit" << endl;

        vector<int> vInt1;
        for ( int i = 0; i < 7; ++i ) {
            vInt1.push_back(i);
        }
        cout << "vInt1.size()" << vInt1.size() << endl;
        cout << "vInt1.capacity()" << vInt1.capacity() << endl;
        vInt1.shrink_to_fit();
        cout << "vInt1.size()" << vInt1.size() << endl;
        cout << "vInt1.capacity()" << vInt1.capacity() << endl;
        printVector(vInt1);

    }
	

	//Создание "двухмерного вектора" - вектора векторов
	//Задан одномерный массив int ar[] = {11,2,4,3,5};
	//Создайте вектор векторов следующим образом:
	//вектор vv[0] - содержит 11 элементов со значением 11
	//vv[1] - содержит 2,2
	//vv[2] - содержит 4,4,4,4
	//...
	//Распечатайте содержимое такого двухмерного вектора по строкам
	//с помощью:
	
	//std::cout<<vv<<std::endl;
    {
        int ar[] = {11,2,4,3,5};
        vector< vector<int> > vInt1;
        int arSize = sizeof (ar)/sizeof(int);
        for ( int i = 0; i < arSize; ++i ) {
            vInt1.push_back(vector<int>( ar[i],ar[i]) );
        }
        std::cout << vInt1 << std::endl;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	//Вставка элемента последовательности insert().
	//Реализуйте функцию, которая должна вставлять новый элемент
		//в начало вектора только при условии, что в векторе такого
		 //значения еще нет.
	//Проверьте работоспособность функции - в вектор vChar2 вставьте в начало вектора символ только при
	//условии, что в векторе такого символа еще нет.
		 //например: vChar2 - abc 
		 //При попытке вставить 'a' попытка должна быть проигнорирована
		 //При попытке вставить 'q' vChar2 - qabc 
    {
	vector<char> vChar2;
    printVector(vChar2);
    vChar2.push_back('a');
    vChar2.push_back('b');
    vChar2.push_back('c');
    printVector(vChar2);
    cout << "Insert 'q'" << insertIfAbsent(vChar2, 'q') << endl;
    insertIfAbsent(vChar2, 'a');
    cout << "Insert \'a\'" << insertIfAbsent(vChar2, 'a') << endl;

    printVector(vChar2);



    //Реализуйте функцию, которая должна вставлять новый элемент
		 //перед каждым элементом вектора
	//Проверьте работоспособность функции - вставьте перед каждым элементом вектора vChar2 букву 'W'

	separateInsert(vChar2, 'W');
    printVector(vChar2);

    }


///////////////////////////////////////////////////////////////////
	//Напишите функцию, которая должна удалять только повторяющиеся последовательности.
	//Например: было - "qwerrrrty12222r3", стало - "qwety1r3"




	

///////////////////////////////////////////////////////////////////

	//Удаление элемента последовательности erase()
	//Напишите функцию удаления из любого вектора всех дублей 
		 //Например: было - "qwerrrrty12222r3", стало - "qwerty123"



	

///////////////////////////////////////////////////////////////////
	//Создайте новый вектор таким образом, чтобы его элементы стали
	//копиями элементов любого из созданных ранее векторов, но расположены
	//были бы в обратном порядке






///////////////////////////////////////////////////////////////////

	//Задание 1. Списки. Операции, характерные для списков.
	//Создайте пустой список из элементов Point - ptList1 и наполните
	//его значениями с помощью методов push_back(),
	//push_front, insert()
	

	//Напишите шаблон функции, которая будет выводить элементы
	//ЛЮБОГО КОНТЕЙНЕРА на печать. Проверьте работу шаблона на контейнерах
	//vector и list. Подсказка - хотелось бы увидеть тип контейнера.


	//Сделайте любой из списков "реверсивным" - reverse()


	//Создайте список ptList2 из элементов Point таким образом, чтобы он стал 
	//копией вектора элементов типа Point, но значения элементов списка располагались
	//бы в обратном порядке 



	//Отсортируйте списки  ptList1 и ptList2 - методом класса list - sort()
	//по возрастанию.
	//Подумайте: что должно быть перегружено в классе Point для того, чтобы
	//работала сортировка


	



	//Объедините отсортированные списки - merge(). Посмотрите: что
	//при этом происходит с каждым списком.

	
	

	//Исключение элемента из списка - remove()
	//Исключите из списка элемент с определенным значением.
	//Подумайте: что должно быть перегружено в классе Point?
	

	//Исключение элемента из списка, удовлетворяющего заданному условию:
	//любая из координат отрицательна - remove_if(). 


	//Исключение из списка подряд расположенных дублей - unique(). 

	

///////////////////////////////////////////////////////////////////
	//Задание 2.Очередь с двумя концами - контейнер deque

	//Создайте пустой deque с элементами типа Point. С помощью
	//assign заполните deque копиями элементов вектора. С помощью
	//разработанного Вами в предыдущем задании универсального шаблона
	//выведите значения элементов на печать



	//Создайте deque с элементами типа MyString. Заполните его значениями
	//с помощью push_back(), push_front(), insert()
	//С помощью erase удалите из deque все элементы, в которых строчки
	//начинаются с 'A' или 'a'




	return 0;
}