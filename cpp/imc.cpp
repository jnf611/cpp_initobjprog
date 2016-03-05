#include <iostream>
using namespace std;

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/

class Patient
{
public:
  // getters
  double poids() const  {return _masse;};
  double taille() const {return _hauteur;};

  void init(double masse, double hauteur)
  {
    if (masse <= 0.0 || hauteur <= 0.0)
    {
      _masse = 0.0;
      _hauteur = 0.0;
    }
    else
    {
      _masse = masse;
      _hauteur = hauteur;
    }
  };

  void afficher() const
  {
    cout << "Patient : " << _masse << " kg pour " << _hauteur << " m" << endl;
  };

  double imc() const
  {
    double imc = 0.0;

    if (_hauteur > 0.0) {
      imc = _masse / (_hauteur * _hauteur);
    }

    return imc;
  };

private:
  double _masse;
  double _hauteur;
};


/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  Patient quidam;
  double poids, taille;
  do {
    cout << "Entrez un poids (kg) et une taille (m) : ";
    cin >> poids >> taille;
    quidam.init(poids, taille);
    quidam.afficher();
    cout << "IMC : " << quidam.imc() << endl;
  } while (poids * taille != 0.0);
  return 0;
}
