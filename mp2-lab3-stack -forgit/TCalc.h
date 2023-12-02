#pragma once
#include<iostream>
#include<string>
#include "TStack.h"


class TCalc
{
private:
	std::string infix; // Инфиксная строка, подаваемая на вход
	std::string postfix; // Постфиксная строка

	TStack<char> OpStack = TStack<char>(10); // Стек из операций "+", "-", ")" и тд
	TStack<double> NumStack = TStack<double>(10); // Стек из чисел из инфиксной строки

	int priority(char op); // Метод , определяющий приоритет операций
	void ToPostfix(); // Метод перевода инфиксной строки в постфиксную

public:
	std::string GetInfix() { return infix; } // Получить инфиксную строку
	std::string GetPostfix() { return postfix; } // Получить инфиксную строку
	void SetInfix(std::string _infix) { infix = _infix; } // Записать строку в ификсную строку

	TCalc(std::string _infix) :infix(_infix) { this->ToPostfix(); } // Конструктор по умолчанию
	double CalculateWithPostfix(); // Метод вычисления c постфиксной 
	double CalculateNoPostfix(); // Метод вычисления 

	
};

