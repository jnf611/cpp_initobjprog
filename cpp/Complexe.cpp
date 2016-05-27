#include "Complexe.hpp"
using namespace std;

#define FUNC() log_func(__func__)

void log_func(const char* f)
{
	std::cout << " --" << f << "-- ";
}

bool Complexe::operator==(const Complexe& c) const
{
	FUNC();
	return (_x == c._x) && (_y == c._y);
}

bool Complexe::operator!=(const Complexe& c) const
{
	FUNC();
	return !(*this == c);
}

Complexe Complexe::operator-() const
{
	FUNC();
	Complexe c(*this);
	c._x = -c._x;
	c._y = -c._y;
	return c;
}

Complexe& Complexe::operator+=(const Complexe& c)
{
	log_func("Complexe::operator+=(const Complexe& c)");
	_x += c._x;
	_y += c._y;
	return *this;
}

Complexe Complexe::operator+(const Complexe& c) const
{
	log_func("Complexe::operator+(const Complexe& c)");
	return Complexe(*this) += c;
}

Complexe& Complexe::operator-=(const Complexe& c)
{
	log_func("Complexe::operator-=(const Complexe& c)");
	return *this += -c;
}

Complexe Complexe::operator-(const Complexe& c) const
{
	log_func("Complexe::operator-(const Complexe& c)");
	return Complexe(*this) -= c;
}

Complexe& Complexe::operator*=(const Complexe& c)
{
	log_func("Complexe::operator*=(const Complexe& c)");
	double prev_x = _x;
	_x = _x*c._x - _y*c._y;
	_y = prev_x*c._y + _y*c._x;
	return *this;
}

Complexe Complexe::operator*(const Complexe& c) const
{
	log_func("Complexe::operator*(const Complexe& c)");
	return Complexe(*this) *= c;
}

Complexe& Complexe::operator/=(const Complexe& c)
{
	log_func("Complexe::operator/=(const Complexe& c)");
	double den = c._x*c._x + c._y*c._y;
	double prev_x = _x;
	_x = (_x*c._x + _y*c._y) / den;
	_y = (_y*c._x - prev_x*c._y) / den;
	return *this;
}

Complexe Complexe::operator/(const Complexe& c) const
{
	log_func("Complexe::operator/=(const Complexe& c)");
	return Complexe(*this) /= c;
}

const std::string Complexe::to_string() const
{
	string s;

	if (_x == 0.0 && _y == 0.0)
	{
		s = std::to_string(0);
	}
	else
	{
		if (_x != 0.0)
		{
			s = std::to_string(_x);
		}

		if (_y != 0.0)
		{
			string cs;
			if (_y == 1.0)       { cs = "i"; }
			else if (_y == -1.0) { cs = "-i"; }
			else                 { cs = std::to_string(_y) + "i"; }

			if (s.empty())     { s = cs; }
			else if (_y > 0.0) { s += " + " + cs; }
			else               { s += " - " + cs; }
		}
	}

	return s;
}

Complexe operator+(double r, const Complexe& c)
{
	log_func("operator+(double r, Complexe c)");
	return Complexe(r) + c;
}

Complexe operator-(double r, const Complexe&  c)
{
	return Complexe(r) - r;
}

Complexe operator*(double r, const Complexe&  c)
{
	return Complexe(r) * r;
}

Complexe operator/(double r, const Complexe&  c)
{
	return Complexe(r) / r;
}

std::ostream& operator<<(std::ostream& os, const Complexe& c)
{
	return os << c.to_string();
}
