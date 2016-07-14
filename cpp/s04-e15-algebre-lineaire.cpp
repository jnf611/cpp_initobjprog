/* s04e15 ensemble, groupe, anneau, corps*/

#include <iostream>
using namespace std;

// Ensemble des nombre positifs de 0 à p [exclu]
class EnsembleFini
{
public:
	EnsembleFini(unsigned int p = 1) : p(p)
	{
		if (p == 0)
			p = 1;
	}

protected:
	unsigned int p;
};

// Groupe : ensemble avec une addition (loi de composition interne, associative,
// avec un element neutre, et un symetrique
class Groupe : public EnsembleFini
{
public:
	Groupe(unsigned int p = 1) : EnsembleFini(p) {}

	// element neutre: 0
	unsigned int add(unsigned int a, unsigned int b) { return (a + b) % p; }
};

// Anneau : Groupe avec un multiplication (loi de composition interne,
// associative, avec un element neutre, et distributive par rapport à la loi
// de groupe
class Anneau : public Groupe
{
public:
	Anneau(unsigned int p = 1) : Groupe(p) {}

	// element neutre 1
	unsigned int mult(unsigned int a, unsigned int b) { return (a*b) % p; }
};

// Corps : 2e loi est aussi une loi de groupe (à un inverse)
class Corps : Anneau
{
public:
	Corps(unsigned int p = 1) : Anneau(p) {}

	// element neutre 1
	unsigned int inv(unsigned int a)
	{
		if (a > 0)
		{
			int b(p), q, r, u(0), new_u, prev_u(1);
			while (b != 1)
			{
				q = a/b;
				r = a%b;
				a = b;
				b = r;
				new_u = prev_u - q * u;
				prev_u = u;
				u = new_u;
			}
			return (u + p)%p;
		}
		else
		{
			return 0;
		}
	}

	unsigned int div(unsigned int a, unsigned int b) { return mult(a, inv(b)); }
};

int main()
{
	Groupe groupe(6);
	cout << "groupe.add(4, 3) = " << groupe.add(4, 3) << endl;
	cout << "groupe.add(3, 4) = " << groupe.add(3, 4) << endl;
	cout << "groupe.add(4, 0) = " << groupe.add(4, 0) << endl;
	cout << "groupe.add(4, 2) = " << groupe.add(4, 2) << endl;

	Anneau anneau(6);
	cout << "anneau.add(4, 3) = " << anneau.add(4, 3) << endl;
	cout << "anneau.add(3, 4) = " << anneau.add(3, 4) << endl;
	cout << "anneau.add(4, 0) = " << anneau.add(4, 0) << endl;
	cout << "anneau.add(4, 2) = " << anneau.add(4, 2) << endl;
	cout << "anneau.mult(4, 3) = " << anneau.mult(4, 3) << endl;
	cout << "anneau.mult(3, 4) = " << anneau.mult(3, 4) << endl;
	cout << "anneau.mult(4, 1) = " << anneau.mult(4, 1)	<< endl;
	cout << "anneau.mult(anneau.add(2, 4), 3) = "
		<< anneau.mult(anneau.add(2, 4), 3) << endl;
	cout << "anneau.add(anneau.mult(2, 3), anneau.add(4, 3)) = "
		<< anneau.add(anneau.mult(2, 3), anneau.add(4, 3)) << endl;

	Corps corps(7); // only Z/pZ where p are prime are corps
	for (int i = 1; i < 7; ++i)
	{
		cout << "inv(" << i << ") = " << corps.inv(i) << endl;
	}

	return 0;
}
