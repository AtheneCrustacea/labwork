#include <iostream>
#include <string>
using namespace std;
string prepare(const string& text)//Функция подготовки текста к зашифровке
{
	string preptext=text;
    int i = 0;
    while(text[i] != 0) {
	if(!(isalpha(preptext[i]))) {
	    preptext.erase(i, 1);
	    i--;
	} else
	    preptext[i] = toupper(preptext[i]);
	i++;
    }
    return preptext;
}
string encrypt(const string& text, const int key)//Функция зашифровки текста
{
	string entext = prepare(text);
    for(unsigned int i = 0; i < entext.size(); i++)
	for(int j = 0; j < key; j++) {
	    if(entext[i] != 'Я')
		entext[i] = entext[i] + 1;
	    else
		entext[i] = 'А';
	}
    return entext;
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


int main()
{
    setlocale(LC_CTYPE, ".866");
	const string text = "Привет, мир";
	string entext;
	entext = encrypt(text,7);
	cout << entext << endl;
	return 0;
}
