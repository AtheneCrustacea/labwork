#include <fstream>
#include <iostream>
using namespace std;
int main()
{
    ifstream iz("D:\\binfiles\\data_v13.bin", ios::in | ios::binary);
    ofstream v("D:\\binfiles\\tyt.bin", ios::out | ios::binary);
    iz.seekg(0, ios::end);
    const int izsize = iz.tellg();
    iz.seekg(0, ios::beg);
    double* buf = new double[izsize];
    float* var = new float[izsize];
    for(int i = 0; i < izsize; i++)
	iz.read((char*)&buf[i], sizeof(double));
    for(int i = 0; i < izsize; i++)
	var[i] = 1 / buf[i];
    for(int i = 0; i < izsize; i++)
	v.write((char*)&var, sizeof(float));
    iz.close();
    v.close();
    delete[] buf;
    delete[] var;
    return 0;
}