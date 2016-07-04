/* s04e01 figures
Le but de cet exercice est d'illustrer la notion d'héritage en utilisant une
hiérarchie de figures géométriques.
Dans le fichier figures.cc, commencez par définir des classes Rectangle  et
Cercle. Munissez-les d'attributs adaptés et d'une méthode surface.
 * */
#include <iostream>
#include <string>
#include <cmath> // for pi
using namespace std;

class Point
{
public:
	Point(double x = 0.0, double y = 0.0) : _x(x), _y(y) {}

	std::string to_string() const
	{
		return "(" + std::to_string(_x) + ", " + std::to_string(_y) + ")";
	}

private:
	double _x;
	double _y;
};

ostream& operator<<(ostream& os, Point& p)
{
	return os << p.to_string();
}

enum e_color
{
	black,
	blue,
	green,
	yellow,
	red
};

class Figure
{
public:
	Figure() {};
	Figure(Point& origin) : _origin(origin) {}
	virtual double surface() const = 0;
	virtual std::string to_string() const // it can be defined and eventually specialized
	{
		return _origin.to_string();
	};

protected:
	Point _origin;
};

ostream& operator<<(ostream& os, Figure& f)
{
	return os << f.to_string();
}

class ColoredElement
{
public:
	ColoredElement(e_color color = black) : _color(color) {};

	std::string to_string() const
	{
		switch(_color)
		{
		case black:  return "black";
		case yellow: return "yellow";
		case blue:   return "blue";
		case green:  return "green";
		case red:    return "red";
		default:     return "unknown color";
		}
	}

protected:
	e_color _color;
};

class Rectangle : public Figure
{
public:
	Rectangle() {}
	Rectangle(Point& origin, double width = 0.0, double height = 0.0) :
		Figure(origin), _width(width), _height(height)
	{
		if (_width < 0.0)
			_width = 0.0;
		if (_height < 0.0)
			_height = 0.0;
	}

	double surface() const { return _width*_height; }

	std::string to_string() const
	{
		return "(" + Figure::to_string() + ", " + std::to_string(_width) + ", "
			+ std::to_string(_height) + ")";
	}

private:
	double _width;
	double _height;
};

ostream& operator<<(ostream& os, Rectangle& r)
{
	return os << r.to_string();
}

class ColoredRectangle : public Rectangle, public ColoredElement
{
public:
	ColoredRectangle() {}
	ColoredRectangle(Point& origin, double width = 0.0, double height = 0.0,
		e_color color = black) :
		Rectangle(origin, width, height), ColoredElement(color) {};

	std::string to_string() const
	{
		return Rectangle::to_string() + " " + ColoredElement::to_string();
	}
};

ostream& operator<<(ostream& os, ColoredRectangle& r)
{
	return os << r.to_string();
}

class Circle : public Figure
{
public:
	Circle() {}
	Circle(Point& origin, double radius = 0.0) :
		Figure(origin), _radius(radius)
	{
		if (_radius < 0.0)
		{
			_radius = 0.0;
		}
	}

	double surface() const { return M_PI*_radius*_radius; };

	std::string to_string() const
	{
		return "(" + Figure::to_string() + ", " + std::to_string(_radius) + ")";
	}

private:
	double _radius;
};

ostream& operator<<(ostream& os, Circle& c)
{
	return os << c.to_string();
}

int main()
{
	Point p1;
	Point p2(5.0);
	Point p3(5.0, 3.0);

	cout
		<< "p1 : " << p1 << endl
		<< "p2 : " << p2 << endl
		<< "p3 : " << p3 << endl;

	Rectangle r1;
	Rectangle r2(p1);
	Rectangle r3(p2, 2.0);
	Rectangle r4(p3, 2.0, 8.0);

	cout
		<< "r1 : " << r1 << endl
		<< "r2 : " << r2 << endl
		<< "r3 : " << r3 << endl
		<< "r4 : " << r4 << endl;

	Circle c1;
	Circle c2(p1);
	Circle c3(p2, 4.0);

	cout
		<< "c1 : " << c1 << endl
		<< "c2 : " << c2 << endl
		<< "c3 : " << c3 << endl;

	ColoredRectangle rc(p3, 2.0, 8.0, black);
	cout << "rc : " << rc << endl;

	return 0;
}
