#include <stdio.h>
#include <iostream>
using namespace std;
int main(int argc, char** argv)
{
    int n, a = 1;
	bool b = 0;
    cout << "����� �᫮ ��� ���᪠: \n";
    cin >> n;
    while(a != 0) {
	cout << "������ �᫮: \n";
	cin >> a;
	if (a == n)
		b = 1;
    }
	if (b)
		cout << "�������\n";
	else 
		cout << "�� �������\n";
    return 0;
}
