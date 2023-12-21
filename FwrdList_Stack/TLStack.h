#pragma once
#include<iostream>


template <class T>
struct TNode
{
	T value;
	TNode <T>* pNext;
};
template <class T>
class TLStack
{
	
TNode<T>* pFirst;

public:

	TLStack()
	{
		pFirst = nullptr;
	};                                                // ����������� �� ���������                                
	TLStack(const TLStack& StackObject);              // ����������� �����������
    TLStack<T>& operator = (const TLStack& object);   // �������� ������������
	bool full();                                      // ����� �������� ����� �� �������
	bool empty() { return pFirst == nullptr; }        // ����� �������� ����� �� �������        
	void ClerStack();                                 // ����� ������� �����
	T Pop();                                          // ����� ��������� ������� ����� (c � ������������)
	void Push(const T element);                       // ����� ���������� �������� � ����                  
	T Top();                                          // ����� ��������� �������� ������� �����
	int ElementsNumber();                             // ���������� ��������� � �����
	//void output();                                  // ����� ������ ����� �� �����                         
};

//���������� ������� ������ TStack

template <class T> 
TLStack<T>::TLStack(const TLStack& object)
{
	if (object.pFirst == nullptr)
	{
		pFirst = nullptr;
	}
	else
	{
		pFirst = new TNode<T>;
		pFirst->value = object.pFirst->value;
		TNode<T> *tmp = object.pFirst->pNext;
		TNode<T> *current = pFirst;
		while (tmp != nullptr)
		{
			current->pNext = new TNode<T>;
			current->pNext->value = tmp->value;
			current = current->pNext;
			tmp = tmp->pNext;
		}
	}
}

template<class T>
inline TLStack<T>& TLStack<T>::operator=(const TLStack& object)
{
	if (object.pFirst == nullptr)
	{
		pFirst = nullptr;
	}
	else
	{
		pFirst = new TNode<T>;
		pFirst->value = object.pFirst->value;
		TNode<T>* tmp = object.pFirst->pNext;
		TNode<T>* current = pFirst;
		while (tmp != nullptr)
		{
			current->pNext = new TNode<T>;
			current->pNext->value = tmp->value;
			current = current->pNext;
			tmp = tmp->pNext;
		}
	}
	return *this;
}

template<class T>
void TLStack<T>::Push(const T element)
{
	TNode <T>* tmp =  new TNode<T>;
	tmp->pNext = pFirst;
	tmp->value = element;
	pFirst = tmp;
}

template<class T>
inline void TLStack<T>::ClerStack()
{
	TNode <T>* tmp = pFirst;
	while (pFirst != nullptr)
	{
		pFirst = pFirst->pNext;
		delete tmp;
		tmp = pFirst;
	}
}

template<class T>
T TLStack<T>::Pop()
{
	if (empty())
	{
		throw std::exception();
	}	
	TNode<T>* p = pFirst;
	pFirst = pFirst->pNext;
	T result = p->value;
	delete p;
	return result;
}

template<class T>
T TLStack<T>::Top()
{
	if (empty())
	{
		throw std::exception();
	}
	return pFirst->value;
}

template<class T>
bool TLStack<T>::full()
{
	TNode<T>* p = new TNode<T>;
	if (p)
	{
		delete p;
		return true;
	}
	else
	{
		return false;
	}
}

template<class T>
int TLStack<T>::ElementsNumber()
{
	TNode<T>* p = pFirst;
	int i = 0;
	while (p != NULL)
	{
		i++;
		p = p->pNext;
	}
	return i;
}
