#include <iostream>
using namespace std;
template <typename T> T sort (T *arr, int len)
{
	T temp;
	for (int i = 0; i < len-1;i++ )
	{
		for (int j = 0; j < len-i-1;j++)
		{
			if (arr[j]>arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}
int main(int argc, char **argv)
{
	int int_arr[6]  = {5,7,23,13,45,9};
	sort(int_arr,6);
	for (int i = 0;i<6;i++)
		cout << int_arr[i]<< " ";
	cout << endl;
	double double_arr[8] = {0.15,4.58,1.25,4.75,5.68,6.73,7.41,8.25};
	sort(double_arr,6);
	for (int i = 0;i<6;i++)
		cout << double_arr[i]<< " ";
	cout << endl;
	return 0;
}
