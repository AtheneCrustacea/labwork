#include <iostream>
using namespace std;
class String
{
    char* value;
    int len;

public:
    String() //конструктор по умолчанию
        : value(new char[1]{})
        , len(0)
    {
        cout << "The default constructor works...\n";
    };
    String(const String& s)
    { //конструктор копирования
        len = s.len;
        value = new char[len + 1];
        for(int i = 0; i < len + 1; i++)
            value[i] = s.value[i];
        cout << "Copy constructor works...\n";
    }
    friend ostream& operator<<(ostream& outputStream, const String& s) // конструктор вывода
    {
        cout << "Output constructor works...\n";
        return outputStream << s.value;
    }
    friend istream& operator>>(istream& inputStream, String& s) 
    {
        cout << "Input constructor works...\n";
        cin >> s.len;
        delete[] s.value;
        char* value = new char[s.len + 1];
        for(int i = 0; i < s.len; i++)
            cin >> value[i];
    }
    String(const char * s)
    {
        len = 0;
        while (s[len] != '\0') ++len;
        value = new char[len + 1];
        for (int i = 0; i <= len; i++)
            value[i] = s[i];
    };

    ~String() 
    {
        cout << "Destructor works..." << value << len << endl;
        delete[] value;
    }
};
int main(int argc, char **argv) 
{
    String s;
    String s1();
    String s2 = s;
    return 0;
}