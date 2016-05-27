#ifndef CIRCLE_H
#define CIRCLE_H
/* 
 * Circle.hpp
 * Model a circle figure
 */

#include <string>
#include <ostream>
#include "Point.hpp"
 
// class Point; // the forward declaration would be enough only if used with
// pointers and references.

class Circle
{
private:
	Point _p; // circle center
	double _r; // radius

public:
	// getters, setters
	Point getCenter() const        { return _p;};
	void setCenter(const Point& p) { _p = p;};
	double getRadius() const       { return _r;};
	void setRadius(double r);
	// other features
	double surface() const;
	bool inside(const Point& p) const;
	const std::string to_string() const; // should this string returned as const ?
	const std::string to_string_cpp03() const;
};

std::ostream& operator<<(std::ostream& o, const Circle& c);

#endif //ifndef CIRCLE_H
