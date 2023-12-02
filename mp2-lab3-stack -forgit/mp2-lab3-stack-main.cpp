#include <iostream>
#include<string>
#include "TCalc.h"


int main()
{
	setlocale(LC_ALL, "Russian");
	
	//Калькулятор
	std::cout << "Введите выражение" << std::endl;
	std::string expression;
	std::cin >> expression;
	TCalc m(expression);
	std::cout<<m.GetPostfix()<<std::endl;
	std::cout <<"Результат:"<<std::endl<<expression << " = " << m.CalculateWithPostfix()<<std::endl;
	
	

};