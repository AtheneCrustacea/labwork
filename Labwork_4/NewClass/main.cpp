#include <iostream>
using namespace std;

class String
{
private:
    char* value;
    int len;

public:
    String()
        : value(new char[1]{})
        , len(0){};
    String(const String& s)
    {
	len = s.len;
	value = new char[len + 1];
	for(int i = 0; i <= len; i++)
	    value[i] = s.value[i];
    };
    String(const char* s)
    {
	len = 0;
	while(s[len] != '\0')
	    ++len;
	value = new char[len + 1];
	for(int i = 0; i <= len; i++)
	    value[i] = s[i];
    };
    ~String()
    {
	delete[] value;
    };
    friend istream& operator>>(istream& is, String& obj)
    {
	int ios_size = 0, i = 0;
	char v[2048];
	while(is.peek() != '\n')
	    v[ios_size++] = (char)is.get();
	v[ios_size] = '\0';
	is.ignore();
	delete[] obj.value;
	obj.value = new char[ios_size + 1];
	for(i = 0; i <= ios_size; i++)
	    obj.value[i] = v[i];
	obj.len = ios_size;
	return is;
    }
    friend ostream& operator<<(ostream& outputStream, const String& s) // конструктор вывода
    {
	return outputStream << s.value;
    }
    String operator=(String other)
    {
	if(this != &other) {
	    delete[] value;
	    len = other.len;
	    value = new char[len + 1];
	    for(int i = 0; i <= len; i++) {
		value[i] = other.value[i];
	    }
	}
	return *this;
    }

    String operator-()
    {
	String ret;
	ret.len = len;
	delete[] ret.value;
	ret.value = new char[len + 1];
	for(int i = 0; i < len; i++) {
	    ret.value[i] = value[len - i - 1];
	}
	ret.value[len] = 0;
	return ret;
    }
    String operator+(const String& other)
    {
	String ret;
	delete[] ret.value;
	ret.len = len + other.len;
	ret.value = new char[ret.len + 1]{};
	for(int i = 0; i < len; i++)
	    ret.value[i] = value[i];
	for(int i = 0; i + len < ret.len; i++) {
	    ret.value[i + len] = other.value[i];
	}
	return ret;
    }
};
int main(int argc, char** argv)
{
    String s;
    String s3("hello");
	s = s3.operator -();
    cout << s << endl;
    return 0;
}