#include <table.h>
using namespace std;
table::table (int inputKey){
	Key = inputKey;
    if (Key == 0){
        throw string("empty key.");
    }
}
string table::encrypt(const string &inputString){
    if (!inputString.length()){
        throw string("empty text.");
    }
	string outputString;
	int line = inputString.size()/Key;
	if ((inputString.size()%Key) != 0)
		line++;
	for (int j = Key; j > 0; j--)
		for (int i = 1; i <= line; i++)
		{
            if (Key*(i - 1) + j - 1 < inputString.size())
                outputString = outputString + inputString[Key * (i - 1) + j - 1];
		}
    return outputString;
}
string table::decrypt(const string &inputString){
    if (!inputString.length()){
        throw string("empty text.");
    }
    string res;
    char outputString [inputString.length()];
	int line = inputString.size()/Key, counter = 0;
	if ((inputString.size()%Key) != 0)
		line++;
	for (int j = Key; j > 0; j--)
		for (int i = 1; i <= line; i++)
		{
            if (Key*(i - 1) + j - 1 < inputString.size())
                {
					outputString[Key * (i - 1) + j - 1] = inputString[counter];
					counter++;
				}
		}
    for (int i = 0; i < inputString.length(); ++i) {
        res.push_back(outputString[i]);
    }
    return res;
}
