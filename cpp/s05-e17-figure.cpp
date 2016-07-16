/* s05e16 formes */
#include <iostream>
#include <string>
#include <vector>
#include <memory> // for unique_ptr
using namespace std;

#define LOG_FUNC() cout << __PRETTY_FUNCTION__ << endl

class Figure
{
public:
	virtual ~Figure() {}
	virtual void affiche() const = 0;
	virtual Figure* copie() const = 0;
};

class Cercle : public Figure
{
public:
	Cercle(double r = 0.0) : rayon(r) { LOG_FUNC(); }
	Cercle(const Cercle& c) : rayon(c.rayon) { LOG_FUNC(); }
	~Cercle() { LOG_FUNC(); }

	virtual void affiche() const
	{
		LOG_FUNC();
		cout << "Ceci est un cercle de rayon: " << rayon << endl;
	}

	virtual Figure* copie() const
	{
		LOG_FUNC();
		/*Figure* c = new Cercle(*this);
		return c;*/ // can be written on one line
		return new Cercle(*this);
	}

private:
	double rayon;
};

class Triangle : public Figure
{
public:
	Triangle(double l = 0.0, double h = 0.0) :
		largeur(l), hauteur(h)
	{
		LOG_FUNC();
	}
	Triangle(const Triangle& t) :
		largeur(t.largeur), hauteur(t.hauteur)
	{
		LOG_FUNC();
	}
	~Triangle() { LOG_FUNC(); }

	virtual void affiche() const
	{
		LOG_FUNC();
		cout << "Ceci est un triangle de largeur: " << largeur
			<< " est de hauteur: " << hauteur << endl;
	}

	virtual Figure* copie() const
	{
		LOG_FUNC();
		/*Figure* t = new Triangle(*this);
		return t;*/ // can be written on one line
		return new Triangle(*this);
	}

private:
	double largeur;
	double hauteur;
};

class Carre : public Figure
{
public:
	Carre(double c = 0.0) : cote(c) { LOG_FUNC(); }
	Carre(const Carre& c) : cote(c.cote) { LOG_FUNC(); }
	~Carre() { LOG_FUNC(); }

	virtual void affiche() const
	{
		LOG_FUNC();
		cout << "Ceci est un carré de coté: " << cote << endl;
	}

	virtual Figure* copie() const
	{
		LOG_FUNC();
		/*Figure* c = new Carre(*this);
		return c;*/ // can be written on one line
		return new Carre(*this);
	}

private:
	double cote;
};

class Dessin
{
public:
	Dessin() { LOG_FUNC(); }
	Dessin(const Dessin& d)
	{
		for (size_t i = 0; i < d.figures.size(); ++i)
		{
			figures.push_back(d.figures[i]->copie());
		}
	}
	~Dessin()
	{
		LOG_FUNC();
		for(size_t i = 0; i < figures.size(); ++i)
		{
			delete figures[i];
		}
	}

	void ajoute_figure(const Figure& f)
	{
		figures.push_back(f.copie());
	}
	void affiche()
	{
		for(size_t i = 0; i < figures.size(); ++i)
		{
			Figure* f = figures[i];
			f->affiche();
		}
	}

private:
	vector<Figure*> figures;
};

void unCercleDePlus(Dessin const& img)
{
	Dessin tmp(img);
	tmp.ajoute_figure(Cercle(1));
	cout << "Affichage de 'tmp': " << endl;
	tmp.affiche();
}

class Dessin2
{
public:
	Dessin2() { LOG_FUNC(); }
	Dessin2(const Dessin2& d)
	{
		for (auto& f : d.figures)
		{
			figures.push_back(unique_ptr<Figure>(f->copie()));
		}
	}
	~Dessin2() { LOG_FUNC(); }

	void ajoute_figure(const Figure& f)
	{
		figures.push_back(unique_ptr<Figure>(f.copie()));
	}
	void affiche()
	{
		for (auto& f : figures)
		{
			f->affiche();
		}
	}

private:
	vector<unique_ptr<Figure>> figures;
};

void unCercleDePlus(Dessin2 const& img)
{
	Dessin2 tmp(img);
	tmp.ajoute_figure(Cercle(1));
	cout << "Affichage de 'tmp': " << endl;
	tmp.affiche();
}

int main()
{
	Cercle c(1.0);
	Triangle t(2.0, 3.0);
	Carre ca(2.0);

	Dessin dessin;
	dessin.ajoute_figure(t);
	dessin.ajoute_figure(c);
	dessin.ajoute_figure(Triangle(5.0, 1.0));
	dessin.ajoute_figure(ca);

	dessin.affiche();

	unCercleDePlus(dessin);

	// with unique_ptr
	Dessin2 dessin2;
	dessin2.ajoute_figure(t);
	dessin2.ajoute_figure(c);
	dessin2.ajoute_figure(Triangle(5.0, 1.0));
	dessin2.ajoute_figure(ca);

	dessin2.affiche();

	unCercleDePlus(dessin2);

	return 0;
}
