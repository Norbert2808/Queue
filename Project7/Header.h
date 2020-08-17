#pragma once
#include <iostream>
using namespace std;

template<typename P>
class PriorEll
{
private:
	unsigned prior;
	P value;
public:
	PriorEll(P b = P(), unsigned a = 0) : value(b), prior(a)  {}
	friend ostream &operator <<(ostream &out, const PriorEll &a)
	{
		out << a.value << '(' << a.prior << ')';
		return out;
	}
	PriorEll& operator=(const PriorEll &a)
	{
		value = a.value;
		prior = a.prior;
		return *this;
	}
	unsigned getPrior()
	{
		return prior;
	}
	P getValue()
	{
		return value;
	}
};

template<typename T>
class Queue
{
private:
	PriorEll<T>* mas;
	T Top;
	int size;
	int busy;
public:

	Queue()
	{
		busy = 0;
		Top = T();
		size = 2;
		mas = new PriorEll<T>[size];
	}

	T top()
	{
		return Top;
	}

	int getSize()
	{
		return size;
	}

	void push(T value, unsigned prior)
	{
		PriorEll<T> insert(value, prior);
		if (busy == size)
		{
			size *= 2;
			PriorEll<T> *newMas = new PriorEll<T>[size];
			for (int i = 0; i < size / 2; i++)
			{
				newMas[i] = mas[i];
			}
			delete[]mas;
			mas = newMas;
		}
		cout << "Queue push: " << value << " priority: " << prior << '\n';
		busy++;
		if (busy == 1)
		{
			Top = value;
		}
		PriorEll<T> *newMas2 = new PriorEll<T>[busy];
		int counter = 0;
		for (int i = 0; i < busy - 1; i++)
		{
			if (mas[i].getPrior() < insert.getPrior())
			{
				newMas2[i] = mas[i];
				counter++;
			}
			else
			{
				newMas2[i + 1] = mas[i];
			}
		}
		newMas2[counter] = insert;
		Top = newMas2[busy - 1].getValue();
		delete[]mas;
		mas = newMas2;
	}

	void pop()
	{
		if (!isEmpty())
		{
			cout << "-------- Queue pop --------\n";
			busy--;
			PriorEll <T> *newMas = new PriorEll <T>[busy];
			for (int i = 0; i < busy; i++)
			{
				newMas[i] = mas[i];
			}
			Top = newMas[busy - 1].getValue();
			delete[]mas;
			mas = newMas;
		}
		else  cout << "Is Empty...\n";

	}

	void print()
	{
		cout << "Queue print:" << endl;
		for (int i = 0; i < busy; i++)
		{
			cout << mas[i] << ' ';
		}
		cout << '\n';
	}

	bool isEmpty()
	{
		return busy == 0;
	}

	~Queue()
	{
		delete[] mas;
	}
};
