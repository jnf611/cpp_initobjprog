#ifndef COMPLEXE_H
#define COMPLEXE_H

#include <string>
#include <iostream>

void log_func(const char* f);

class Complexe
{
public:
	// constructors
	Complexe(double x = 0.0, double y = 0.0) : _x(x), _y(y) { log_func("Complexe(r)"); };
	// there is no need to define a copy constructor, as the types in Complexe
	// are straighforward.
	// however we keep it, to track the copies in methods
	// here, delegating the construction, may not be the best choice because
	// there will be 2 functions call
	//Complexe(const Complexe& c) : Complexe(c._x, c._y) { log_func("Complexe(c)"); }
	Complexe(const Complexe& c) : _x(c._x), _y(c._y) { log_func("Complexe(c)"); }

	// getters
	double x() const { return _x; }
	double y() const { return _y; }
	
	// overload
	bool operator==(const Complexe& c) const;
	bool operator!=(const Complexe& c) const;
	Complexe operator-() const;
	Complexe& operator+=(const Complexe& c);
	// not needed, as it not explicit, it uses implicitely the double to
	// create a Complexe.
	//Complexe& operator+=(double r);
	Complexe operator+(const Complexe& c) const;
	Complexe& operator-=(const Complexe& c);
	Complexe operator-(const Complexe& c) const;
	Complexe& operator*=(const Complexe& c);
	//Complexe& operator*=(double r); // implicit use of constructor
	Complexe operator*(const Complexe& c) const;
	Complexe& operator/=(const Complexe& c);
	//Complexe& operator/=(double r); // implicit use of constructor
	Complexe operator/(const Complexe& c) const;
	
	// display
	const std::string to_string() const;

private:
	double _x;
	double _y;
};

// operator overload
// replaced by internal overload: this is not necessary, external overload is
// often advised
//Complexe operator+(Complexe c, const Complexe& d);
//not needed as the constructor is not explicit: it can construct a Complexe
//from a a double
//Complexe operator+(Complexe c, double r);
Complexe operator+(double r, const Complexe& c);
// replaced by internal overload
//Complexe operator-(Complexe c, const Complexe& d);
//Complexe operator-(Complexe c, double r); // using implicit constructor
Complexe operator-(double r, const Complexe& c);
// replaced by internal overload
//Complexe operator*(Complexe c, const Complexe& d);
//Complexe operator*(Complexe c, double r); // using implicit constructor
Complexe operator*(double r, const Complexe& c);
// replaced by internal overload
//Complexe operator/(Complexe c, const Complexe& d);
//Complexe operator/(Complexe c, double r); // using implicit constructor
Complexe operator/(double r, const Complexe& c);
std::ostream& operator<<(std::ostream& os, const Complexe& c);

#endif // COMPLEXE_H
