/* s01e02 tour de magie
On souhaite ici écrire un programme « simulant » le tour de magie élémentaire suivant :
Un magicien demande à un spectateur d'écrire sur un papier son âge et la somme qu'il a
en poche (moins de 100 francs).
Il lui demande ensuite de montrer le papier à son assistant, qui doit le lire (sans rien
dire), puis effectuer secrètement le calcul suivant : multiplier l'âge par 2, lui ajouter 5,
multiplier le résultat par 50, ajouter la somme en poche, et soustraire le nombre de jours
que contient une année, puis finalement donner le résultat à haute voix.
En ajoutant mentalement (rapidement !) 115 au chiffre reçu, le magicien trouve tout de
suite l'âge et la somme en poche (qui étaient restés secrets).
Modéliser ce tour de magie, en définissant au moins les classes (simples) Magicien,
Assistant et Spectateur. Il pourrait également être utile de disposer d'une classe
Papier.
L'instance de Spectateur devra demander son âge à l'utilisateur du programme ainsi que la
somme d'argent en poche, et s'assurer qu'une valeur correcte est entrée (entre 0 et 99).
Essayer de faire une modélisation la plus exacte possible ; faire notamment usage des droits
d'accès là où cela semble pertinent. Pour chaque méthode, effectuer un affichage à l'écran de
l'opération en cours et de l'acteur qui la réalise.
Note : Il existe de nombreuses variantes possibles. Commencer par un modèle très simple, et
le faire évoluer pour se rapprocher de la situation « réelle » décrite.*/

#include <iostream>
#include <string>
using namespace std;

class Papier
{
public:
	// getters
	int age()    const {return _age;};
	int argent() const {return _argent;};

	void write(int age, int argent)
	{
		_age = age;
		_argent = argent;
	};

private:
	int _age;
	int _argent;
};


class Personne
{
public:
	Personne(string name):_name(name){};

protected:
	string _name;
	void dit(const char* str) const
	{
		cout << _name << ": " << str << endl;
	}
};

class Spectateur : public Personne
{
public:
	Spectateur():Personne("Spectateur")
	{
		appears();
	};

	void write(Papier& p) const
	{
		dit("j'ecris le papier");
		p.write(_age, _argent);
	};

	static const int max_argent = 100;

private:
	void appears()
	{
		do
		{
			cout << "write your age:? ";
			cin >> _age;
		}
		while (_age <= 0);

		do
		{
			cout << "write your argent (<" << max_argent << "):? ";
			cin >> _argent;
		}
		while (_argent < 0 || _argent >= max_argent);
		dit("j'entre dans la salle");
	}

	int _age;
	int _argent;
};

class Assistant : public Personne
{
public:
	Assistant() : Personne("Assistant"){};

	void lit(const Papier& p)
	{
		dit("je lis le papier");
		_age = p.age();
		_argent = p.argent();
	};

	void calcule()
	{
		dit("je calcule ");
		_nombre_magique = (_age*2 + 5)*50 + _argent - 365;
	};

	int annonce()
	{
		cout << "Assistant: j'ai calcule " <<  _nombre_magique << endl;
		return _nombre_magique;
	};

private:
	int _age;
	int _argent;
	int _nombre_magique;
};

class Magicien : public Personne
{
public:
	Magicien() : Personne("Magicien"){};

	void magie(Assistant& a, Spectateur& s, Papier& p)
	{
		s.write(p);
		a.lit(p);
		a.calcule();
		calcule(a.annonce());
		annonce();
	};

private:
	void calcule(int nombre_magique)
	{
		nombre_magique += 115;
		_age = nombre_magique/Spectateur::max_argent;
		_argent = nombre_magique%Spectateur::max_argent ;
	};

	void annonce() const
	{
		cout << _name << ": vous avez " << _age << " ans et "
			<< _argent << " euros en poche."	<< endl;
	}

	int _age;
	int _argent;

};

int main()
{
	Spectateur s;
	Papier p;
	Assistant a;
	Magicien m;
	m.magie(a, s, p);
}
