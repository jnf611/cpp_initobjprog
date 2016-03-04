/* 
 * Circle.cpp
 */
#include <cmath> 
#include "Point.hpp"
#include "Circle.hpp"

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
