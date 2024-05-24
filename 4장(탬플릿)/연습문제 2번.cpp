#include <iostream>
using namespace std;

template <class T>
class Stack
{
private:
	T* temp;
	int count;
public:
	explicit Stack() : temp(NULL), count(0) {}
	~Stack()
	{
		delete[]temp;
	}
	void Push(T num)
	{
		if (temp == NULL)
		{
			temp = new T[10];
			temp[count++] = num;
		}
		else
		{
			temp[count++] = num;
		}
	}
	bool Empty()
	{
		return temp == NULL;
	}
	T Pop()
	{
		T thisTemp = temp[--count];
		temp[count] = NULL;
		return thisTemp;
	}
	void CheckError1()
	{
		for (int i = 0; i < count; i++)
		{
			cout << temp[i] << endl;
		}
	}
};

int main(void)
{
	Stack<int> st;

	st.Push(10);
	st.Push(20);
	st.Push(30);

	// st.CheckError1();

	if (!st.Empty())
		cout << st.Pop() << endl;
	if (!st.Empty())
		cout << st.Pop() << endl;
	if (!st.Empty())
		cout << st.Pop() << endl;

	return 0;
}