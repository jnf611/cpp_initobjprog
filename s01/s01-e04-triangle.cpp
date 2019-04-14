/***************************************************************************************************
triangles (niveau 2)
4.1 Organisation de l'exercice
Comme dans l'exercice 2, nous vous demandons dans cet exercice d'élaborer un programme
orienté objets de manière indépendante. Nous l'avons donc à nouveau organisé en deux
parties :
1. une première (de 4.2 à 4.4) qui décrit le problème à résoudre et qui, idéalement devrait
suffire pour élaborer puis écrire le programme de façon autonome ;
2. une seconde (partie 4.5), pour aider au cas où la première partie vous semble
insuffisante. Essayez dans un premier temps de ne pas la lire et revenez-y si nécessaire.
4.2 Buts du programme
Sur la base du programme de l'exercice précédent, écrire un nouveau programme
triangles.cc qui permet à l'utilisateur d'entrer les coordonnées (x, y et z) des sommets
d'un triangle (en 3D). Le programme affiche ensuite le périmètre du triangle ainsi qu'un
message indiquant s'il s'agit ou non d'un triangle isocèle.
4.2 Indications générales (aide mathématique)
Un triangle est isocèle si au moins deux côtés ont la même longueur.
Le périmètre d'un triangle peut être calculé comme la somme des distances entre les trois
sommets.
4.4 Exemple de déroulement
Construction d'un nouveau point
Veuillez entrer x : 0
Veuillez entrer y : 0
Veuillez entrer z : 0
Construction d'un nouveau point
Veuillez entrer x : 2.5
Veuillez entrer y : 2.5
Veuillez entrer z : 0
Construction d'un nouveau point
Veuillez entrer x : 0
Veuillez entrer y : 5
Veuillez entrer z : 0
Périmètre : 12.071067811865476
Ce triangle est isocèle !
***************************************************************************************************/
#include <iostream>
#include <vector>
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

class Triangle
{
public:
    Triangle(const Point3& a, const Point3& b, const Point3& c) : m_sommets({a, b, c}) {};
    double perimeter() const;
    bool isocele() const;

private:
    vector<Point3> m_sommets;
};

double Triangle::perimeter() const
{
    double perimeter = 0.0;

    for (size_t i = 0; i < 3; ++i)
        perimeter += distance(m_sommets[i], m_sommets[(i+1)%3]);

    return perimeter;
}

bool Triangle::isocele() const
{
    vector<double> distances = {0.0, 0.0, 0.0};

    for (size_t i = 0; i < 3; ++i)
        distances[i] = distance(m_sommets[i], m_sommets[(i+1)%3]);

    return (distances[0] == distances[1]) ||
           (distances[1] == distances[2]) ||
           (distances[0] == distances[2]);
}


int main()
{
    Point3 o(0.0, 0.0, 0.0);
    Point3 a(2.5, 0.0, 0.0);
    Point3 b(5.0, 0.0, 0.0);

    Triangle t(o, a, b);
    cout << "perimeter:" << t.perimeter() << endl;
    cout << "t " << (t.isocele() ? "est" : "n'est pas") << " isocèle" << endl;
    return 0;
}
