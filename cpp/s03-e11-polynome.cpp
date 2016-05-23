/*s03e11
Exercice 11 : encore un peu plus de polynômes (désolé !) (niveau 2)
Cet exercice correspond à l'exercice n°54 (pages 133 et 314) de
l'ouvrage C++ par la pratique (3e  édition, PPUR).
Le but de cet exercice est de faire de façon propre et complète une classe permettant la manipulation de
polynômes (sur le corps réels).
Pour ceux qui n'ont pas fait le tutoriel :
définissez la classe Polynome comme un tableau dynamique de double ;
ajoutez-y la méthode degre() qui donne le degré du polynôme ;
définissez à cette occasion le type Degre utilisé pour représenter le degré d'un
polynôme ;
ajoutez un constructeur par défaut qui crée le polynôme nul, un constructeur
plongeant le corps des réels dans celui des polynômes (Polynome(double);)
et un constructeur de copie ;
ajoutez aussi un constructeur permettant de construire 
facilement des monômes (a X^n), en précisant le coefficient (a) et le degré (n) : 
Polynome(double a, Degre n)
passez ensuite à l'opérateur (externe) <<  d'affichage dans un ostream ;
Pour finir cette partie introductive, ajoutez les opérateurs de 
multiplication (par un polynôme et aussi
par un réel).
  Polynome operator*(Polynome const& q) const;
  Polynome operator*(double) const;
  Polynome& operator*=(Polynome const& q);
  Polynome& operator*=(double);
et en externe
  Polynome operator*(double, Polynome const&);
*/
#include <iostream>
#include <vector>
#include <string>
#include <ostream>
using namespace std;

class Polynome
{
public:
	typedef unsigned int Degre;
	
	// constructor
	Polynome() {}
	Polynome(double a) : coeffs(1, a) {} // what if a == 0 ?
	Polynome(double a, Degre n) : coeffs(n) { coeffs.push_back(a); }
	
	// other
	
	Degre degre() const { return coeffs.size()?coeffs.size()-1:0; }
	
	// display
	std::string to_string() const
	{
		string s("");
		for (size_t i = 2; i < coeffs.size(); ++i)
		{
			if (i == 0)
				s = std::to_string(coeffs[0]) + s;
			else if (i == 1)
				s = std::to_string(coeffs[1]) + " + " + s;
			else
				s = std::to_string(coeffs[i]) + " x^" + std::to_string(i) + " + " + s;
		}
		return s;
	}

private:
	std::vector<double> coeffs;
};

ostream& operator<<(ostream& os, const Polynome& p)
{
	return os << p.to_string();
}

int main()
{
	Polynome null;
	Polynome reel(5.0);
	Polynome monome(3.0, 2);
	
	cout << "Le polynome null est :" << null << endl;
	cout << "Un polynome reel est par exemple:" << reel << endl;
	cout << "Un monome est par example:" << monome << endl;
	
	return 0;
}
