/***************************************************************************************************
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
et tester les deux méthodes précédentes.
***************************************************************************************************/
#include <iostream>
#include <cmath>

using namespace std;

class Point3
{
public:
    // constructor and assignment
    Point3(double x, double y, double z) : x(x), y(y), z(z) {}
    Point3(const Point3& p) : x(p.x), y(p.y), z(p.z) {}
    Point3& operator=(const Point3& p);

    // features
    bool operator==(const Point3& p) const;
    int compare(const Point3& p);
    friend double distance(const Point3& a, const Point3& b);

    // log
    string to_string() const;

private:
    double x;
    double y;
    double z;
};

double distance(const Point3& a, const Point3& b)
{
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    double dz = a.z - b.z;

    return sqrt(dx*dx + dy*dy + dz*dz);
}

Point3& Point3::operator=(const Point3& p)
{
    x = p.x;
    y = p.y;
    z = p.z;
    return *this;
}

bool Point3::operator==(const Point3& p) const
{
    return (p.x == x) && (p.y == y) && (p.z == z);
}

string Point3::to_string() const
{
    return "(" + std::to_string(x) + "," + std::to_string(y) + "," + std::to_string(z) + ")";
}

ostream& operator<<(ostream& os, const Point3 p)
{
    return os << p.to_string();
}

void test(const Point3& a, const Point3& b)
{
    cout << "le point " << a << " est " << (a == b ? "identique au" : "différent du")
        << " point " << b << endl;
}

int main()
{
    Point3 o(0.0, 0.0, 0.0);
    Point3 i(1.0, 0.0, 0.0);
    Point3 j(0.0, 1.0, 0.0);
    Point3 i2(1.0, 0.0, 0.0);
    cout << i << endl;
    cout << o << endl;

    test(i, j);
    test(i, i2);

    return 0;
}
