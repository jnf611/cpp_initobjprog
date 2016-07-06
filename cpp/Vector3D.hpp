#ifndef VECTOR_3D_H
#define VECTOR_3D_H
#include <iostream>
#include <cmath>
#include <string>
#include "Point3D_2.hpp"

class Vector3D : public Point3D_2
{
public:
	Vector3D(double x = 0.0, double y = 0.0, double z = 0.0) :
		Point3D_2(x, y, z)
	{}

	std::string to_string() const { return Point3D_2::to_string(); }

	// addition, soustraction, opposé
	Vector3D& operator+=(const Vector3D& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}
	Vector3D operator-() const
	{
		return Vector3D(-x, -y, -z);
	}
	Vector3D& operator-=(const Vector3D& v)
	{
		return (*this += -v);
	}

	// multiplication par un scalaire
	Vector3D& operator*=(double c)
	{
		x *= c;
		y *= c;
		z *= c;
		return *this;
	}
	Vector3D& operator/=(double c)
	{
		if (c > 0.0)
		{
			x /= c;
			y /= c;
			z /= c;
		}
		return *this;
	}

	double norm() const;

	bool operator!() const
	{
		return (x == 0.0) && (y == 0.0) && (z == 0.0);
	}

protected:
	static const Vector3D null;
};

const Vector3D Vector3D::null;

Vector3D operator+(Vector3D u, const Vector3D& v)
{
	return u += v;
}

Vector3D operator-(Vector3D u, const Vector3D& v)
{
	return u += -v;
}

// multiplication par un scalaire
Vector3D operator*(double c, Vector3D v)
{
	return v *= c;
}

Vector3D operator*(Vector3D v, double c)
{
	return c * v;
}

Vector3D operator/(double c, Vector3D v)
{
	return v /= c;
}

// produit scalaire
// this is possible as we admitted that the member of Point3D_2 are public:
// if they were protected, internal overload would be preferable
double operator*(const Vector3D& u, const Vector3D& v)
{
	return u.x*v.x + u.y*v.y + u.z*v.z;
}

double Vector3D::norm() const
{
	return (Vector3D(*this) * Vector3D(*this));
}

double angle(const Vector3D& u, const Vector3D& v)
{
	return acos((u * v) / (u.norm() * v.norm()));
}

// affichage
std::ostream& operator<<(std::ostream& os, const Vector3D& v)
{
	return os << v.to_string();
}

#endif // VECTOR_3D_H
