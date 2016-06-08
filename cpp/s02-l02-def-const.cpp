#include <iostream>
using namespace std;

class Point
{
private:
	int x;
	int y;
public:
	void display() {cout << "x:" << x << ", y:" << y << endl;};
};

class Point2
{
private:
	int x;
	int y;
public:
	Point2(int x, int y) : x(x), y(y) {};
	Point2() : Point2(0, 0) {};
	void display() {cout << "x:" << x << ", y:" << y << endl;};
};

int main()
{
	Point p;
	p.display();

	int y;
	cout << "y:" << y << endl;

	Point2 p1(1, 2);
	p1.display();
	Point2 p2;
	p2.display();

	return 0;
}
