#ifndef CIRCLE_H
#define CIRCLE_H
/* 
 * Circle.hpp
 * Model a circle figure
 */
 
class Point;

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
};

#endif //ifndef CIRCLE_H
