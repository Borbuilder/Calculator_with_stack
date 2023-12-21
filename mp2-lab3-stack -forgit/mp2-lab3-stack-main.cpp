#include <iostream>
#include<string>
#include "TCalc.h"


int main()
{
	setlocale(LC_ALL, "Russian");
	/*
	//Калькулятор
	std::cout << "Введите выражение" << std::endl;
	std::string expression;
	std::cin >> expression;
	TCalc m(expression);
	std::cout<<m.GetPostfix()<<std::endl;
	std::cout <<"Результат:"<<std::endl<<expression << " = " << m.CalculateWithPostfix()<<std::endl;
	*/
	
	TStack<int> a(2);
	a.Push(1);
	a.Push(2);
	a.output();
	TStack<int> b(a);
	std::cout << b.Pop() << " " << b.Pop();
};