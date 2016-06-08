#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Pour simplifier
typedef string Forme   ;
typedef string Couleur ;

class Brique
{
private:
  Forme   forme   ;
  Couleur couleur ;

public:
  /*****************************************************
    Compléter le code à partir d'ici
  *******************************************************/

	// constructor
	Brique(const Forme& forme, const Couleur& couleur)
		: forme(forme), couleur(couleur) {}

	// display
	ostream& afficher(ostream& os) const
	{
		if (couleur.empty()) { os << forme;	}
		else                 { os << "(" << forme << ", " << couleur << ")"; }

		return os;
	}
};

ostream& operator<<(ostream& os, const Brique& brique)
{
	return brique.afficher(os);
}

class Construction
{
  friend class Grader;

public:
	// constructor
	Construction(const Brique& brique)
		: contenu(1, vector<vector<Brique>>(1, vector<Brique>(1, brique))) {};

	// attributes (ensured as Construction is a least initialized with one
	// element)
	size_t hauteur() const    { return contenu.size();       }
	size_t profondeur() const { return contenu[0].size();    }
	size_t largeur() const    { return contenu[0][0].size(); }

	//display
	ostream& afficher(ostream& os) const;

	// operators
	Construction& operator^=(const Construction& c); // add above
	Construction& operator-=(const Construction& c); // add behind
	Construction& operator+=(const Construction& c); // add on the right

private:
	// hauteur [i], profondeur[j], largeur[k]
	vector<vector<vector<Brique>>> contenu;
};

ostream& Construction::afficher(ostream& os) const
{
	for(size_t i = contenu.size()-1; i < contenu.size(); --i)
	{
		os << "Couche " << i << " : " << endl;
		for (size_t j = contenu[i].size()-1; j < contenu[i].size(); --j)
		{
			for (size_t k = 0; k < contenu[i][j].size(); ++k)
			{
				os << contenu[i][j][k] << " ";
			}
			os << endl;
		}
	}

	return os;
}

ostream& operator<<(ostream& os, const Construction& construction)
{
	return construction.afficher(os);
}

Construction& Construction::operator^=(const Construction& other)
{
	contenu.insert(contenu.end(), other.contenu.begin(), other.contenu.end());

	return *this;
}

Construction operator^(Construction c, const Construction& d)
{
	return c ^= d;
}

Construction& Construction::operator-=(const Construction& other)
{
	if (other.hauteur() >= hauteur())
	{
		for (size_t i = 0; i < hauteur(); ++i)
		{
			contenu[i].insert(contenu[i].end(),
							  other.contenu[i].begin(),
							  other.contenu[i].end());
		}
	}

	return *this;
}

Construction operator-(Construction c, const Construction& d)
{
	return c -= d;
}

Construction& Construction::operator+=(const Construction& other)
{
	if (other.hauteur() >= hauteur() && other.profondeur() >= profondeur())
	{
		for (size_t i = 0; i < hauteur(); ++i)
		{
			for (size_t j = 0; j < profondeur(); ++j)
			{
				contenu[i][j].insert(contenu[i][j].end(),
									 other.contenu[i][j].begin(),
									 other.contenu[i][j].end());
			}
		}
	}

	return *this;
}

Construction operator+(Construction c, const Construction& d)
{
	return c += d;
}

const Construction operator*(unsigned int n, Construction const& a)
{
	Construction ret(a);
	for (unsigned int i = 1; i < n; ++i)
	{
		ret += a;
	}

	return ret;
}

const Construction operator/(unsigned int n, Construction const& a)
{
	Construction ret(a);
	for (unsigned int i = 1; i < n; ++i)
	{
		ret ^= a;
	}

	return ret;
}

const Construction operator%(unsigned int n, Construction const& a)
{
	Construction ret(a);
	for (unsigned int i = 1; i < n; ++i)
	{
		ret -= a;
	}

	return ret;
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  // Modèles de briques
  Brique toitD("obliqueD", "rouge");
  Brique toitG("obliqueG", "rouge");
  Brique toitM(" pleine ", "rouge");
  Brique mur  (" pleine ", "blanc");
  Brique vide ("                 ", "");

  unsigned int largeur(4);
  unsigned int profondeur(3);
  unsigned int hauteur(3); // sans le toit

  // on construit les murs
  Construction maison( hauteur / ( profondeur % (largeur * mur) ) );

  // on construit le toit
  Construction toit(profondeur % ( toitG + 2*toitM + toitD ));
  toit ^= profondeur % (vide + toitG + toitD);

  // on pose le toit sur les murs
  maison ^= toit;

  // on admire notre construction
  cout << maison << endl;

  return 0;
}
