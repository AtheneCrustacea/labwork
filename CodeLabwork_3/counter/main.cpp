#include <iostream>
#include <stdio.h>
using namespace std;
int main(int argc, char** argv)
{
    setlocale(LC_CTYPE, ".866");
    int alpha = 0, digit = 0, mark = 0;
    string s,
        p[8] = {"deb http://mirror.mephi.ru/debian/ stretch main contrib non-free\n",
	    "deb-src http://mirror.mephi.ru/debian/ stretch main contrib non-free\n",
	    "deb http://security.debian.org/ stretch/updates main contrib non-free\n",
	    "deb-src http://security.debian.org/ stretch/updates main contrib non-free\n",
	    "deb http://mirror.mephi.ru/debian/ stretch-updates main contrib non-free\n",
	    "deb-src http://mirror.mephi.ru/debian/ stretch-updates main contrib non-free\n",
	    "deb http://mirror.mephi.ru/debian stretch-backports main contrib non-free\n",
	    "deb-src http://mirror.mephi.ru/debian stretch-backports main contrib non-free\n" };
    for(int i = 0; i < 8; i++) {
	s = p[i];

	for(unsigned int j = 0; j < s.size(); j++) {
	    if(s[j] == ' ') {
		
		continue;
	    }
	    if(s[j] == '\n') {
		
		continue;
	    }
	    if(isalpha(s[j]))
		alpha++;
	    else if(isdigit(s[j]))
		digit++;
	    else 
		mark++;
		}
    }

    cout << "Количество букв: " << alpha << endl;
    cout << "Количество цифр: " << digit << endl;
    cout << "Количество знаков препинания: " << mark << endl;
    cout << "Всего символов: " << mark + alpha + digit << endl;
    return 0;
}
