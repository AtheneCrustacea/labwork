#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int a;
    cout << "Введите количество верблюдов: ";
    cin >> a;
    if((a < 0) || (a > 100)) {
	cout << "Ошибка. Неверное количество верблюдов.\n";
	return 0;
    }
    string x = "верблюд";
    string y = "был";
    if(((a % 10) > 4) || ((a > 10) && (a < 15))) {
	x = x + "ов";
	y = y + "о";
    } else if(a % 10 > 1) {
	x = x + "а";
	y = y + "о";
    }
    cout << "В караване " << y << " " << a << " " << x << "." << endl;
    return 0;
}
