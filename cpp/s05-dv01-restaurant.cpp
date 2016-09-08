#include <iostream>
#include <vector>
#include <sstream>

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
	string getNom() const { return nom; }
	string getUnite() const { return unite; }

private:
	string nom;
	string unite;
};

class Ingredient
{
public:
	Ingredient(const Produit& produit, double quantite = 1.0)
		: produit(produit), quantite(quantite)
	{}
	string getNom() const { return produit.getNom(); }
	double getQuantite() const { return quantite; }

private:
	Produit produit;
	double quantite;
};

class Recette
{
public:
	Recette(const string& nom, double nbFois = 1.0)
		: nom(nom), nbFois_(nbFois)
	{}
	~Recette();
	void ajouter(const Produit& produit, double quantite);
	string toString() const { return nom; };
	double quantiteTotale(const string& nom) const;

private:
	vector<Ingredient*> ingredients;
	string nom;
	double nbFois_;
};

Recette::~Recette()
{
	for (auto i : ingredients)
	{
		delete i;
	}
	ingredients.clear();
}

void Recette::ajouter(const Produit& produit, double quantite)
{
	ingredients.push_back(new Ingredient(produit, quantite));
}

double Recette::quantiteTotale(const string& nom) const
{
	for (auto i : ingredients)
	{
		if (nom.compare(i->getNom()) == 0)
		{
			return i->getQuantite()*nbFois_;
		}
	}
	// when not found, return null
	return 0.0;
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

  /*ProduitCuisine glacage("glaçage au chocolat");
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
  cout << glacageParfume.toString() << endl;*/

  Recette recette("tourte glacée au chocolat");
  recette.ajouter(oeufs, 5);
  recette.ajouter(farine, 150);
  recette.ajouter(beurre, 100);
  recette.ajouter(amandesMoulues, 50);
  //recette.ajouter(glacageParfume, 2);

  cout << "===  Recette finale  =====" << endl;
  cout << recette.toString() << endl;
  afficherQuantiteTotale(recette, beurre);
  cout << endl;

  // double recette
  /*Recette doubleRecette = recette.adapter(2);
  cout << "===  Recette finale x 2 ===" << endl;
  cout << doubleRecette.toString() << endl;

  afficherQuantiteTotale(doubleRecette, beurre);
  afficherQuantiteTotale(doubleRecette, oeufs);
  //afficherQuantiteTotale(doubleRecette, extraitAmandes);
  //afficherQuantiteTotale(doubleRecette, glacage);
  cout << endl;

  cout << "===========================\n" << endl;
  cout << "Vérification que le glaçage n'a pas été modifié :\n";
  cout << glacage.toString() << endl;*/

  return 0;
}
