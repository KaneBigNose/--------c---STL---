#include <iostream>
using namespace std;

template <class T>
class Queue
{
private:
	T* temp;
	int count;
public:
	explicit Queue() : temp(NULL), count(0) {}
	~Queue()
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
		T thistemp = temp[0];
		for (int i = 0; i <= count; i++)
		{
			temp[i] = temp[i + 1];
		}
		temp[count--] = NULL;
		return thistemp;
	}
	void Print()
	{
		for (int i = 0; i < count; i++)
		{
			cout << temp[i];
		}
	}
};

int main(void)
{
	Queue<int> q;

	q.Push(10);
	q.Push(20);
	q.Push(30);

	if (!q.Empty())
		cout << q.Pop() << endl;
	if (!q.Empty())
		cout << q.Pop() << endl;
	if (!q.Empty())
		cout << q.Pop() << endl;

	q.Print();

	return 0;
}