#include "stdafx.h"
#include <string.h>
#include <iostream>
#include <vector>

#include "mystring.h"

using namespace std;


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

bool MyString::find(char * str) {
    bool bRet = false;
    int iSubLen = strlen(str);
    int n=iSubLen+length+1;
    char * s=new char[n+1];
    strcpy_s(s,n+1,str);
    strcpy_s(s+iSubLen,2,"#");
    strcpy_s(s+iSubLen+1,length+1,data);
    puts(s);
    vector<int> pi (n);
    for (int i=1; i<n; ++i) {
        int j = pi[i-1];
        /*while ((j > 0) && (s[i] != s[j] || j==iSubLen || i==iSubLen))
            //j = pi[j-1];
			j=0;*/
        if (s[i] == s[j] && i!=iSubLen && j!=iSubLen)  ++j;
        pi[i] = j;
        if (j==iSubLen)
        {
            bRet = true;
            //break;
        }
    }
	for(int i1=0;i1<n;i1++)
	{
		printf("%i",pi[i1]);
	}
    delete[] s;
    return bRet;
}
