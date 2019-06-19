#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char **argv)
{
	double sum = 0; 
	int n = 0;
	ifstream file ("/home/IBST/18pi116/Labwork_5/FileFloat/1.txt");
	double a;
	if (file.is_open())
		while (file >> a)
		{
			sum += a;
			n++;
		}
	else 
		{
			cout <<"Файл не существует.\n";
			return 0;
		}
	cout << "Среднее арифметическое чисел: " << sum/n <<endl;
	return 0;
}
