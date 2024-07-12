#include <iostream>
#include <cmath>
using namespace std;

class Point
{
private:
	int x, y, r;
public:
	Point(int x = 0, int y = 0, int r = 0) : x(x), y(y), r(r) {}
	bool operator==(Point p)
	{
		if (x == p.x && y == p.y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator!=(Point p)
	{
		if (x == p.x && y == p.y)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	int distance(Point p) const
	{
		return pow(abs(x - p.x), 2) + pow(abs(y - p.y), 2); // 거리의 제곱
	}
};

int main()
{
	int test;
	cin >> test;
	int x1, y1, r1, x2, y2, r2;
	for (int i = 0; i < test; i++)
	{
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		Point p1(x1, y1, r1), p2(x2, y2, r2);
		int powR = pow(r1 + r2, 2);
		if (p1 != p2 && p1.distance(p2) < powR) // 접점이 2개인 경우
		{
			cout << "2" << endl;
		}
		else if (p1 != p2 && p1.distance(p2) == powR) // 접점이 1개인 경우 (외접)
		{
			cout << "1" << endl;
		}
		else if (p1 != p2 && pow(r1, 2) == p1.distance(p2) + pow(r2, 2)) // 접점이 1개인 경우 (내접)
		{
			cout << "1" << endl;
		}
		else if (p1 != p2 && p1.distance(p2) > powR) // 접점이 0개인 경우 (외부)
		{
			cout << "0" << endl;
		}
		else if (p1 != p2 && pow(r1, 2) > p1.distance(p2) + pow(r2, 2)) // 접점이 0개인 경우 (내부, 중심이 다른 경우)
		{
			cout << "0" << endl;
		}
		else if (p1 == p2 && r1 != r2) // 접점이 0개인 경우 (내부, 중심이 같은 경우)
		{
			cout << "0" << endl;
		}
		else if (p1 == p2 && r1 == r2) // 접점이 무한인 경우
		{
			cout << "-1" << endl;
		}
		else
		{
			cout << "예외 발생!" << endl;
		}
	}
}