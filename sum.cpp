#include <iostream>
#include <stdio.h>
using namespace std;
int main(int argc, char** argv)
{
    int sum, a = 1;
    while(a != 0) {
    cout << "������ �᫮: \n";
	cin >> a;
	if (a>0)
		sum += a;
	}
	cout << "�㬬� ������⥫��� �ᥫ ��᫥����⥫쭮��: " << sum << endl;
    return 0;
}
