/* s03e10
* Polynomes
*/
#include "Polynome.hpp"
using namespace std;

string Polynome::to_string() const
{
	string s;

	for (size_t i = 0; i < p.size(); ++i)
	{
		if (p[i] == 0.0 && p.size() != 1)
			continue;
		
		string ns;
		if (i == 0) { ns = std::to_string(p[0]); }
		else
		{
			if      (p[i] ==  1.0) { ns =  "X";                        }
			else if (p[i] == -1.0) { ns = "-X";                        }
			else                   { ns = std::to_string(p[i]) + " X"; }
			
			if (i > 1) { ns += "^" + std::to_string(i); }
		}
		if (s.empty()) { s = ns;}
		else { s = ns + " + " + s; };
	}

	return s;
}

bool Polynome::operator==(Polynome const& q)
{
	return (p == q.p);
}

bool Polynome::operator!=(Polynome const& q)
{
	return !(*this == q);
}

void Polynome::simplify()
{
	while (p.back() == 0.0 && p.size() != 1)
	{
		p.pop_back();
	}
}

Polynome& Polynome::operator+=(Polynome const& q)
{
	while (degree() < q.degree())
	{
		p.push_back(0.0); // ensure there is enough space;
	}
	for (Degree i(0); i <= q.degree(); ++i)
	{
		p[i] += q.p[i];
	}
	simplify();
	
	return *this;
}

bool Polynome::isNull() const
{
	bool nullPolynome = true;
	
	for (Degree i(0); i <= degree(); ++i)
	{
		if (p[i] != 0)
		{
			nullPolynome = false;
			break;
		}
	}
	
	return nullPolynome;
}
#include <iostream>
using namespace std;
void Polynome::divide(const Polynome& q, Polynome& quotient, Polynome& rest)
{
	quotient = Polynome();
	rest = *this;
	int delta = (int)rest.degree() - (int)q.degree();
	while ( delta >= 0 && !rest.isNull())
	{
		double a = rest.top() / q.top();
		Polynome monome(a, (Degree)delta);
		quotient += monome;
		rest -= monome * q;
		delta = (int)rest.degree() - (int)q.degree();
	}
}

Polynome& Polynome::operator-=(Polynome const& q)
{
	while (degree() < q.degree())
	{
		p.push_back(0.0); // ensure there is enough space;
	}
	for (Degree i(0); i <= q.degree(); ++i)
	{
		p[i] -= q.p[i];
	}
	simplify();
	
	return *this;
}

Polynome& Polynome::operator*=(Polynome const& q)
{
	*this = *this * q;
	return *this;
}

Polynome& Polynome::operator*=(double x)
{
	for (Degree i(0); i <= this->degree(); ++i)
	{
		p[i] *= x;
	}
	simplify();
	
	return *this;
}

Polynome& Polynome::operator/=(Polynome const& q)
{
	Polynome quotient;
	Polynome rest;
	divide(q, quotient, rest);
	*this = quotient;
	return *this;
}

Polynome& Polynome::operator%=(Polynome const& q)
{
	Polynome quotient;
	Polynome rest;
	divide(q, quotient, rest);
	*this = rest;
	return *this;
}

const Polynome operator*(Polynome p, const Polynome& q)
{
	const Degree dp = p.degree();
	const Degree dq = q.degree();
	Polynome r(0.0, dp + dq);

	for (Degree i(0); i <= dp; ++i)
	{
		for (Degree j(0); j <= dq; ++j)
		{
			r.p[i+j] += p.p[i] * q.p[j];
		}
	}
	
	r.simplify();

	return r;
}

const Polynome operator*(double x, const Polynome& q)
{
	return Polynome(q) *= x;
}

const Polynome operator+(Polynome p, const Polynome& q)
{
	return p += q;
}

const Polynome operator-(Polynome p, const Polynome& q)
{
	return p -= q;
}

const Polynome operator/(Polynome p, const Polynome& q)
{
	return p /= q;
}

const Polynome operator%(Polynome p, const Polynome& q)
{
	return p %= q;
}

ostream& operator<<(ostream& os, const Polynome& p)
{
	return os << p.to_string();
}
