#ifndef POINT_3D_2_H
#define POINT_3D_2_H

/* Models a 3D point
 * s04e02 add constructor*/

#include <iostream>
#include <string>
#include <cmath> // for sqrt

class Point3D_2
{
public:
	Point3D_2(int x = 0.0, int y = 0.0, int z = 0.0) : x(x), y(y), z(z) {}

	static Point3D_2 userInit()
	{
		double x, y, z;

		std::cout << "x: ";
		std::cin >> x;
		std::cout << "y: ";
		std::cin >> y;
		std::cout << "z: ";
		std::cin >> z;

		return Point3D_2(x, y, y);
	}

	bool operator!=(const Point3D_2& p) const
	{
		return ((x != p.x) || (y != p.y) || (z != p.z));
	}

	bool operator==(const Point3D_2& p) const
	{
		return !(*this != p);
	}

	double square_dist(const Point3D_2& p) const
	{
		double dx = x - p.x;
		double dy = y - p.y;
		double dz = z - p.z;

		return dx*dx + dy*dy + dz*dz;
	}

	double dist(const Point3D_2& p) const
	{
		return sqrt(square_dist(p));
	}

	std::string to_string() const
	{
		return "(" + std::to_string(x) + "," + std::to_string(y) + ","
			+ std::to_string(z) + ")";
	}

	double x, y, z; // coordinates, set as public attribute for simplier use
	// but could remain private as all operation for now dont use them
};

std::ostream& operator<<(std::ostream& os, const Point3D_2& p)
{
	return os << p.to_string();
}

double square_dist(const Point3D_2& p1, const Point3D_2& p2)
{
	return p1.square_dist(p2);
}

double dist(const Point3D_2& p1, const Point3D_2& p2)
{
	return p1.square_dist(p2);
}

#endif // #define POINT_3D_2_H
