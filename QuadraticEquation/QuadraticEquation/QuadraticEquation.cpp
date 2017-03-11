// QuadraticEquation.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	double a, b, c;
	double D;
	cout << "Enter a,b,c for ax^2+bx+c: ";
	cin >> a >> b >> c;
	//cout << a << " " << b << " " << c << endl;
	printf("%g\t%g\t%g\n",a,b,c);
	D = b*b-4*a*c;
	printf("main20\t%g\n",D);
	//cout << D << endl;
	//cout << (D > 0) << endl;
	if (D < 0) cout << "No real roots.";
	else if (0 == D) cout << "x = " << -b/(2*a);
	else if (D > 0)
		{
			//printf("main50\t%g\t%g\n",D,sqrt(D));
			//cout << "x1 = " << (-b-sqrt(D)) << "\nx2 = " << (-b+sqrt(D));
			cout << "x1 = " << (-b-sqrt(D))/(2*a) << "\nx2 = " << (-b+sqrt(D))/(2*a);
	}
	cout << "main90" << endl;

	_getch();

	return 0;
}

