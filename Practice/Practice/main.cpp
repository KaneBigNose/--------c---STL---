#include <iostream>
#include <cstring>
using namespace std;

class String
{
private:
	char* temp;
public:
	explicit String(const char* trash)
	{
		int len = strlen(trash) + 1;
		temp = new char[len];
		strcpy_s(temp, len, trash);
	}
	~String()
	{
		//delete[]temp;  4번 문제에 필요
	}
	operator const char* () const
	{
		cout << "const char* 형 operator호출!" << endl;
		return temp;
	}
	String& operator=(const char* trash)
	{
		if (temp != NULL)
			delete[]temp;
		int len = strlen(trash) + 1;
		temp = new char[len];
		strcpy_s(temp, len, trash);
		return *this;
	}
	friend ostream& operator<<(ostream& os, const String sr);
};

ostream& operator<<(ostream& os, String sr)
{
	cout << sr.temp << endl;
	return os;
}

int main()
{
	/* String s("Hello!");
	const char* sz = s;            4번문제
	cout << sz << endl; */

	const char* sz = "Hello!";    //5번문제
	String s("Hi~!");
	s = sz;
	cout << s << endl;
}