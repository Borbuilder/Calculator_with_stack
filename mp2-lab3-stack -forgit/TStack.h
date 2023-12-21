#pragma once
#include<iostream>

template <class T>
class TStack
{
private:
	T* pMem;
	int MaxSize;
	int CurrentIndex;

public:
	
	TStack(int ms);                                  // Конструктор по умолчанию
	TStack(const TStack& StackObject);               // Конструктор копирования

	bool operator ==(const TStack& StackObject);     // Оператор сравнения
	bool operator !=(const TStack& StackObject);     // Оператор сравнения 2
	TStack& operator = (const TStack& StackObject);  // Оператор присваивания

	bool empty();                                    // Метод проверки стека на пустоту
	bool full();                                     // Метод проверки стека на полноту
	int ElementsNumber();                            // Количесвто элементов в стеке
	void output();                                   // Метод вывода стека на экран 
	void Push(const T element);                      // Метод добавления элемента в стек
	void ClerStack();                                // Метод очистки стека
	T Pop();                                         // Метод получения вершины стека (c её перемещением)
	T Top();                                         // Метод получения значения вершины стека
};


//Реализация методов класса TStack

template <class T> //Конструктор по умолчанию
TStack<T>::TStack(int ms) 
{
	if (ms < 1)
	{
		throw std::exception();
	}
	MaxSize = ms;
	pMem = new T[MaxSize];
	CurrentIndex = -1;
}

template <class T> // Конструктор копирования
TStack<T>::TStack(const TStack& StackObject)
{
	MaxSize = StackObject.MaxSize;
	delete[] pMem;
	pMem = new T[MaxSize];
	CurrentIndex = StackObject.CurrentIndex;
	std::copy(StackObject.pMem, StackObject.pMem + (CurrentIndex+1), pMem);
}

template <class T> //Оператор сравнения
bool TStack<T>:: operator ==(const TStack& StackObject)
{
	if ((CurrentIndex) != (StackObject.CurrentIndex))
	{
		return false;
	}
	for (int i = 0; i < CurrentIndex; i++)
	{
		if (pMem[i] != StackObject.pMem[i])
		{
			return false;
		}
	}
	return true;
}

template <class T> //Оператор сравнения 2
bool TStack<T>:: operator !=(const TStack& StackObject)
{
	return !(*this == StackObject);
}

template <class T> //Оператор присваивания
TStack<T>& TStack<T>::operator = (const TStack& StackObject)
{
	if (*this != StackObject)
	{
		delete[] pMem;
		MaxSize = StackObject.MaxSize;
		CurrentIndex = StackObject.CurrentIndex;
		pMem = new T[MaxSize];
		std::copy(StackObject.pMem, StackObject.pMem + (CurrentIndex+1), pMem);
	}
	return *this;
}

template <class T> //Проверка на пустоту
bool TStack<T>::empty()
{
	if (CurrentIndex == -1)
	{
		return true;
	}
	return false;
}

template <class T> //Проверка на полноту
bool TStack<T>::full()
{
	if (CurrentIndex == MaxSize - 1)
	{
		return true;
	}
	return false;
}

template <class T> //Количество элементов
int TStack<T>::ElementsNumber()
{
	return CurrentIndex + 1;
}

template<class T>//Вывод
void TStack<T>::output()
{
	if (CurrentIndex == -1)
	{
		throw std::exception();
	}
	std::cout << "( ";
	for (int i = 0; i <= CurrentIndex; i++)
	{
		std::cout << pMem[CurrentIndex - i] << " ";
	}
	std::cout << ")" << std::endl;
}

template <class T> //Добавление элемента
void TStack<T>::Push(const T element)
{
	if (CurrentIndex + 1 >= MaxSize)
	{
		throw std::exception();
	}
	pMem[CurrentIndex + 1] = element;
	CurrentIndex++;
}

template <class T> //Получение вершины
T TStack<T>::Pop()
{
	if (CurrentIndex == -1)
	{
		throw std::exception();
	}
	CurrentIndex--;
	return pMem[CurrentIndex + 1];
}

template <class T> //Значение вершины
T TStack<T>::Top()
{
	if (CurrentIndex == -1)
	{
		throw std::exception();
	}
	return pMem[CurrentIndex];
}

template <class T> //Очистка стека ????? Нужно ли делать Pop для каждого элемента
void TStack<T>::ClerStack()
{
	CurrentIndex = -1;
}

