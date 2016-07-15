#include <iostream>
#include <string>
using namespace std;

class Personnage
{
public:
	Personnage(const string& nom, int point_vie = 10, int force = 1) :
		nom(nom), point_vie(point_vie), force(force)
	{}
	void attaquer(Personnage& p)
	{
		cout << __PRETTY_FUNCTION__ << ": " << nom << " attaque " << p.nom << endl;
		p.point_vie -= force;
	}
	// defined as virtual, to be redefined latter
	virtual void faiblir(int point)
	{
		point_vie -= point;
		if (point_vie < 0)
			point_vie = 0;
		cout << __PRETTY_FUNCTION__ << ": " << getNom() << " faiblit de " << point << ", il reste " << point_vie << endl;
	}
	const string getNom() { return nom; }

private:
	const string nom;
protected:
	int point_vie;
	int force;
};

class Magicien : public Personnage
{
public:
	Magicien(const string& nom, int point_vie = 10, int force = 1,
		int mana = 10) :
		Personnage(nom, point_vie, force), mana(mana)
	{}

	void attaquer(Personnage& p)
	{
		cout << __PRETTY_FUNCTION__ << ": " << getNom() << " attaque " << p.getNom() << endl;
		//p.point_vie -= force 	// Forbidden
		p.faiblir(force); 		// point_vie is a SuperClass member
								// even if protected, Magicien instance can only access its own point_vie
								// but he can't access other::point_vie
								// --> the access should be done through a SuperClass method
								// that can eventually be redefined by an Inherited class
		if (mana > 0)
			mana--;
	}

private:
	int mana;
};

class Guerrier : public Personnage
{
public:
	Guerrier(const string& nom, int point_vie = 10, int force = 1,
		int armure = 10) :
		Personnage(nom, point_vie, force), armure(armure)
	{}

	void faiblir(int point)
	{
		cout << __PRETTY_FUNCTION__ << ": " << getNom() << " devrait faiblir de " << point << endl;
		if (armure > 0)
		{
			Personnage::faiblir(point-1);
			armure--;
		}
		else
		{
			Personnage::faiblir(point);
		}
	}

private:
	int armure;
};

int main()
{
	Guerrier g("Guerrier", 20, 1, 5);
	Magicien m("Magicien", 10, 2, 10);

	g.attaquer(m);
	m.attaquer(g);

	return 0;
}
