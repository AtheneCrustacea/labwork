#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int a;
    cout << "������ ������⢮ ��࡫�: ";
    cin >> a;
    if((a < 0) || (a > 100)) {
	cout << "�訡��. ����୮� ������⢮ ��࡫�.\n";
	return 0;
    }
    string x = "��࡫�";
    string y = "��";
    if(((a % 10) > 4) || ((a > 10) && (a < 15))) {
	x = x + "��";
	y = y + "�";
    } else if(a % 10 > 1) {
	x = x + "�";
	y = y + "�";
    }
    cout << "� ��ࠢ��� " << y << " " << a << " " << x << "." << endl;
    return 0;
}
