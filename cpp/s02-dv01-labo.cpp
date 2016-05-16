#include <iostream>
using namespace std;

class Souris
{
  /*****************************************************
    Compléter le code à partir d'ici
  *******************************************************/
public:
	Souris(double poids, const string& couleur, unsigned int age = 0,
		unsigned int esperance_vie = 36)
	: poids(poids), couleur(couleur), age(age), esperance_vie(esperance_vie),
	clonee(false)
	{
		cout << "Une nouvelle souris !" << endl;
	}
	Souris(const Souris& s)
	: poids(s.poids), couleur(s.couleur), age(s.age),
	esperance_vie(s.esperance_vie*4/5), clonee(true)
	{
		cout << "Clonage d'une souris !" << endl;
	}
	~Souris()
	{
		cout << "Fin d'une souris..." << endl;
	}
	void afficher() const
	{
		cout << "Une souris " << couleur << (clonee?", clonee,":"") << " de "
			<< age << " mois et pesant " << poids << " grammes" << endl;
	}
	void vieillir()
	{
		++age;
		if (clonee && age > esperance_vie/2)
		{
			couleur.assign("verte");
		}
	}
	void evolue()
	{
		while (age < esperance_vie)
		{
			vieillir();
		}
	}

private:
	double poids;
	string couleur;
	unsigned int age;
	const unsigned int esperance_vie;
	const bool clonee;
  /*******************************************
   * Ne rien modifier après cette ligne.
   *******************************************/

}; // fin de la classe Souris

int main()
{
  Souris s1(50.0, "blanche", 2);
  Souris s2(45.0, "grise");
  Souris s3(s2);
  // ... un tableau peut-être...
  s1.afficher();
  s2.afficher();
  s3.afficher();
  s1.evolue();
  s2.evolue();
  s3.evolue();
  s1.afficher();
  s2.afficher();
  s3.afficher();
  return 0;
}
