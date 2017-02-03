#include "stdafx.h"
#include "mystring.h"
#include <conio.h>


int main(int argc, char *argv[])
{

    MyString str("s1 s4");
    printf("ini\t|%s|%i|\n",str.get(),str.getLen());

    str.append(" s5");
    printf("append\t|%s|%i|\n",str.get(),str.getLen());

    if (str.insert(3, " s2"))
        printf("insert\t|%s|%i|\n",str.get(),str.getLen());

    if (str.insert(6, " s3"))
        printf("insert\t|%s|%i|\n",str.get(),str.getLen());

    if (NULL != str.substr(5, 3))
        printf("substr\t|%s|%i|\n",str.get(),str.getLen());

    if (NULL != str.substr(1, 2))
        printf("substr\t|%s|%i|\n",str.get(),str.getLen());
	_getch();
}
