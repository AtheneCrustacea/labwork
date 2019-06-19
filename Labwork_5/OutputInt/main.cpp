#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char **argv)
{
	const int n = 10;
	int ar[n];
	cout << "Введите " << n << " чисел:";
	for (int i = 0; i < n; i++)
		cin >> ar[i];
	for (int i = 0; i < n; i++)
	{
		cout << setw(12) << oct << ar[i];
		cout << setw(12) << dec << ar[i] ;
		cout << setw(12) << hex << ar[i] << endl;
	}
}