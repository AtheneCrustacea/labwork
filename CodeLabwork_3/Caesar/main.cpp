#include <iostream>
#include <locale>
#include <stdio.h>
#include <string>
using namespace std;

string encrypt(string& text, const int key)//�㭪�� ����஢�� ⥪��
{
    for(unsigned int i = 0; i < text.size(); i++)
	for(int j = 0; j < key; j++) {
	    if(text[i] != '�')
		text[i] = text[i] + 1;
	    else
		text[i] = '�';
	}
    return text;
}

string decrypt(string& text, const int key)//�㭪�� ����஢�� ⥪��
{
    for(unsigned int i = 0; i < text.size(); i++)
		for(int j = 0; j < key; j++) {
			if(isalpha(text[i]))
				if(text[i] != '�')
					text[i] = text[i] - 1;
			else
					text[i] = '�';
		else {
			text = "������";
			goto error;
		}
	}
	error:
    return text;
}

string prepare(string& text)//�㭪�� �����⮢�� ⥪�� � ����஢��
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
    string a = "�ਢ��, ���!";
	string b = "�ਢ��, ���!";
    cout << a << endl;//�뢮� ⥪�� ��� �����⮢��
    cout << prepare(a) << endl;//�뢮� �����⮢������� ⥪��
    cout << encrypt(a, 7) << endl;//�뢮� ����஢������ ⥪��
    cout << decrypt(a, 7) << endl;//�뢮� ����஢������ ⥪��
	cout << b << endl;//�뢮� �������⮢������� ⥪��
	cout << decrypt(b, 7) << endl;//����⪠ ����஢�� ⥪� � �������⨬묨 ᨬ������
    return 0;
}
