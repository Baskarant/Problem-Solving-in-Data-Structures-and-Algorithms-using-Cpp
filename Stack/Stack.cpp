#include "stdafx.h"
#include "Stack.h"
#include <exception>

int main()
{
	Stack s(10);
	for (int i = 1; i <= 100; i++)
	{
		s.gPush(i);
	}
	for (int i = 1; i <= 100; i++)
	{
		s.gPop();
	}
	s.print();
	return 0;
}

Stack::Stack() : Stack(MIN_CAPACITY)
{
}

Stack::Stack(int MaxCapacity)
{
	data = new int[MaxCapacity];
	capacity = MaxCapacity;
}

Stack::~Stack()
{
	delete[] data;
}

int Stack::size()
{
	return (stack_top + 1);
}

bool Stack::isEmpty()
{
	return (stack_top == -1);
}

void Stack::push(int value)
{
	if (size() == capacity)
	{
		throw std::exception("StackOvarflowException");
	}
	stack_top++;
	data[stack_top] = value;
}

int Stack::top()
{
	if (isEmpty())
	{
		throw std::exception("StackEmptyException");
	}
	return data[stack_top];
}

int Stack::pop()
{
	if (isEmpty())
	{
		throw std::exception("StackEmptyException");
	}
	int topVal = data[stack_top];
	stack_top--;
	return topVal;
}

void Stack::print()
{
	for (int i = stack_top; i > -1; i--)
	{
		std::cout << " " << data[i];
	}
}

void Stack::gPush(int value)
{
	if (size() == capacity)
	{
		int *delMe = data;
		capacity = 2 * capacity;
		data = new int[capacity];
		for (int i = stack_top; i > -1; i--)
		{
			data[i] = delMe[i];
		}
		delete[] delMe;
		std::cout << "stack size doubled" << std::endl;
		//throw std::exception("StackOvarflowException");
	}
	stack_top++;
	data[stack_top] = value;
}

int Stack::gPop()
{
	if (isEmpty())
	{
		throw std::exception("StackEmptyException");
	}

	int topVal = data[stack_top];
	stack_top--;
	if (stack_top < capacity / 2 && stack_top > MIN_CAPACITY)
	{
		capacity = capacity / 2;
		int *delMe = data;
		data = new int[capacity];
		for (int i = stack_top; i > -1; i--)
		{
			data[i] = delMe[i];
		}
		std::cout << "stack size reduced" << std::endl;
	}
	return topVal;
}