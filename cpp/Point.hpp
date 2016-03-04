#ifndef POINT_H
#define POINT_H
/* 
 * Point.hpp
 * Model a point
 */

class Point
{
private:
	double _x;
	double _y;

public:
	Point()                   { _x = 0.0; _y = 0.0;};
	Point(double x, double y) { _x = x;   _y = y;};
	double x() const { return _x;};
	double y() const { return _y;};
};

#endif //#define POINT_H
