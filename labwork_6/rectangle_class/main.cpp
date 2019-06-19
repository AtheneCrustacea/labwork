#include <iostream>
using namespace std;
template <typename T> void sort (T *arr, int len)
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

template <typename T> class Rectangle
{
private:
	T h = T(); //высота
	T w = T(); //ширина
public:
	Rectangle() {};
	Rectangle(const T height,const T width):h(height),w(width) {};
	bool operator>(const Rectangle sth)
	{
		return (h*w>sth.h*sth.w);
	}
};
int main(int argc, char **argv)
{
	Rectangle<int> first(8,19);
	Rectangle<int> second(5,7);
	Rectangle<int> rec[2] = {first,second};
	sort(rec,2);
	return 0;
}
