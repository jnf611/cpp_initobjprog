/* s02e13
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
#include "Point3D_2.hpp"
#include "Vector3D.hpp"
using namespace std;

int main()
{
	Point3D_2 point1(1.0, 2.0, -0.1);
	Point3D_2 point2(2.6, 3.5, 4.1);
	Point3D_2 point3(point1);
	//Point3D_2 point4(Point3D_2::userInit());

	cout << "Point 1 :" << point1 << endl;
	cout << "Point 2 :" << point2 << endl;

	cout << "Le point 1 est "
		<< string((point1==point2)?"identique au":"différent du")
		<< " point 2." << endl;

	cout << "Le point 1 est "
		<< string((point1==point2)?"identique au":"différent du")
		<< " point 3." << endl;

	Vector3D null;
	Vector3D v(0.0, 1.0);
	Vector3D a(2.0, 1.0);
	cout << "Vecteur null: " << null << endl;
	cout << "v: " << v << endl;
	a += v;
	cout << a << endl;
	a = a + v - null;
	cout << a << endl;
	a *= 2.0;
	cout << a << endl;
	a = 5 * v;
	cout << a << endl;
	a = v * 3;
	cout << a << endl;

	UnitVector3D i(1.0);
	UnitVector3D j(0.0, 1.0);
	cout << "i: " << i << endl;
	cout << "j: " << j << endl;
	cout << "i + j: " << i + j << endl;
	i += j;
	cout << "i:" << i << endl;
	i -= j;

	return 0;
}
