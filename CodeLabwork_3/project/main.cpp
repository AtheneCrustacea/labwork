#include <iostream>
#include <string>
using namespace std;
wstring encrypt(const wstring text,const int key)
{
    wstring entext = text;
    unsigned int i = 0;
    while (i<entext.size())
    {
        if ((entext[i]>L'а') && (entext[i]<L'я'))
            entext[i]=entext[i]-32;
        i++;
    }
    i=0;
    while (i<entext.size())
    {
        if (!((entext[i]>L'А') && (entext[i]<L'Я')))
            entext.erase(i,1);
        i++;
    }
    for (i=0;i<entext.size();i++)
        for (int j = 0;j<key;j++)
            if (entext[i]!=L'Я')
                entext[i]++;
            else
                entext[i]=L'А';
    return entext;
}

int main()
{
    wstring a = L"Привет, мир!";
    wstring s = encrypt(a,7);
    wcout << s << endl;
    return 0;
}
