#ifndef POINT_3D_H
#define POINT_3D_H

/* Models a 3D point*/

#include <iostream>
#include <cmath> // for sqrt

class Point3D
{
public:
	void init(int _x, int _y, int _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}

	void user_init()
	{
		std::cout << "x: ";
		std::cin >> x;
		std::cout << "y: ";
		std::cin >> y;
		std::cout << "z: ";
		std::cin >> z;
	}

	bool compare(const Point3D& p) const
	{
		bool identique = ((x == p.x) && (y == p.y) && (z == p.z));

		return identique;
	}

	void print() const
	{
		std::cout << "(" << x << "," << y << "," << z << ")" << std::endl;
	}

	double x, y, z; // coordinates, set as public attribute for simplier use
};

double square_dist(const Point3D& p1, const Point3D& p2)
{
	double dx = p1.x - p2.x;
	double dy = p1.y - p2.y;
	double dz = p1.z - p2.z;

	return dx*dx + dy*dy + dz*dz;
}

double dist(const Point3D& p1, const Point3D& p2)
{
	return sqrt(square_dist(p1, p2));
}

#endif // #define POINT_3D_H
