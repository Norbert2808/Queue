//При додаванні елемента вказується значення та приорітет елемента, він додається в чергу по прирітету.
//При видаленні елемента, видаляється той, в якого найбільший приорітет, якщо вони однакові тоді той, що додавався перший.
#include <string>
#include <iostream>
#include "Header.h"

using namespace std;

int main()
{
	Queue<int> base;
	base.push(5, 2);
	base.push(7, 1);
	base.push(3, 7);
	base.push(4, 5);
	base.push(10, 5);
	base.push(177, 5);
	base.print();
	base.pop();
	cout << base.top() << endl;
	system("pause");
	return 0;
}