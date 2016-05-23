#ifndef POLYNOME_H
#define POLYNOME_H

#include <vector>
#include <string>
#include <ostream>

typedef size_t Degree;

class Polynome
{
public:
	// constructor
	Polynome(double a = 0.0, Degree n = 0) : p(n) { p.push_back(a); }
	
	// other
	// this condition (c.size() > 0) should be ensured, 
	// actual degree of nul polynome is -Inf
	Degree degree() const { return p.size()-1; }
	bool isNull() const;
	double top() const { return p.back(); }
	
	// operator overload
	bool operator==(Polynome const& q);
	bool operator!=(Polynome const& q);
	Polynome& operator*=(Polynome const& q);
	Polynome& operator*=(double x);
	Polynome& operator+=(Polynome const& q);
	Polynome& operator-=(Polynome const& q);
	Polynome& operator/=(Polynome const& q);
	Polynome& operator%=(Polynome const& q);
	friend const Polynome operator*(Polynome p, const Polynome& q);
	
	// display
	std::string to_string() const;

private:
	// remove null coefficients (exept the last one, in case of null polynome)
	void simplify();
	void divide(const Polynome& q, Polynome& quotient, Polynome& rest);
	std::vector<double> p;
};

// operator overload
std::ostream& operator<<(std::ostream& os, const Polynome& p);
const Polynome operator*(Polynome p, const Polynome& q);
const Polynome operator*(double x, const Polynome& q);
const Polynome operator+(Polynome p, const Polynome& q);
const Polynome operator-(Polynome p, const Polynome& q);
const Polynome operator/(Polynome p, const Polynome& q);
const Polynome operator%(Polynome p, const Polynome& q);

#endif //#define POLYNOME_H
