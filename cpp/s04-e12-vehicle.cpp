/* s04e12
Dans un fichier Vehicule.cc, définir une classe Vehicule qui a pour attributs des informations
valables pour tout type de véhicule : sa marque ; sa date d'achat ; son prix d'achat ; son prix courant.

Définir un constructeur prenant en paramètre les trois attributs correspondant à :
la marque, la date d'achat et le prix d'achat (le prix courant sera calculé plus tard).

Définir une méthode publique void affiche(ostream&) const; qui affiche l'état de l'instance,
i.e. la valeur de ses attributs.
Définir ensuite deux classes Voiture et Avion, héritant de la classe Vehicule et ayant les attributs
supplémentaires suivants :
- pour la classe Voiture :
	-sa cylindrée ;
	-son nombre de portes ;
	-sa puissance ;
	-son kilométrage ;
- pour la classe Avion :
	- son type (hélices ou réaction) ;
	-son nombre d'heures de vol.
Pour chacune de ces classes, définir un constructeur qui permette l'initialisation explicite de l'ensemble
des attributs, ainsi qu'une méthode affichant la valeur des attributs. Constructeurs et méthode d'affichage
devront utiliser les méthodes appropriées de la classe parente !

Ajouter ensuite à la classe Vehicule, une méthode void calculePrix() qui donne le prix
courant. On calculera ce prix courant en soustrayant au prix d'achat 1% par année écoulée depuis la date
d'achat.

Redéfinir cette méthode dans les deux sous-classes Voiture et Avion, de sorte à calculer le prix
courant en fonction de certains critères, et mettre à jour l'attribut correspondant au prix courant :
Pour une voiture, le prix courant est égal au prix d'achat, moins :
- 2% pour chaque année depuis sa fabrication jusqu'à la date actuelle ;
- 5% pour chaque tranche de 10'000 km parcourus (on arrondit à la tranche la plus proche) ;
- 10% s'il s'agit d'un véhicule de marque « Renault » ou « Fiat » (choix totalement arbitraire
qu'on est bien sûr libre de modifier) ;
- et plus 20% s'il s'agit d'un véhicule de marque « Ferrari » ou « Porsche » (même remarque
que ci-dessus).

Pour un avion, le prix courant est égal au prix d'achat, moins :
10% pour chaque tranche de 1000 heures de vol s'il s'agit d'un avion à réaction ;
10% pour chaque tranche de 100 heures de vol s'il s'agit d'un avion à hélices.
Le prix doit rester positif (i.e., s'il est négatif, on le met à 0).
*/
#include <iostream>
#include <vector>
using namespace std;

const int dateAujourdhui = 2015;

class Vehicule
{
public:
	Vehicule(const std::string& marque, int dateAchat, double prixAchat) :
		marque(marque), dateAchat(dateAchat), prixAchat(prixAchat),
		prix(prixAchat)
	{}

	void affiche(ostream& os) const
	{
		os << "marque : " << marque << ", date d'achat : " << dateAchat
			<< ", prix d'achat : " << prixAchat << "," << endl
			<< "prix actuel : " << prix << endl;
	}

	void calculePrix()
	{
		double decote = 0.01 * (dateAujourdhui - dateAchat);
		prix = max(0.0, (1.0 - decote) * prixAchat);
	}

protected:
	std::string marque;
	int dateAchat;
	double prixAchat;
	double prix;
};

class Voiture : public Vehicule
{
public:
	Voiture(const std::string& marque, int dateAchat, double prixAchat,
		double cylindree, unsigned int nbPorte, double puissance,
		double kilometrage) :
		Vehicule(marque, dateAchat, prixAchat), cylindree(cylindree),
		nbPorte(nbPorte), puissance(puissance), kilometrage(kilometrage)
	{}

	void affiche(ostream& os) const
	{
		os << " ---- Voiture ----" << endl;
		Vehicule::affiche(os);
		cout << cylindree << " litres, " << nbPorte << " portes, "
			<< puissance << "CV, " << kilometrage << " km." << endl;
	}

	void calculePrix()
	{
		double decote = 0.02*(dateAujourdhui - dateAchat);
		decote += 0.05 * kilometrage/10000.0;
		if (marque == "Renault" || marque == "Fiat")
		{
			decote += 0.1;
		}
		else if (marque == "Ferrari" || marque == "Porsche")
		{
			decote -= 0.2;
		}
		prix = max(0.0, prixAchat * (1.0 - decote));
	}

private:
	double cylindree;
	unsigned int nbPorte;
	double puissance;
	double kilometrage;
};

enum eTypeAvion
{
	HELICES,
	REACTION
};

class Avion : public Vehicule
{
public:
	Avion(const std::string& marque, int dateAchat, double prixAchat,
		eTypeAvion type, double nbHeureVol = 0.0) :
		Vehicule(marque, dateAchat, prixAchat), type(type),
		nbHeureVol(nbHeureVol)
	{}

	void affiche(ostream& os) const
	{
		os << " ---- Avion à " << string((type == HELICES)?"helices":"reaction")
			<< " ----" << endl;
		Vehicule::affiche(os);
		os << nbHeureVol << " heures de vol." << endl;
	}

	void calculePrix()
	{
		double tranche = (type == HELICES)?100.0:1000.0;
		double decote = 0.1*nbHeureVol/tranche;
		prix = max(0.0, prixAchat*(1.0 - decote));
	}

private:
	eTypeAvion type;
	double nbHeureVol;
};

//Afin de tester les méthodes implémentées ci-dessus, compléter le main comme suit :
int main()
{
	vector<Voiture> garage;
	vector<Avion> hangar;

	garage.push_back(Voiture("Peugeot", 1998, 147325.79, 2.5, 5, 180.0, 12000));
	garage.push_back(Voiture("Porsche", 1985, 250000.00, 6.5, 2, 280.0, 81320));
	garage.push_back(Voiture("Fiat", 2001, 7327.30, 1.6, 3, 65.0, 3000));
	hangar.push_back(Avion("Cessna", 1972, 1230673.90, HELICES, 250));
	hangar.push_back(Avion("Nain Connu", 1992, 4321098.00, REACTION, 1300));

	for (auto voiture : garage)
	{
		voiture.calculePrix();
		voiture.affiche(cout);
	}

	for (auto avion : hangar)
	{
		avion.calculePrix();
		avion.affiche(cout);
	}

	return 0;
}
