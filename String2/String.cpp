// String.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "String.h"


int String::getLength()
{
	return length;
}

char *String::getData()
{
	return data;
}

String::String(char *sData)
{
	length = strlen(sData)+1;
	data = new char[length];
	strcpy(data, sData);
}

String::~String()
{
	if (0 != data)
	{
		delete[] data;
	}
}

void String::append(String str)
{
	int iNewLen = length+str.getLength();
	char *buffer = new char[iNewLen];
	strcpy(buffer,data);
	strcat(buffer,str.getData());
	delete[] data;
	data = new char[iNewLen];
	strcpy(data, buffer);
	delete[] buffer;
	length = iNewLen;
}


