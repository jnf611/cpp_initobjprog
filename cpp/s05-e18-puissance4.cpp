/* s05e18 Puissance 4*/
#include <iostream>
#include <vector>
using namespace std;

enum Couleur
{
	VIDE,
	JAUNE,
	ROUGE
};

class Jeu
{
public:
	Jeu(size_t largeur = 8) : largeur(max(largeur, largeur_min)), plateau(8) {}
	size_t getLargeur() { return largeur; }

	bool jouer(Couleur couleur, size_t colonne)
	{
		bool ok = false;
		if (colonne < largeur && plateau[colonne].size() < largeur)
		{
			plateau[colonne].push_back(couleur);
			ok = true;
		}
		return ok;
	}

	Couleur gagnant()
	{
		if (estRempli())
			return VIDE;
	}

	static const size_t largeur_min;
private:
	bool estRempli()
	{
		size_t total = 0;
		for (auto c : plateau)
		{
			total += c.size();
		}
		return (total == largeur*largeur);
	}
	size_t largeur;
	vector<vector<Couleur>> plateau;
};

const size_t Jeu::largeur_min = 8;

class Joueur
{
public:
	Joueur(const string& nom, Couleur couleur) : nom(nom), couleur(couleur) {}
	virtual void jouer(Jeu& jeu) = 0;

protected:
	const string nom;
	Couleur couleur;
};

class JoueurHumain : public Joueur
{
public:
	using Joueur::Joueur;
	virtual void jouer(Jeu& jeu)
	{
		bool ok = false;
		do
		{
			size_t colonne;
			cout << "Joueur " << nom << ", entrez un numéro de colonne" << endl
				<< "(entre 1 et " << jeu.getLargeur() << ") :";
			cin >> colonne;
			ok = jeu.jouer(couleur, colonne);
		}
		while(!ok);
	}
};

class JoueurOrdinateur : public Joueur
{
public:
	using Joueur::Joueur;
	virtual void jouer(Jeu& jeu)
	{
		size_t colonne = 0;
		bool ok = false;
		do
		{
			ok = jeu.jouer(couleur, colonne);
			colonne ++;
		}
		while (!ok && colonne < jeu.getLargeur());
	}
};

class Partie()
{
public:
	void addJoueur(Joueur* j)
	{
		if (joueurs.size() < 2)
		{
			joueurs.push_back(j);
		}
	}

	void jouer()
	{
		if (joueur.size() != 2)
			return;

		Jeu jeu(8);
		size_t idx
		while (!jeu.estTermine())
		{

		}
	}
	
private:
	vector<Joueur*> joueurs;
};

int main()
{
	string nom;
	cout << "Quel est votre nom ?";
	cin >> nom;
	JoueurHumain j1(nom, JAUNE);
	JoueurOrdinateur("ordinateur", ROUGE);
	return 0;
}
