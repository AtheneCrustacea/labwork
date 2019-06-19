#include <stdio.h>
#include <iostream>
using namespace std;
int main(int argc, char **argv)
{
    string p[8]={
	"deb http://mirror.mephi.ru/debian/ stretch main contrib non-free\n",
    "deb-src http://mirror.mephi.ru/debian/ stretch main contrib non-free\n",
    "deb http://security.debian.org/ stretch/updates main contrib non-free\n",
    "deb-src http://security.debian.org/ stretch/updates main contrib non-free\n",
    "deb http://mirror.mephi.ru/debian/ stretch-updates main contrib non-free\n",
    "deb-src http://mirror.mephi.ru/debian/ stretch-updates main contrib non-free\n",
    "deb http://mirror.mephi.ru/debian stretch-backports main contrib non-free\n",
    "deb-src http://mirror.mephi.ru/debian stretch-backports main contrib non-free\n"
    };
    int a;
    for (int i=0;i<8;i++)
    {
        a=0;
        a=p[i].find("mephi");
        if (a>0)
            p[i].replace(a,5,"yandex");
        cout << p[i];
    }
	return 0;
}
