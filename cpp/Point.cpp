#include "Point.hpp"

const std::string Point::to_string() const
{
	return "(" + std::to_string(_x) + "," + std::to_string(_y) + ")";
}

std::ostream& operator<<(std::ostream& os, const Point& p)
{
	os << p.to_string();
	return os;
}
