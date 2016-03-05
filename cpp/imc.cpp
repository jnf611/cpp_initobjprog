#include <iostream>
using namespace std;

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/

class Patient
{
public:
  void init(double masse, double hauteur)
  {
    if (masse > 0.0) {
      _masse = masse;
    } else {
      _masse = 0.0;
    }
    if (hauteur > 0.0) {
      _hauteur = hauteur;
    } else {
      _hauteur = 0.0;
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
