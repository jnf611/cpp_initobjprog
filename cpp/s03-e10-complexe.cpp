/* s03e10
Le but de cet exercice est d'implémenter la classe Complexe et de définir les opérateurs nécessaires pour
écrire des opérations arithmétiques simples mettant en jeu des nombre complexes et réels.

1. Définir la classe Complexe, en utilisant la représentation cartésienne des nombres complexes (i.e.
avec deux attributs double représentant respectivement les parties réelle et imaginaire du nombre
complexe).

*/
#include "Complexe.hpp"
#include <iostream>
using namespace std;


int main()
{
	//2
	cout << endl << "Complexe defaut;" << endl;
	Complexe defaut;
	cout << endl << "Complexe zero(0.0, 0.0);" << endl;
	Complexe zero(0.0, 0.0);
	cout << endl << "Complexe un(1.0, 0.0);" << endl;
	Complexe un(1.0, 0.0);
	cout << endl << "Complexe i(0.0, 1.0);" << endl;
	Complexe i(0.0, 1.0);
	cout << endl << "Complexe j;" << endl;
	Complexe j;

	//3
	cout << endl << zero << " ==? " << defaut;
	cout << endl << "if (zero == defaut)" << endl;
	if (zero == defaut) cout << " oui" << endl;
	else cout << " non" << endl;

	cout << endl << zero << " ==? " << i;
	cout << endl << "if (zero == i)" << endl;
	if (zero == i) cout << " oui" << endl;
	else cout << " non" << endl;

	//4
	cout << endl << "j = un + i;" << endl;
	j = un + i;
	cout << endl << un << " + " << i << " = " << j << endl;

	cout << endl << "Complexe trois(un);" << endl;
	Complexe trois(un);
	cout << endl << "trois += un;" << endl;
	trois += un;
	cout << endl << "trois += 1.0;" << endl;
	trois += 1.0;
	cout << endl << un << " + " << un << " + 1.0 = " << trois << endl;

	cout << endl << "Complexe two;" << endl;
	Complexe two;
	cout << endl << "two = 1.0 + un" << endl;
	two = 1.0 + un;

	cout << endl << "Complexe deux(trois);" << endl;
	Complexe deux(trois);
	cout << endl << "deux -= un;" << endl;
	deux -= un;
	cout << endl << trois << " - " << un << " = " << deux << endl;
	cout << endl << "trois = 1.0 + deux;" << endl;
	trois = 1.0 + deux;
	cout << endl << "1.0 + " << deux << " = " << trois << endl;

	//5
	cout << endl << "Complexe z(i*i);" << endl;
	Complexe z(i*i);
	cout << endl << i << " * " << i << " = " << z << endl;
	cout << endl << z << " / " << i << " = " << z/i << " = ";
	cout << endl << (z/=i) << endl;

	//6
	cout << endl << "Complexe k(2.0,-3.0);" << endl;
	Complexe k(2.0,-3.0);
	cout << endl << "z = k;" << endl;
	z = k;
	cout << endl << "z *= 2.0;" << endl;
	z *= 2.0;
	cout << endl << "z *= i;" << endl;
	z *= i;
	cout << endl << k << " * 2.0 * " << i << " = " << z << endl;
	z = 2.0 * k * i / 1.0;
	cout << endl << " 2.0 * " << k << " * " << i << " / 1 = " << z << endl;

	return 0;
}
