#include <iostream>
#include <locale>
#include <stdio.h>
#include <string>
using namespace std;

string encrypt(string& text, const int key)//Функция зашифровки текста
{
    for(unsigned int i = 0; i < text.size(); i++)
	for(int j = 0; j < key; j++) {
	    if(text[i] != 'Я')
		text[i] = text[i] + 1;
	    else
		text[i] = 'А';
	}
    return text;
}

string decrypt(string& text, const int key)//Функция дешифровки текста
{
    for(unsigned int i = 0; i < text.size(); i++)
		for(int j = 0; j < key; j++) {
			if(isalpha(text[i]))
				if(text[i] != 'А')
					text[i] = text[i] - 1;
			else
					text[i] = 'Я';
		else {
			text = "ОШИБКА";
			goto error;
		}
	}
	error:
    return text;
}

string prepare(string& text)//Функция подготовки текста к зашифровке
{
    int i = 0;
    while(text[i] != 0) {
	if(!(isalpha(text[i]))) {
	    text.erase(i, 1);
	    i--;
	} else
	    text[i] = toupper(text[i]);
	i++;
    }
    return text;
}

int main()
{
    setlocale(LC_CTYPE, ".866");
    string a = "Привет, мир!";
	string b = "Привет, мир!";
    cout << a << endl;//Вывод текста для подготовки
    cout << prepare(a) << endl;//Вывод подготовленного текста
    cout << encrypt(a, 7) << endl;//Вывод зашифрованного текста
    cout << decrypt(a, 7) << endl;//Вывод расшифрованного текста
	cout << b << endl;//Вывод неподготовленного текста
	cout << decrypt(b, 7) << endl;//Попытка расшифровки текта с недопустимыми символами
    return 0;
}
