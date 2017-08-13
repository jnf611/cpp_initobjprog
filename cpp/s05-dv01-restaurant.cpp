#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

/*****************************************************
  * Compléter le code à partir d'ici
 *****************************************************/

class Produit
{
public:
	Produit(const string& nom, const string& unite = "")
		: nom(nom), unite(unite)
	{}
	const string& getNom() const { return nom; }
	const string& getUnite() const { return unite; }
	virtual string toString() const { return getNom(); }
	virtual const Produit* adapter(double n) { return this; }

protected:
	string nom;
	string unite;
};

class Ingredient
{
public:
	Ingredient(const Produit& produit, double quantite = 1.0)
		: produit(produit), quantite(quantite)
	{}
	const Produit& getProduit() const { return produit; }
	double getQuantite() const { return quantite; }
	string descriptionAdaptee() const;

private:
	const Produit& produit;
	double quantite;
};

string Ingredient::descriptionAdaptee() const
{
	// Necessite la méthode adapter sur les produits
	// Exemple: 2.000000 gouttes de extrait d’amandes
	string s = to_string(quantite) + " " + produit.getUnite() + " de "
		+ produit.toString();
	return s;
}

class Recette
{
public:
	Recette(const string& nom, double nbFois = 1.0)
		: nom(nom), nbFois_(nbFois)
	{}
	~Recette();
	void ajouter(const Produit& produit, double quantite);
	string toString() const;
	double quantiteTotale(const string& nom) const;
	Recette adapter(double n) const;

private:
	vector<Ingredient*> ingredients;
	string nom;
	double nbFois_;
};

Recette::~Recette()
{
	for (auto i : ingredients)
		delete i;

	ingredients.clear();
}

void Recette::ajouter(const Produit& produit, double quantite)
{
	ingredients.push_back(new Ingredient(produit, nbFois_*quantite));
}

/**
 * Exemple de formatage
Recette "glaçage au chocolat parfumé" x 1:
1. 2.000000 gouttes de extrait d’amandes
2. 1.000000 portion(s) de glaçage au chocolat
 */
string Recette::toString() const
{
	string s = "  Recette \"" + nom + "\" x " + to_string(int(nbFois_)) + ":\n";
	for (size_t i = 0; i < ingredients.size(); ++i)
	{
		s += "  " + to_string(i+1) + ". "
			+ ingredients[i]->descriptionAdaptee();
		if (i < ingredients.size() - 1)
			s += "\n";
	}
	return s;
}

double Recette::quantiteTotale(const string& nom) const
{
	for (auto i : ingredients)
	{
		if (nom.compare(i->getProduit().getNom()) == 0)
		{
			return i->getQuantite()*nbFois_;
		}
	}
	// when not found, return 0
	return 0.0;
}

Recette Recette::adapter(double n) const
{
	Recette r(nom, n);
	for (auto i : ingredients)
	{
		r.ingredients.push_back(new Ingredient(i->getProduit(), i->getQuantite()/nbFois_));
	}
	return r;
}

class ProduitCuisine : public Produit
{
public:
	ProduitCuisine(const string& nom)
		: Produit(nom, "portion(s)"), recette(nom)
	{}
	void ajouterARecette(const Produit& produit, double quantite);
	virtual string toString() const;
	virtual const ProduitCuisine* adapter(double n);

private:
	Recette recette;
};

void ProduitCuisine::ajouterARecette(const Produit& produit, double quantite)
{
	recette.ajouter(produit, quantite);
}

string ProduitCuisine::toString() const
{
	return Produit::toString() + "\n" + recette.toString();
}

/*une méthode const ProduitCuisine* adapter(double n) retournant
un pointeur sur un nouveau produit cuisiné correspondant au produit
courant dont la recette est adaptée n fois;*/
const ProduitCuisine* ProduitCuisine::adapter(double n)
{
	cout << "[D]ProduitCuisine::adapter(" << n << "):" << nom << endl;
	recette = recette.adapter(n);
	return this;
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/
void afficherQuantiteTotale(const Recette& recette, const Produit& produit)
{
  string nom = produit.getNom();
  cout << "Cette recette contient " << recette.quantiteTotale(nom)
       << " " << produit.getUnite() << " de " << nom << endl;
}

int main()
{
  // quelques produits de base
  Produit oeufs("oeufs");
  Produit farine("farine", "grammes");
  Produit beurre("beurre", "grammes");
  Produit sucreGlace("sucre glace", "grammes");
  Produit chocolatNoir("chocolat noir", "grammes");
  Produit amandesMoulues("amandes moulues", "grammes");
  Produit extraitAmandes("extrait d'amandes", "gouttes");

  ProduitCuisine glacage("glaçage au chocolat");
  // recette pour une portion de glaçage:
  glacage.ajouterARecette(chocolatNoir, 200);
  glacage.ajouterARecette(beurre, 25);
  glacage.ajouterARecette(sucreGlace, 100);
  cout << glacage.toString() << endl;

  ProduitCuisine glacageParfume("glaçage au chocolat parfumé");
  // besoin de 1 portions de glaçage au chocolat et de 2 gouttes
  // d'extrait d'amandes pour 1 portion de glaçage parfumé

  glacageParfume.ajouterARecette(extraitAmandes, 2);
  glacageParfume.ajouterARecette(glacage, 1);
  cout << glacageParfume.toString() << endl;

  Recette recette("tourte glacée au chocolat");
  recette.ajouter(oeufs, 5);
  recette.ajouter(farine, 150);
  recette.ajouter(beurre, 100);
  recette.ajouter(amandesMoulues, 50);
  recette.ajouter(glacageParfume, 2);

  cout << "===  Recette finale  =====" << endl;
  cout << recette.toString() << endl;
  afficherQuantiteTotale(recette, beurre);
  cout << endl;

  // double recette
  Recette doubleRecette = recette.adapter(2);
  cout << "===  Recette finale x 2 ===" << endl;
  cout << doubleRecette.toString() << endl;

  afficherQuantiteTotale(doubleRecette, beurre);
  afficherQuantiteTotale(doubleRecette, oeufs);
  afficherQuantiteTotale(doubleRecette, extraitAmandes);
  afficherQuantiteTotale(doubleRecette, glacage);
  cout << endl;

  cout << "===========================\n" << endl;
  cout << "Vérification que le glaçage n'a pas été modifié :\n";
  cout << glacage.toString() << endl;

  return 0;
}
