/* s05e19 livre */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Livre
{
public:
	Livre(const std::string& titre, const std::string& auteur,
		unsigned int nb_page, bool bestseller);
	virtual ~Livre();

	virtual double prix();
	virtual void afficher();

protected:
	void afficher_info();
	void afficher_prix();

	std::string titre;
	std::string auteur;
	unsigned int nb_page;
	bool bestseller;
};

class Roman : public Livre
{
public:
	Roman(const std::string& titre, const std::string& auteur,
		unsigned int nb_page, bool bestseller, bool biographie);
	virtual ~Roman();

	virtual void afficher();

protected:
	bool biographie;
};

class Policier : public Roman
{
public:
	using Roman::Roman;
	virtual ~Policier();

	virtual double prix();
};

class BeauLivre : public Livre
{
public:
	using Livre::Livre;
	virtual ~BeauLivre();

	virtual double prix();
};

Livre::Livre(const std::string& titre, const std::string& auteur,
	unsigned int nb_page, bool bestseller) :
	titre(titre), auteur(auteur), nb_page(nb_page), bestseller(bestseller)
{}

Livre::~Livre()
{}

double Livre::prix()
{
	double prix = 0.3*nb_page;

	if (bestseller)
		prix += 50.0;

	return prix;
}

void Livre::afficher_info()
{
	cout
		<< "titre : " << titre << endl
		<< "auteur : " << auteur << endl
		<< "nombre de pages : " << nb_page << endl
		<< "bestseller : " << (bestseller?"oui":"non") << endl;
}

void Livre::afficher_prix()
{
	cout << "prix : " << prix() << endl;
}

void Livre::afficher()
{
	afficher_info();
	afficher_prix();
}

Roman::Roman(const std::string& titre, const std::string& auteur,
	unsigned int nb_page, bool bestseller, bool biographie) :
	Livre(titre, auteur, nb_page, bestseller), biographie(biographie)
{}

Roman::~Roman()
{}

void Roman::afficher()
{
	Livre::afficher_info();
	cout << "Ce roman " << (biographie?"est":"n'est pas") << " une biographie"
		<< endl;
	Livre::afficher_prix();
}

Policier::~Policier()
{}

double Policier::prix()
{
	double prix = Roman::prix() - 10.0;

	if (prix < 0.0)
		prix = 1.0;

	return prix;
}

BeauLivre::~BeauLivre()
{}

double BeauLivre::prix()
{
	return Livre::prix() + 30.0;
}

class Librairie
{
public:
	void ajouter_livre(Livre*);
	void afficher() const;
	void vider_stock();

private:
	vector<Livre*> livres;
};

void Librairie::ajouter_livre(Livre* l)
{
	livres.push_back(l);
}

void Librairie::afficher() const
{
	for (auto l : livres)
	{
		l->afficher();
	}
}

void Librairie::vider_stock()
{
	while (livres.size())
	{
		delete livres.back();
		livres.pop_back();
	}
	// other solution from correction, corresponding more with the idea of
	// deleting stock. Anyway, the delete needs to be call on each book
	/*for (auto l : livres)
	{
		delete l;
	}
	livres.clear()*/
}

int main()
{
	Librairie librairie;

	librairie.ajouter_livre(new Livre("Harry Potter à l'école des sorciers", "J.K. Rowling", 308, true));
	librairie.ajouter_livre(new Roman("Le fou", "Gogol", 252, false, false));
	librairie.ajouter_livre(new BeauLivre("La terre", "JJA", 100, true));
	librairie.ajouter_livre(new Policier("Brouillard au pont de Tolbiac", "Tardi", 48, false, false));
	librairie.ajouter_livre(new Policier("Le chien des Baskerville", "A.C.Doyle", 221, false, false));
	librairie.ajouter_livre(new Policier("Le Parrain", "A.Cuso", 367, true, false));
	librairie.ajouter_livre(new Roman("Le baron perché", "I. Calvino", 283, false, false));
	librairie.ajouter_livre(new Roman("Mémoires de Géronimo", "S.M. Barrett", 173, false, true));
	librairie.ajouter_livre(new BeauLivre("Fleuves d'Europe", "C. Osborne", 150, false));

	librairie.afficher();
	librairie.vider_stock();

	return 0;
}
