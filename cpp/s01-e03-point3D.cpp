/* s01e03
Le but de cet exercice est d'implémenter de façon élémentaire une classe représentant les
coordonnées dans l'espace (3D).
Dans le fichier Point3D.cc, définir la classe Point3D représentant un point dans l'espace
par ses trois coordonnées, et possédant les méthodes suivantes :
« init », permettant d'initialiser les trois coordonnées d'un objet Point3D à partir de
trois valeurs de type double reçus en paramètres ;
« affiche », permettant l'affichage de coordonnées d'un objet Point3D ;
et « compare », permettant de comparer (tester l'égalité des coordonnées) l'objet
courant à un autre objet de type Point3D passé en paramètre.
Dans le main, créer trois points (trois instances) dont deux avec des coordonnées identiques
et tester les deux méthodes précédentes.*/

#include <iostream>
#include "Point3D.hpp"
using namespace std;

int main()
{
	Point3D point1;
	Point3D point2;
	Point3D point3;
	point1.init(1.0, 2.0, -0.1);
	point2.init(2.6, 3.5, 4.1);
	point3 = point1;

	cout << "Point 1 :";
	point1.print();
	cout << "Point 2 :";
	point2.print();

	cout << "Le point 1 est ";
	if (point1.compare(point2))
	{
		cout << "identique au";
	}
	else
	{
		cout << "différent du";
	}
	cout << " point 2." << endl;

	cout << "Le point 1 est ";
	if (point1.compare(point3))
	{
		cout << "identique au";
	}
	else
	{
		cout << "différent du";
	}
	cout << " point 3." << endl;

	return 0;
}
