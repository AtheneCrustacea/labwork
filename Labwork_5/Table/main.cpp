#include <iostream>
#include <iomanip>
using namespace std;
void table (int s)
{
	if (8 == s)
		cout << oct;
	else if (16 == s)
		cout << hex;
	else if (10 == s)
		cout << dec;
	else {
		wcerr << L"Ошибка: неверная система счисления.\n";
		return;
	}
	for (int i = 1; i < s+1; i++) {
		cout << endl;
		for (int j = 1; j < s+1; j++)
			cout <<setw(4) <<i*j;
	}
	cout << endl;
}
int main(int argc, char **argv)
{
	setlocale(LC_ALL,"Russian");
	int osn;
	wcout << L"Введите основание системы счисления: ";
	cin >> osn;
	table(osn);
	return 0;
}
