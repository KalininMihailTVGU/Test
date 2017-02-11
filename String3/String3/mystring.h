#ifndef STRING_H
#define STRING_H

class MyString
{
public:
    MyString(char * string);
    ~MyString();
    char * get() {return data;}
    int getLen() {return length;}
    void append(char * str);
    bool insert(int pos, char * str);
    char * substr(int start, int num);
    bool find(char * str);

private:
    char * data;
    int length;
};

#endif // STRING_H
