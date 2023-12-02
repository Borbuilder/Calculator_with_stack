#include "TCalc.h"
#include<iostream>
#include<string>
#include<math.h>


int TCalc::priority(char op) //Приоритет
{
	switch (op)
	{
	case '+' :
		return 1;
	case '-' :
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
}

void TCalc::ToPostfix() //Перевод в постфикс
{
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
}

double TCalc::CalculateWithPostfix() //Вычисление с постфиксом
{
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
				y = pow(x1,x2);
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
	    throw "В TStack::Calculate не пустой стек при возврате result";
	}
	return result;
}

double TCalc::CalculateNoPostfix() //Вычисление без постфикса
{
	OpStack.ClerStack(); NumStack.ClerStack();
	std::string str = '(' + infix + ')';

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
		{
			OpStack.Push('(');
		}

		if (str[i] == ')')
		{
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
				element = OpStack.Pop();
			}
		}

		if ((str[i] >= '0') && (str[i] <= '9'))
		{
			size_t position;
			NumStack.Push(std::stod(&str[i], &position));
			i += (position - 1);
		}

		if ((str[i] == '+') || (str[i] == '-') || (str[i] == '*') || (str[i] == '/') || (str[i] == '^'))
		{
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
				OpStackElement = OpStack.Pop();
			}
			OpStack.Push(OpStackElement);
			OpStack.Push(str[i]);
		}
	}

	double result = NumStack.Pop();
	if (!NumStack.empty())
	{
		throw "В TStack::Calculate не пустой стек чисел при возврате result";
	}
	if (!OpStack.empty())
	{
		throw "В TStack::Calculate не пустой стек операций при возврате result";
	}
	return result;
}
