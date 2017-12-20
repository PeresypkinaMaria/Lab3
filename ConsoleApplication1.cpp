/*3. Реализовать шаблон класса стек (Stack<X>), хранящий элементы произвольного типа.
Класс должен в обязательном порядке содержать методы:
Вычисление длины стека;
Добавление нового элемента в голову стека;
Получение элемента из головы стека;
Удаление элемента из головы;
Поиск элемента в стеке;
Печать стека.
a) Реализация стека с помощью массива;
b) Реализация стека с помощью списка.
Пересыпкина М.А.*/

#include "stdafx.h"
#include <cassert> // для assert
#include <iostream>
#include <Windows.h>
#include <iomanip> // для setw

using namespace std;

template <typename T>
class Stack
{
private:
	T *stackPtr;                      // указатель на стек
	const int size;                   // максимальное количество элементов в стеке
	int top;                          // номер текущего элемента стека
public:
	Stack(int = 10);                  // по умолчанию размер стека равен 10 элементам
	Stack(const Stack<T> &);          // конструктор копирования
	~Stack();                         // деструктор

	inline void push(const T &);     // поместить элемент в вершину стека
	inline T pop();                   // удалить элемент из вершины стека и вернуть его
	inline void printStack();         // вывод стека на экран
	inline const T &Peek(int) const; // n-й элемент от вершины стека
	inline int getStackSize() const;  // получить размер стека
	inline T *getPtr() const;         // получить указатель на стек
	inline int getTop() const;        // получить номер текущего элемента в стеке
};

// реализация методов шаблона класса STack

// конструктор Стека
template <typename T>
Stack<T>::Stack(int maxSize) :
	size(maxSize) // инициализация константы
{
	stackPtr = new T[size]; // выделить память под стек
	top = 0; // инициализируем текущий элемент нулем;
}

// конструктор копирования
template <typename T>
Stack<T>::Stack(const Stack<T> & otherStack) :
	size(otherStack.getStackSize()) // инициализация константы
{
	stackPtr = new T[size]; // выделить память под новый стек
	top = otherStack.getTop();

	for (int ix = 0; ix < top; ix++)
		stackPtr[ix] = otherStack.getPtr()[ix];
}

// функция деструктора Стека
template <typename T>
Stack<T>::~Stack()
{
	delete[] stackPtr; // удаляем стек
}

// функция добавления элемента в стек
template <typename T>
inline void Stack<T>::push(const T &value)
{
	// проверяем размер стека
	assert(top < size); // номер текущего элемента должен быть меньше размера стека

	stackPtr[top++] = value; // помещаем элемент в стек
}

// функция удаления элемента из стека
template <typename T>
inline T Stack<T>::pop()
{
	// проверяем размер стека
	assert(top > 0); // номер текущего элемента должен быть больше 0

	stackPtr[--top]; // удаляем элемент из стека
	return 0;
}

// функция возвращает n-й элемент от вершины стека
template <class T>
inline const T &Stack<T>::Peek(int nom) const
{
	//
	assert(nom <= top);

	return stackPtr[top - nom]; // вернуть n-й элемент стека
}

// вывод стека на экран
template <typename T>
inline void Stack<T>::printStack()
{
	for (int ix = top - 1; ix >= 0; ix--)
		cout << "|" << setw(4) << stackPtr[ix] << endl;
}

// вернуть максимальный размер стека
template <typename T>
inline int Stack<T>::getStackSize() const
{
	return size;
}

// вернуть указатель на стек (для конструктора копирования)
template <typename T>
inline T *Stack<T>::getPtr() const
{
	return stackPtr;
}

// вернуть размер стека
template <typename T>
inline int Stack<T>::getTop() const
{
	return top;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int item;
	int stop = -999;

	unsigned int maxStackSize = 100;
	Stack<int> st(maxStackSize);

	for (; ;)
	{
		cout << "1 - Ввести полностью" << endl;
		cout << "2 - Вычисление длины стека" << endl;
		cout << "3 - Добавление нового элемента в голову стека" << endl;
		cout << "4 - Получение элемента из головы стека" << endl;
		cout << "5 - Удаление элемента из головы" << endl;
		cout << "6 - Поиск элемента в стеке" << endl;
		cout << "7 - Печать стека" << endl;
		cout << "0 - Выход" << endl;
		cout << "Выберете необходимое действие" << endl;
		cin >> item;

		switch (item)
		{
		case 1: {
			int value;
			cout << "Введите элементы (признак конца: -999)" << endl;
			cin >> value;
			while (value != stop)
			{
				st.push(value);
				cin >> value;;
			}
			cout << endl;
			st.printStack();
			getchar();
			cout << endl;
			break;
		}
		case 2: {
			cout << "Размер стека: " << st.getTop() << endl;
			getchar();
			cout << endl;
			break;
		}
		case 3: {
			int value;
			cout << "Введите элемент" << endl;
			cin >> value;
			st.push(value);
			cout << "Элемент добавлен" << endl;
			st.printStack();
			getchar();
			cout << endl;
			break;
		}
		case 4: {
			if (st.getTop() == 0)
			{
				cout << "В стеке нет элементов" << endl;
				getchar();
				cout << endl;
				break;
			}
			else
			{
				cout << "Искомый элемент: " << st.Peek(1) << endl;
				getchar();
				cout << endl;
				break;
			}
		}
		case 5: {
			if (st.getTop() == 0)
			{
				cout << "Попытка удаления элемента из пустого стека" << endl;
				getchar();
				cout << endl;
				break;
			}
			else
			{
				st.pop();
				cout << "Элемент удалён" << endl;
				st.printStack();
				getchar();
				cout << endl;
				break;
			}
		}
		case 6: {
			if (st.getTop() == 0)
			{
				cout << "В стеке нет элементов" << endl;
				getchar();
				cout << endl;
				break;
			}
			else
			{
				int num;
				cout << "Введите номер элемента, который хотите получить" << endl;
				cin >> num;
				if (num > st.getTop() || num <= 0)
				{
					cout << "Элемента с таким номером в стеке нет" << endl;
					getchar();
					cout << endl;
					break;
				}
				else 
				{
					cout << "Искомый элемент: " << st.Peek(num) << endl;
					getchar();
					cout << endl;
					break;
				}
			}
		}
		case 7: {
			st.printStack();
			getchar();
			cout << endl;
			break;
		}
		case 0: exit(1); break;
		default: {
			cout << "Некорретный ввод" << endl;
			cout << endl;
			break;
		}
		}
		getchar();
	}
	return 0;
}

