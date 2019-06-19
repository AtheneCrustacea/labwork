#include <stdio.h>
#include <iostream>
using namespace std;
int main(int argc, char** argv)
{
    int n, a = 1;
	bool b = 0;
    cout << "Ввеите число для поиска: \n";
    cin >> n;
    while(a != 0) {
	cout << "Введите число: \n";
	cin >> a;
	if (a == n)
		b = 1;
    }
	if (b)
		cout << "Найдено\n";
	else 
		cout << "Не найдено\n";
    return 0;
}
