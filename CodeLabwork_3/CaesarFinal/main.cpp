#include <iostream>
#include <string>
using namespace std;
string prepare(const string& text)//�㭪�� �����⮢�� ⥪�� � ����஢��
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
string encrypt(const string& text, const int key)//�㭪�� ����஢�� ⥪��
{
	string entext = prepare(text);
    for(unsigned int i = 0; i < entext.size(); i++)
	for(int j = 0; j < key; j++) {
	    if(entext[i] != '�')
		entext[i] = entext[i] + 1;
	    else
		entext[i] = '�';
	}
    return entext;
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


int main()
{
    setlocale(LC_CTYPE, ".866");
	const string text = "�ਢ��, ���";
	string entext;
	entext = encrypt(text,7);
	cout << entext << endl;
	return 0;
}
