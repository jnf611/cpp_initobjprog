#ifndef VECTOR_3D_H
#define VECTOR_3D_H
#include <iostream>
#include <cmath>
#include <string>
#include "Point3D_2.hpp"

class Vector3D : public Point3D_2
{
public:
	// force declaration of all parameters (or use an additionnal default const
	// for the null vector
	Vector3D(double x, double y, double z) :
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
	const Vector3D operator-() const // the return result is a const
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

	virtual double norm() const;

	bool operator!() const
	{
		return (x == 0.0) && (y == 0.0) && (z == 0.0);
	}

protected:
	static const Vector3D null;
};

const Vector3D Vector3D::null(0.0, 0.0, 0.0);

const Vector3D operator+(Vector3D u, const Vector3D& v) // const return
{
	return u += v;
}

const Vector3D operator-(Vector3D u, const Vector3D& v) // const return
{
	return u += -v;
}

// multiplication par un scalaire
const Vector3D operator*(double c, Vector3D v) // const return
{
	return v *= c;
}

const Vector3D operator*(Vector3D v, double c) // const return
{
	return c * v;
}

const Vector3D operator/(double c, Vector3D v) // const return
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
	return sqrt((*this) * (*this));
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

const Vector3D nullVector3D(0.0, 0.0, 0.0);

class UnitVector3D : public Vector3D
{
public:
	UnitVector3D();
	UnitVector3D(double x, double y, double z);
	explicit UnitVector3D(const Vector3D& v);
	virtual double norm();
	//overload
	UnitVector3D& operator+=(const UnitVector3D& v);
	UnitVector3D& operator-=(const UnitVector3D& v);
	UnitVector3D& operator*=(double c);

private:
	void normalize();
};

UnitVector3D::UnitVector3D() :
	Vector3D(1.0, 0.0, 0.0) // choix par defaut pour assurer un vecteur non nul
{}

UnitVector3D::UnitVector3D(double x, double y, double z) :
	Vector3D(x, y, z)
{
	normalize();
}

// Plusieurs fois lors qu'une opération modifie le caractère unitaire d'un
// vecteur unitaire:
// - arrêter l'exécution (assert)
// - afficher un message d'erreur
// - empecher l'exécution en la rendant private (casse le caractère "est un" ?)
// - forcer la normalisation
// - lever une exception

UnitVector3D::UnitVector3D(const Vector3D& v) :
	UnitVector3D(v.x, v.y, v.z)
{}

double UnitVector3D::norm()
{
	return 1.0;
}

void UnitVector3D::normalize()
{
	double n = Vector3D::norm();
	if (n > 0.0)
	{
		this->Vector3D::operator*=(1/n);
	}
	else
	{
		*this = UnitVector3D();
	}
}

UnitVector3D& UnitVector3D::operator+=(const UnitVector3D& v)
{
	Vector3D::operator+=(v);
	normalize();
	return *this;
}

UnitVector3D& UnitVector3D::operator-=(const UnitVector3D& v)
{
	Vector3D::operator+=(v);
	normalize();
	return *this;
}

// multiplication par un scalaire , ne fait rien
UnitVector3D& UnitVector3D::operator*=(double c)
{
	Vector3D::operator*=(c);
	normalize();
	return *this;
}

double angle(const UnitVector3D& u, const UnitVector3D& v)
{
	return acos(u * v);
}

#endif // VECTOR_3D_H
