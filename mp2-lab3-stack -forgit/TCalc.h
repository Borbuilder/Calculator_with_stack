#pragma once
#include<iostream>
#include<string>
#include "TStack.h"


class TCalc
{
private:
	std::string infix; // ��������� ������, ���������� �� ����
	std::string postfix; // ����������� ������

	TStack<char> OpStack = TStack<char>(10); // ���� �� �������� "+", "-", ")" � ��
	TStack<double> NumStack = TStack<double>(10); // ���� �� ����� �� ��������� ������

	int priority(char op) {
		switch (op)
		{
		case '+':
			return 1;
		case '-':
			return 1;
		case '/':
			return 2;
		case '*':
			return 2;
		case '^':
			return 3;
		case '(':
			return 0;
		case ')':
			return 0;
		default:
			break;
		}
	}; // ����� , ������������ ��������� ��������
	void ToPostfix() {
		OpStack.ClerStack();
		std::string str = '(' + infix + ')';

		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '(')
			{
				OpStack.Push('(');
			}

			if ((str[i] >= '0') && (str[i] <= '9'))
			{
				postfix += str[i];
			}

			if (str[i] == ')')
			{
				char OpStackElement = OpStack.Pop();
				while (OpStackElement != '(')
				{
					postfix += OpStackElement;
					OpStackElement = OpStack.Pop();
				}
			}

			if ((str[i] == '+') || (str[i] == '-') || (str[i] == '*') || (str[i] == '/') || (str[i] == '^'))
			{
				char OpStackElement = OpStack.Pop();
				while (priority(OpStackElement) >= priority(str[i]))
				{
					postfix += OpStackElement;
					OpStackElement = OpStack.Pop();
				}
				OpStack.Push(OpStackElement);
				OpStack.Push(str[i]);
			}
		}
	}; // ����� �������� ��������� ������ � �����������

public:
	std::string GetInfix() { return infix; } // �������� ��������� ������
	std::string GetPostfix() { return postfix; } // �������� ��������� ������
	void SetInfix(std::string _infix) { infix = _infix; } // �������� ������ � �������� ������

	TCalc(std::string _infix) :infix(_infix) { this->ToPostfix(); } // ����������� �� ���������
	double CalculateWithPostfix() {
		//this->ToPostfix();
		NumStack.ClerStack();

		for (int i = 0; i < postfix.length(); i++)
		{
			if ((postfix[i] >= '0') && (postfix[i] <= '9'))
			{
				NumStack.Push(postfix[i] - '0');
			}

			if ((postfix[i] == '+') || (postfix[i] == '-') || (postfix[i] == '*') || (postfix[i] == '/') || (postfix[i] == '^'))
			{
				double x1, x2, y;
				x1 = NumStack.Pop(); x2 = NumStack.Pop();
				switch (postfix[i])
				{
				case '+':
					y = x1 + x2;
					break;
				case '-':
					y = x2 - x1;
					break;
				case '*':
					y = x1 * x2;
					break;
				case '/':
					y = x1 / x2;
					break;
				case '^':
					y = pow(x1, x2);
					break;
				default:
					break;
				}
				NumStack.Push(y);
			}
		}

		double result = NumStack.Pop();
		if (!NumStack.empty())
		{
			throw "� TStack::Calculate �� ������ ���� ��� �������� result";
		}
		return result;
	}; // ����� ���������� c ����������� 
	double CalculateNoPostfix() {
		OpStack.ClerStack(); NumStack.ClerStack();
		std::string str = '(' + infix + ')';

		for (int i = 0; i < str.size(); i++)
		{
			int flag = 0;
			if (str[i] == '(')
			{   
				flag = 1;
				OpStack.Push('(');
			}

			if (str[i] == ')')
			{
				flag = 1;
				if (OpStack.empty())
				{
					throw "Stack Error";
				}
				char element = OpStack.Pop();
				while (element != '(')
				{
					double x2 = NumStack.Pop();
					double x1 = NumStack.Pop();
					double y;
					switch (element)
					{
					case '+':
						y = x1 + x2;
						break;
					case '-':
						y = x1 - x2;
						break;
					case '*':
						y = x1 * x2;
						break;
					case '/':
						y = x1 / x2;
						break;
					case '^':
						y = pow(x1, x2);
						break;
					default:
						break;
					}
					NumStack.Push(y);
					if (OpStack.empty())
					{
						throw "Stack Error";
					}
					element = OpStack.Pop();
				}
			}

			if ((str[i] >= '0') && (str[i] <= '9'))
			{
				flag = 1;
				size_t position;
				NumStack.Push(std::stod(&str[i], &position));
				i += (position - 1);
			}

			if ((str[i] == '+') || (str[i] == '-') || (str[i] == '*') || (str[i] == '/') || (str[i] == '^'))
			{
				flag = 1;
				if (OpStack.empty())
				{
					throw "Stack Error";
				}
				char OpStackElement = OpStack.Pop();
				while (priority(OpStackElement) >= priority(str[i]))
				{
					double x2 = NumStack.Pop();
					double x1 = NumStack.Pop();
					double y;
					switch (OpStackElement)
					{
					case '+':
						y = x1 + x2;
						break;
					case '-':
						y = x1 - x2;
						break;
					case '*':
						y = x1 * x2;
						break;
					case '/':
						y = x1 / x2;
						break;
					case '^':
						y = pow(x1, x2);
						break;
					default:
						break;
					}
					NumStack.Push(y);
					if (OpStack.empty())
					{
						throw "Stack Error";
					}
					OpStackElement = OpStack.Pop();
				}
				OpStack.Push(OpStackElement);
				OpStack.Push(str[i]);
			}

			if (flag == 0)
			{
				throw std::exception();
			}
		}

		double result = NumStack.Pop();
		if (!NumStack.empty())
		{
			throw "� TStack::Calculate �� ������ ���� ����� ��� �������� result";
		}
		if (!OpStack.empty())
		{
			throw "� TStack::Calculate �� ������ ���� �������� ��� �������� result";
		}
		return result;
	}; // ����� ���������� 

	
};

