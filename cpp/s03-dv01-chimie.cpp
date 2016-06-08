#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Flacon
{
private:
  string nom;
  double volume;
  double pH;

public:
  /*****************************************************
    Compléter le code à partir d'ici
  *******************************************************/
	// constructor
	Flacon(const string& nom, double volume, double pH);

	// display
	ostream& etiquette(ostream& os) const;

	// overload
	Flacon& operator+=(const Flacon& f);
	Flacon operator+(const Flacon& f) const;
};

#define BONUS

// constructor
Flacon::Flacon(const string& nom, double volume, double pH)
	: nom(nom), volume(volume), pH(pH)
{}

// display
ostream& Flacon::etiquette(ostream &os) const
{
	return os << nom << " : " << volume << " ml, pH " << pH;
}

// overload
ostream& operator<<(ostream& os, const Flacon& f)
{
	return f.etiquette(os);
}

// this makes sense to be in the class as private
double add_pH(double v1, double pH1, double v2, double pH2)
{
	return -log10((v1*pow(10, -pH1) + v2*pow(10, -pH2)) / (v1 + v2));
}

#ifdef BONUS

Flacon& Flacon::operator+=(const Flacon& f)
{
	nom += " + " + f.nom;
	pH = add_pH(volume, pH, f.volume, f.pH);
	volume += f.volume;

	return *this;
}

Flacon Flacon::operator+(const Flacon& f) const
{
	return Flacon(*this) += f;
}

#else

Flacon Flacon::operator+(const Flacon& f) const
{
	return Flacon(nom + " + " + f.nom, volume + f.volume,
		add_pH(volume, pH, f.volume, f.pH));
}

Flacon& Flacon::operator+=(const Flacon& f)
{
	return Flacon(*this) + f;
}

#endif

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

void afficher_melange(Flacon const& f1, Flacon const& f2)
{
  cout << "Si je mélange " << endl;
  cout << "\t\"" << f1 << "\"" << endl;
  cout << "avec" << endl;
  cout << "\t\"" << f2 << "\"" << endl;
  cout << "j'obtiens :" << endl;
  cout << "\t\"" << (f1 + f2) << "\"" << endl;
}

int main()
{
  Flacon flacon1("Eau", 600.0, 7.0);
  Flacon flacon2("Acide chlorhydrique", 500.0, 2.0);
  Flacon flacon3("Acide perchlorique",  800.0, 1.5);

  afficher_melange(flacon1, flacon2);
  afficher_melange(flacon2, flacon3);

  return 0;

}
