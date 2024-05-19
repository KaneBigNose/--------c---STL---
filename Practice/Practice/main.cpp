#include <iostream>
#include <cstring>
using namespace std;

class Equal
{
public:
	explicit Equal() {}
	bool operator()(int a, int b)
	{
		return a == b;
	}
};

class Adder
{
public:
	explicit Adder() {}
	int operator() (int a, int b)
	{
		return a + b;
	}
};

int main(void)
{
	Equal cmp;
	if (cmp(10, 20))
		cout << "같다!" << endl;
	else
		cout << "다르다!" << endl;

	Adder add;
	int sum = add(10, 20);
	cout << "sum = " << sum << endl;
}