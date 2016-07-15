/* s05e16 formes */
#include <iostream>
#include <string>
using namespace std;

class Forme
{
public:
	virtual void description() const { cout << "Ceci est une forme" << endl; }
	virtual double aire() const = 0;
};

class Cercle : public Forme
{
public:
	Cercle(double r) : rayon(r) {}
	virtual void description() const { cout << "Ceci est un cercle" << endl; }
	virtual double aire() const { return 3.14*rayon*rayon; }

private:
	double rayon;
};

class Triangle : public Forme
{
public:
	Triangle(double l, double h) : largeur(l), hauteur(h) {}
	virtual void description() const { cout << "Ceci est un triangle" << endl; }
	virtual double aire() const { return largeur*hauteur/2.0; }

private:
	double largeur;
	double hauteur;
};

void afficheDescription(Forme& f)
{
	f.description();
}

void afficheAire(Forme& f)
{
	cout << "Aire: " << f.aire() << endl;
}

int main()
{
	Cercle c(1.0);
	c.description();
	cout << "Aire du cercle: " << c.aire() << endl;

	Triangle t(2.0, 3.0);
	t.description();
	cout << "Aire du triangle: " << t.aire() << endl;

	// with the function
	afficheDescription(c);
	afficheAire(c);
	afficheDescription(t);
	afficheAire(t);

	return 0;
}
