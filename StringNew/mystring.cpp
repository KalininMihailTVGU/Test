#include "stdafx.h"
#include <string.h>
#include "mystring.h"


MyString::MyString(char * str)
{
    length = strlen(str);
    data = new char[length+1];
    strcpy_s(data, length+1, str);
}

MyString::~MyString()
{
    delete[] data;
}

void MyString::append(char * str)
{
    if (NULL == str) return;

    int iNewLen = strlen(str);
    length += iNewLen;
    char * buf = new char[length+1];
    strcpy_s(buf, length+1, data);
    strcat_s(buf, length+1, str);
    delete[] data;
    data = buf;
}

char * MyString::substr(int start, int num)
{
    if ((length < start+num) ||
            (0 >= start) ||
            (0 >= num))
        return NULL;

    char * buf = new char[num+1];
    data[start+num-1] = 0;
    strcpy_s(buf, num+1, data+(start-1));
    length = num;
    delete[] data;
    data = buf;
    return data;
}

bool MyString::insert(int pos, char * str)
{
    int iNewLen = strlen(str);
    if ((length < pos) ||
            (0 >= pos) ||
            (NULL == str))
        return false;

    length += iNewLen;
    char * buf = new char[length+1];
    strcpy_s(buf, length+1, data);
    strcpy_s(buf+(pos-1), length+1-(pos-1), str);
    strcpy_s(buf+(pos-1)+iNewLen, length+1-(pos-1)-iNewLen, data+(pos-1));
    delete[] data;
    data = buf;
    return true;
}

bool MyString::find(char * str)
{
    return true;
}
