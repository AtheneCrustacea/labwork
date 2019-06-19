#include <fstream>
#include <iostream>
using namespace std;
int main()
{
    ifstream ipfile;
    ipfile.open ("D:\\binfiles\\2.txt");
    ofstream opfile;
    opfile.open ("D:\\binfiles\\1.txt", ios::app);
    if (!((ipfile.is_open())||(opfile.is_open())))
        cerr << "Wrong path!" << endl;
    long long length;
    ipfile.seekg (0,ipfile.end);
    length = ipfile.tellg();
    ipfile.seekg(0,ipfile.beg);
    char * tmp = new char [length];
    ipfile.read(tmp,length);
    opfile << tmp;
    return 0;
}
