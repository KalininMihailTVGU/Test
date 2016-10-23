// Queue.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "Queue.h"
 
using namespace std;

int main()
{
	int b;
	queue a(1); // Создает очередь и загружает в очередь 1
	a.append(2); // Загружает 2
	a.append(3); // Загружает 3
	a.extract(&b); // В b выгружается 1
	a.extract(&b);  // В b выгружается 2
 
	cout<<b<<endl; // На экран выведется 2
	system("pause");
 
	return 0;
}

