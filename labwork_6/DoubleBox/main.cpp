#include <iostream>
using namespace std;
template <typename T1,typename T2> class DoubleBox
{
private:
	T1 first = T1();
	T2 second = T2();
public:
	DoubleBox() {};
	DoubleBox(const T1 one, const T2 two):first(one),second(two) {};
	void set(const T1 one, const T2 two) {
		first = one;
		second = two;
	}
	void get(T1 &one, T2 &two) {
		one = first;
		two = second;
	}
};
int main(int argc, char **argv)
{
	int e1;
	double e2;
	DoubleBox <double,int> test(2.7,3);
	test.get(e2,e1);
	cout << e1 << "   " << e2 << endl;
	DoubleBox <int,double> example;
	example.set(3,3.14);
	example.get(e1,e2);
	cout << e1 << "   " << e2 << endl;
	return 0;
}
