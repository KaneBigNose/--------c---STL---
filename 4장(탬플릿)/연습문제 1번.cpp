#include <iostream>
using namespace std;

template <class T>
void Copy(T& des, T& sou, int num)
{
	for (int cut = 0; cut < num; cut++)
	{
		des[cut] = sou[cut];
		cout << des[cut] << " ";
	}
	cout << endl << endl;
}

template <class T>
class MyType
{
private:
	T arr;
public:
	MyType() : arr(NULL) {}
	MyType(T arr) : arr(arr) {}
	friend ostream& operator<<(ostream& os, MyType& my);
};

ostream& operator<<(ostream& os, MyType<double>& my)
{
	cout << my.arr;
	return os;
}

int main(void)
{
	int arr1[5] = { 10,20,30,40,50 };
	int arr2[5];
	Copy(arr2, arr1, 5);

	MyType<double> myArr1[3] = {1.1,2.2,3.3};
	MyType<double> myArr2[3];
	Copy(myArr2, myArr1, 3);

	return 0;
}