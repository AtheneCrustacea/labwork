#include <iostream>
#include <stdio.h>
using namespace std;
int main(int argc, char** argv)
{
    int sum, a = 1;
    while(a != 0) {
    cout << "Введите число: \n";
	cin >> a;
	if (a>0)
		sum += a;
	}
	cout << "Сумма положительных чисел последовательности: " << sum << endl;
    return 0;
}
