#include <iostream>
#include <string>
using namespace std;

class Timbre
{
private:
  static constexpr unsigned int ANNEE_COURANTE = 2016;

  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/
public:
	Timbre(const string& nom, unsigned int annee, const string& pays = "Suisse",
		double valeur_faciale = 1.0) :
		nom(nom), annee(annee), pays(pays), valeur_faciale(valeur_faciale)
	{}
	double vente() const;
	unsigned int age() const;
	ostream& afficher(ostream& os) const;

private:
	string nom;
	unsigned int annee;
	string pays;
	double valeur_faciale;
};

double Timbre::vente() const
{
	double prix(valeur_faciale);

	if (age() >= 5)
	{
		prix *= 2.5 * age();
	}

	return prix;
}

unsigned Timbre::age() const
{
	return ANNEE_COURANTE - annee;
}

ostream& Timbre::afficher(ostream& os) const
{
	return os << " de nom " << nom << " datant de " << annee << " (provenance "
		<< pays << ") ayant pour valeur faciale " << valeur_faciale
		<< " francs";
}

ostream& operator<<(ostream& os, const Timbre& t)
{
	os << "Timbre";
	t.afficher(os);
	return os;
}

class Commemoratif : public Timbre
{
public:
	using Timbre::Timbre;
	double vente() const;
};

double Commemoratif::vente() const
{
	return 2.0 * Timbre::vente();
}

ostream& operator<<(ostream& os, const Commemoratif& t)
{
	os << "Timbre commémoratif";
	t.afficher(os);
	return os;
}

class Rare : public Timbre
{
public:
	Rare(const string& nom, unsigned int annee, const string& pays = "Suisse",
		double valeur_faciale = 1.0, unsigned int nb = 100) :
		Timbre(nom, annee, pays, valeur_faciale), nb(nb)
	{}

	unsigned nb_exemplaires() const { return nb; }
	double vente() const;

private:
	unsigned int nb;
	static constexpr double PRIX_BASE_TRES_RARE = 600.0;
	static constexpr double PRIX_BASE_RARE = 400.0;
	static constexpr double PRIX_BASE_PEU_RARE = 50.;
};

double Rare::vente() const
{
	double prix = 0.0;

	if      (nb < 100)  { prix = PRIX_BASE_TRES_RARE; }
	else if (nb < 1000) { prix = PRIX_BASE_RARE;      }
	else                { prix = PRIX_BASE_PEU_RARE;  }
	prix *= age() / 10.0;

	return prix;
}

ostream& operator<<(ostream& os, const Rare& t)
{
	os << "Timbre rare (" << t.nb_exemplaires() << " ex.)";
	t.afficher(os);
	return os;
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/
int main()
{
  /* Ordre des arguments :
  *  nom, année d'émission, pays, valeur faciale, nombre d'exemplaires
  */
  Rare t1( "Guarana-4574", 1960, "Mexique", 0.2, 98 );
  Rare t2( "Yoddle-201"  , 1916, "Suisse" , 0.8,  3 );

  /* Ordre des arguments :
  *  nom, année d'émission, pays, valeur faciale, nombre d'exemplaires
  */
  Commemoratif t3( "700eme-501"  , 2002, "Suisse", 1.5 );
  Timbre       t4( "Setchuan-302", 2004, "Chine" , 0.2 );

  /* Nous n'avons pas encore le polymorphisme :-(
   * (=> pas moyen de faire sans copie ici :-( )  */
  cout << t1 << endl;
  cout << "Prix vente : " << t1.vente() << " francs" << endl;
  cout << t2 << endl;
  cout << "Prix vente : " << t2.vente() << " francs" << endl;
  cout << t3 << endl;
  cout << "Prix vente : " << t3.vente() << " francs" << endl;
  cout << t4 << endl;
  cout << "Prix vente : " << t4.vente() << " francs" << endl;

  return 0;
}
