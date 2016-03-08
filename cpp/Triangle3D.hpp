#ifndef TRIANGLE_3D_H
#define TRIANGLE_3D_H

#include <iostream>
#include "Point3D.hpp"
using namespace std;

class Point3D;

class Triangle3D
{
public:
	void user_init()
	{
		for (int i = 0; i < 3; ++i)
		{
			cout << "Enter coordinates for point " << i << endl;
			_p[i].user_init();
		}
	}

	double perimeter()
	{
		double perimeter = 0.0;

		for (int i = 0; i < 3; ++i)
		{
			Point3D p1 = _p[i];
			Point3D p2 = _p[(i+1)%3];
			perimeter += dist(p1, p2);
		}

		return perimeter;
	}

	bool isocele()
	{
		double d2[3];
		for (int i = 0; i < 3; ++i)
		{
			Point3D p1 = _p[i];
			Point3D p2 = _p[(i+1)%3];
			d2[i] = square_dist(p1, p2);
		}

		bool isocele = (d2[0] == d2[1]) || (d2[1] == d2[2]) || (d2[2] == d2[0]);
		return isocele;
	}

private:
	Point3D _p[3];
};

#endif // #define TRIANGLE_3D_H
