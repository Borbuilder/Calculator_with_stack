#include "TLStack.h"
#include <iostream>

int main()
{
	TLStack<int> a;
	a.Push(1);
	a.Push(2);
	int i = a.Pop();
	std::cout << a.Top();
	//a.Pop();
	TLStack<int> b;
	b = a;
	std::cout << b.Pop();
}