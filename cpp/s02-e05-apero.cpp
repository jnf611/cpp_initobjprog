/* s02e05
Définir la classe Apero de sorte que le main() suivant :
int main() {
  Apero bic;
  cout << "Super !" << endl;
  bic.bis();
  cout << "Non merci." << endl;
  return 0;
}
affiche le texte suivant :
L'heure de l'apéro a sonné !
Super !
Encore une ?
Non merci.
À table !
*/

#include <iostream>
using namespace std;

class Apero
{
public:
	Apero()	         { cout << "L'heure de l'apéro a sonné !" << endl; }
	~Apero()         { cout << "À table !"                    << endl; }
	void bis() const { cout << "Encore une ?"                 << endl; } // this is a predicate, ie a const method --> do not forget the const specifier
};

int main()
{
	Apero bic;
	cout << "Super !" << endl;
	bic.bis();
	cout << "Non merci." << endl;
	return 0;
}

