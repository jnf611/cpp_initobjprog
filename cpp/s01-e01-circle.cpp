/* s01 e01
Le but de cet exercice est d'écrire une classe représentant la notion de cercle.
Écrivez un programme Cercle.cc dans lequel vous définissez une classe Cercle ayant
comme attributs un rayon et les coordonnées du centre (du cercle).
Déclarez ensuite les méthodes «get» et «set» correspondantes, par exemple :
void getCentre(double& x, double& y) const { ... }
void setCentre(double x, double y) { ... }
...
NOTE : ceci n'est qu'un exemple parmi d'autres. Si vous préférez d'autres prototypes pour
ces méthodes, libre à vous d'implémenter votre solution.
Vous pourrez en particulier réviser votre programme après avoir fait les exercices 3 et 4.
Ajoutez ensuite les méthodes (faisant partie de l'interface) :
double surface() const qui calcule et retourne la surface du cercle (pi fois le
carré du rayon);
bool estInterieur(double x, double y) const qui teste si le point de
coordonnées (x,y) passé en paramètre fait ou non partie du cercle (frontière comprise :
disque fermé).
La méthode retournera true si le test est positif, et false dans le cas contraire.
Dans le main(), instanciez deux objets de la classe Cercle, affectez des valeurs de votre
choix à leur attributs et testez vos méthodes surface et estInterieur.
Remarque : la constante pi est souvent définie comme M_PI dans le module cmath
(#include <cmath> au début de votre programme).
Si ce n'est pas le cas pour votre compilateur, ajoutez simplement les lignes suivantes en début
de votre programme, après les #include et le using namespace std; :
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif*/

#include <iostream>
#include <cmath>
#include "Point.hpp"
#include "Circle.hpp"
using namespace std;

Circle createDefaultCircle()
{
	Circle c;
	
	c.setCenter(Point(0.0, 0.0));
	c.setRadius(1.0);
	
	return c;
}

int unit_test_circle_surface()
{
	Circle c = createDefaultCircle();
	
	double expected = M_PI*c.getRadius()*c.getRadius();
	double res = c.surface();
	if (res != expected)
	{
		cout << res << " != " << expected << endl;
		return 1;
	}
		
	return 0;
}

int unit_test_circle_inside()
{
	Circle c = createDefaultCircle();
	
	if (c.inside(Point(1.0, 1.0)))
		return 1;
	if (!c.inside(Point(0.0, 1.0)))
		return 1;
		
	return 0;
}

int unit_test_circle()
{
	if (unit_test_circle_surface())
	{
		cout << "unit_test_circle_surface failed" << endl;
		return 1; 
	}
	if (unit_test_circle_inside())
	{
		cout << "unit_test_circle_inside failed" << endl;
		return 1; 
	}
	
	return 0;
}

int main()
{
	if (unit_test_circle())
		return 1;
		
	Circle c = createDefaultCircle();
	Point p = c.getCenter();
	cout << "c(" << p.x() << ", " << p.y() << ") radius = " << c.getRadius() << endl;
	
	return 0;
}
