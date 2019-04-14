/***************************************************************************************************
Le but de cet exercice est d'écrire une classe représentant la notion de Circle.
Écrivez un programme Circle.cc dans lequel vous définissez une classe Circle ayant
comme attributs un rayon et les coordonnées du centre (du Circle).
Déclarez ensuite les méthodes «get» et «set» correspondantes, par exemple :
void getCentre(double& x, double& y) const { ... }
void setCentre(double x, double y) { ... }
...
NOTE : ceci n'est qu'un exemple parmi d'autres. Si vous préférez d'autres prototypes pour
ces méthodes, libre à vous d'implémenter votre solution.
Vous pourrez en particulier réviser votre programme après avoir fait les exercices 3 et 4.
Ajoutez ensuite les méthodes (faisant partie de l'interface) :
double surface() const qui calcule et retourne la surface du Circle (pi fois le
carré du rayon);
bool estInterieur(double x, double y) const qui teste si le point de
coordonnées (x,y) passé en paramètre fait ou non partie du Circle (frontière comprise :
disque fermé).
La méthode retournera true si le test est positif, et false dans le cas contraire.
Dans le main(), instanciez deux objets de la classe Circle, affectez des valeurs de votre
choix à leur attributs et testez vos méthodes surface et estInterieur.
Remarque : la constante pi est souvent définie comme M_PI dans le module cmath
(#include <cmath> au début de votre programme).
Si ce n'est pas le cas pour votre compilateur, ajoutez simplement les lignes suivantes en début
de votre programme, après les #include et le using namespace std; :
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
***************************************************************************************************/
#include <iostream>
#include <cmath>

using namespace std;

struct Point
{
    double x; // absciss
    double y; // ordinate
    Point(double x, double y) : x(x), y(y) {}
    string to_string() const { return "(" + std::to_string(x) + "," + std::to_string(y) + ")"; }
};

ostream& operator<<(ostream& os, const Point& p)
{
    return os << p.to_string();
}

double distance(const Point& a, const Point& b)
{
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

class Circle
{
public:
    Circle(const Point& c, double r) : m_center(c), m_radius(r) {}
    void move(const Point& c) { m_center = c; }
    const Point& getCentre() const { return m_center; }
    void setRayon(double r) { m_radius = r; }
    double getRayon() const { return m_radius; }
    // features
    bool inside(const Point& p) const;
    double area() const { return M_PI * m_radius * m_radius; }
    // log
    string to_string() const;

private:
    Point m_center;
    double m_radius;
};

bool Circle::inside(const Point& p) const
{
    return distance(m_center, p) < m_radius;
}

string Circle::to_string() const
{
    return m_center.to_string() + ", radius: " + std::to_string(m_radius);
}

ostream& operator<<(ostream& os, const Circle& c)
{
    return os << c.to_string();
}

int main()
{
    Circle c(Point(0.0, 0.0), 1.0);

    cout << c.to_string() << endl;

    Point a(1.0, 1.0);
    cout << a << " " << (c.inside(a) ? "is" : "is not") << " inside " << c << endl;

    return 0;
}
