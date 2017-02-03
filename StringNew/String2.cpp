// String2.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include "stdafx.h"
#include "string.h"

int main(int argc, char* argv[])
{
	// создаём объект
	String str("begin");
	puts(str.getData());

	// добавляем строку
	str.append("end");
	puts(str.getData());

	return 0;
}

