/* s05e16 formes */
#include <iostream>
#include <string>
using namespace std;

class Forme
{
public:
	virtual void description() const { cout << "Ceci est une forme" << endl; }
};

class Cercle : public Forme
{
public:
	virtual void description() const { cout << "Ceci est un cercle" << endl; }
};

void afficheDescription(const Forme& f)
{
	f.description();
}

int main()
{
	Forme f;
	f.description();
	Cercle c;
	c.description();

	Forme f2(c);
	f2.description();

	// with the function
	afficheDescription(f);
	afficheDescription(c);
	afficheDescription(f2);

	return 0;
}
