#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>


/*#define forn(i,n) for(int i=0;i<n;i++)

using namespace std;

string s2,s1;
// функция возвращает массив с количеством совпавших символов
vector<int> prefix_function (string s) {
    int n = (int) s.length();

    vector<int> pi (n);
    for (int i=1; i<n; ++i) {
        int j = pi[i-1];

        while ((j > 0) && (s[i] != s[j] || j==s2.size() || i==s2.size()))
            j = pi[j-1];
        if (s[i] == s[j] && i!=s2.size() && j!=s2.size())  ++j;
        pi[i] = j;
    }
    return pi;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    s2 = "aba";
    s1 = "ababacaba";
    s1=s2+'#'+s1;
    cout << s1 << endl;

    vector<int> p=prefix_function (s1);

    forn(i,p.size()){
        if(p[i]==s2.size()){
            cout<<i-2*s2.size()+1<<" "<<p[i]<<endl;
        } else {
            //cout<<p[i]<<" wrong"<<endl;
        }
    }

    return a.exec();
}*/

#include "mystring.h"

/*using namespace std;

char * data="ababacabc";
int length = strlen(data);
bool find(char * s2) {
    bool bRet = false;
    int iSubLen = strlen(s2);
    int n=iSubLen+length+1;
    char * s=new char[n+1];
    strcpy_s(s,n+1,s2);
    strcpy_s(s+iSubLen,2,"#");
    strcpy_s(s+iSubLen+1,length+1,data);
    puts(s);

    vector<int> pi (n);
    for (int i=1; i<n; ++i) {
        int j = pi[i-1];
        while ((j > 0) && (s[i] != s[j] || j==iSubLen || i==iSubLen))
            j = pi[j-1];
        if (s[i] == s[j] && i!=iSubLen && j!=iSubLen)  ++j;
        pi[i] = j;
        if (j==iSubLen)
        {
            bRet = true;
            break;
        }
    }
    delete[] s;
    return bRet;
}*/

int main(int argc, char *argv[])
{

    MyString str("ababacaba");
    printf("ini\t'%s'\t%i\t\n",str.get(),str.getLen());

    char sStr[]="aba";
    if (str.find(sStr))
        printf("\nfind\t'%s'\ttrue\n",sStr);
    else
        printf("\nfind\t'%s'\tfalse\n",sStr);

    /*str.append(" s5");
    printf("append\t'%s'\t%i\n",str.get(),str.getLen());

    if (str.insert(3, " s2"))
        printf("insert\t'%s'\t%i\n",str.get(),str.getLen());

    if (str.insert(6, " s3"))
        printf("insert\t'%s'\t%i\n",str.get(),str.getLen());

    if (NULL != str.substr(5, 3))
        printf("substr\t'%s'\t%i\n",str.get(),str.getLen());

    if (NULL != str.substr(1, 2))
        printf("substr\t'%s'\t%i\n",str.get(),str.getLen());*/
}
