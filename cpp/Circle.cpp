/* 
 * Circle.cpp
 */
#include <cmath> 
#include <sstream>
#include "Point.hpp"
#include "Circle.hpp"
using namespace std;

void Circle::setRadius(double r)
{ 
	if (r < 0)
	{
		r = 0;
	}
	
	_r = r;
}

double Circle::surface() const
{
	return M_PI*_r*_r;
}

bool Circle::inside(const Point& p) const
{
	bool inside = false;
	double dx = p.x() - _p.x();
	double dy = p.y() - _p.x();
		
	if ((dx*dx + dy*dy) <= _r*_r) // test is done on distance's square
	{
		inside = true;
	}
	
	return inside;
}

const string Circle::to_string() const
{
	return _p.to_string() + ", r = " + std::to_string(_r);
}

const string Circle::to_string_cpp03() const
{
	ostringstream oss;
	oss << _p.to_string() + ", r=" << _r;
	return oss.str();
}

ostream& operator<<(ostream& o, const Circle& c)
{
	return o << c.to_string();
}
