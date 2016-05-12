/* s02e06
Dans un fichier poeme.cc définissez la classe Fleur de sorte que le programme
principal suivant :
int main ()
{
  Fleur f1("Violette", "bleu");
  Fleur f2(f1);
  cout << "dans un cristal ";
  f2.eclore();
  cout << "Donne un poème un peu fleur bleue" << endl
       << "ne laissant plus ";
  return 0;
}

affiche le texte suivant (inspiré d'un poème arabe du 5e siècle de l'hégire) :

Violette fraichement cueillie
Fragile corolle taillée
dans un cristal veine de bleu
Donne un poème un peu fleur bleue
ne laissant plus qu'un simple souffle...
qu'un simple souffle...
Remarque : la solution n'est pas forcément unique.
*/

#include <iostream>
using namespace std;

class Fleur
{
public:
	Fleur(const string& nom, const string& couleur)
		: nom(nom), couleur(couleur)
	{
		cout << nom << " fraichement cueillie" << endl;
	};

	Fleur(const Fleur& f)
		: nom(f.nom), couleur(f.couleur)
	{
		cout << "Fragile corolle taillée" << endl;
	};

	~Fleur() { cout << "qu'un simple souffle..." << endl; }

	void eclore() const { cout << "veine de " << couleur << endl; }

private:
	const string nom;
	const string couleur;
};

int main ()
{
	Fleur f1("Violette", "bleu");
	Fleur f2(f1);
	cout << "dans un cristal ";
	f2.eclore();
	cout << "Donne un poème un peu fleur bleue" << endl
		<< "ne laissant plus ";
	return 0;
}
