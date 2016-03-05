#include <iostream>
using namespace std;

/*******************************************
 * Complétez le programme à partir d'ici.
 *******************************************/

class Tirelire
{
public:
  double getMontant() const {return _montant;};

  void secouer() const
  {
    if (_montant > 0.0) {
      cout << "Bing bing" << endl;
    }
  };

  void afficher() const
  {
    if (_montant == 0.0)
    {
      cout << "Vous etes sans le sou." << endl;
    }
    else
    {
      cout << "Vous avez : " << _montant << " euros dans votre tirelire."
        << endl;
    }
  };

  void vider() {_montant = 0.0;};

  void puiser(double montant)
  {
    if (montant > 0.0)
    {
      if (_montant - montant > 0.0) {
        _montant -= montant;
      } else {
        _montant = 0.0;
      }
    }
  };

  void remplir(double montant)
  {
    if (montant > 0.0) {
      _montant += montant;
    }
  };

  double calculerSolde(double budget) const
  {
    if (budget < 0.0) {
      budget = 0.0;
    }

    return _montant - budget;
  }

  bool montant_suffisant(double budget, double& solde) const
  {
    bool suffisant = false;

    solde = calculerSolde(budget);
    if (solde > 0.0) {
      suffisant = true;
    } else {
      solde = - solde; // on retourne une valeur positive
    }

    return suffisant;
  };

private:
  double _montant;
};

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  Tirelire piggy;

  piggy.vider();
  piggy.secouer();
  piggy.afficher();

  piggy.puiser(20.0);
  piggy.secouer();
  piggy.afficher();

  piggy.remplir(550.0);
  piggy.secouer();
  piggy.afficher();

  piggy.puiser(10.0);
  piggy.puiser(5.0);
  piggy.afficher();

  cout << endl;

  // le budget de vos vacances de rève.
  double budget;

  cout << "Donnez le budget de vos vacances : ";
  cin >> budget;

  // ce qui resterait dans la tirelire après les
  // vacances
  double solde(0.0);

  if (piggy.montant_suffisant(budget, solde)) {
    cout << "Vous êtes assez riche pour partir en vacances !"
         << endl
         << "Il vous restera " << solde << " euros"
         << " à la rentrée." << endl << endl;
    piggy.puiser(budget);
  } else {
    cout << "Il vous manque " << solde << " euros"
         << " pour partir en vacances !" << endl << endl;
  }
  return 0;
}
