#pragma once
#include <string>
using namespace std;
class table
{
private:
	int Key;
public:
	table (int inputKey);
	string encrypt(const string &inputString);
	string decrypt(const string &inputString);
};
