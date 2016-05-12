/* sO2e08

Un supermarché souhaite que vous l’aidiez à afficher le total des achats
enregistrés par ses caisses. Il s’agit de compléter le programme supermarche.cc
fourni sur le site du cours. Voici les entités nécessaires pour modéliser le
fonctionnement du supermarché :
- les articles vendus : caractérisés par leur nom (une chaîne de caractères),
leur prix unitaire (un double) et un booléen indiquant si l’article est en solde
ou pas (en Suisse, on dit «en action») ;
- les achats : un achat est caractérisé par l’article acheté et la quantité
achetée de cet article;
- les caddies : caractérisés par l’ensemble des achats qu’ils contiennent ;
- les caisses : chargées de scanner et enregistrer le contenu des caddies ; une
caisse est caractérisée par un numéro de caisse (un entier) et le montant total
des achats qu’elle a scanné (un double).

Le programme principal fourni sur le site du cours a pour but de faire afficher
le montant total de chaque caisse au bout d’une journée donnée. Commencer par
l’étudier.

Coder ensuite les structures de données et les méthodes manquantes.
Ces entités doivent pouvoir être testées avec le programme principal fourni.
Dans ce fichier, déclarer les classes nécessaires à la modélisation du
supermarché, telles que suggérées ci-dessus.

Il est suggéré d'utiliser un vector d'achats pour modéliser le contenu du
caddie. Faire bien attention à l'encapsulation (e.g. les attributs doivent être
privées). Les méthodes à implémenter dans la classe concernant les achats sont :
- afficher(): affichant les caractéristiques de l'article (son nom, son prix
unitaire, la quantité achetée et le prix de l’achat). De plus, si l’article
concerné est en solde, il faudra afficher le texte «(en action)».
	Voici le modèle d’affichage pour afficher() :
	Petit-lait : 2.5 x 6 = 7.5 Frs (en action)
	où Petit-lait est le nom de l’article, 2.5 son prix unitaire, 6 la quantité
	achetée, 7.5 le prix de l’achat et «(en action)» l'indication que l’article
	est en solde. Cette indication ne doit évidemment apparaitre que si
	l’article est en solde.
- toute autre méthode vous semblant nécessaire.

Pour les caddies :
- remplir(..) conforme au programme principal fourni.
Réfléchissez à comment stocker le contenu du caddie (qui sera scanné par la
suite).
- toute autre méthode vous semblant nécessaire.

Pour les caisses :
- afficher() qui affiche son numéro et la valeur de son champ montant total
selon la forme de l’exemple suivant :
	La caisse 1 a encaisse 121.15 Frs aujourd'hui.
	où 1 est le numéro de la caisse et 121.15 le montant total. Vous supposerez
	que ce montant total est stocké comme attribut (et qu'il est mis à jour par
	la méthode scanner(..), ci-dessous).
- scanner(...) : cette méthode, qui doit être conforme au programme principal
fourni, permet à la caisse d’afficher le ticket de caisse correspondant au
contenu du caddie. Cette méthode doit aussi mettre à jour le montant total
de la caisse en y ajoutant le montant des achats du caddie.

L’affichage du ticket de caisse doit se faire selon le modèle ci-dessous et doit
utiliser la méthode afficher précédemment codée.

--------------------------------------------------------------------------------
Exemple de déroulement
Une fois le programme complété, l'exécution du programme principal devrait
ressembler à ceci :
Chou-fleur extra : 3.5 x 2 = 7 F
C++ en trois jours : 48.5 x 1 = 48.5 F
Cookies de grand-mere : 3.2 x 4 = 12.8 F
Petit-lait : 2.5 x 6 = 7.5 F (en action)
Sardines : 6.5 x 2 = 13 F
-----
Total à payer : 88.8 F.
=========================================
Les malheurs de Sophie : 16.5 x 1 = 8.25 F (en action)
Cremeux 100%MG : 5.8 x 1 = 5.8 F
Pois surgeles : 4.35 x 2 = 8.7 F
Poires Williams : 4.8 x 2 = 9.6 F
-----
Total à payer : 32.35 F.
=========================================
100% Arabica : 6.9 x 2 = 6.9 F (en action)
Pain d'epautre : 6.9 x 1 = 6.9 F
Cremeux 100%MG : 5.8 x 2 = 11.6 F
-----
Total à payer : 25.4 F.
=========================================
Résultats du jour :
Caisse 1 : 121.15 F
Caisse 2 : 25.4 F
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// =============================================================================
/* Article
- les articles vendus : caractérisés par leur nom (une chaîne de caractères),
leur prix unitaire (un double) et un booléen indiquant si l’article est en solde
ou pas (en Suisse, on dit «en action») ;
*
* Remarques:
* - could this be done in a struct ?
* */

class Article
{
public:
	Article(string const& name, double price, bool inSale = false)
		: _name(name), _price(price), _inSale(inSale) {};
	const string& name() const { return _name; };
	double price() const { return _price; };
	bool inSale() const { return _inSale; };

private:
	const string _name;
	double _price; // la modelisation en const n'a pas de sens, le prix pourrait
	bool _inSale; //très bien changer, alors que le nom ne changera pas.
};

//==============================================================================
/* Achat
- les achats : un achat est caractérisé par l’article acheté et la quantité
achetée de cet article;
Il est suggéré d'utiliser un vector d'achats pour modéliser le contenu du
caddie. Faire bien attention à l'encapsulation (e.g. les attributs doivent être
privées). Les méthodes à implémenter dans la classe concernant les achats sont :
- afficher(): affichant les caractéristiques de l'article (son nom, son prix
unitaire, la quantité achetée et le prix de l’achat). De plus, si l’article
concerné est en solde, il faudra afficher le texte «(en action)».
	Voici le modèle d’affichage pour afficher() :
	Petit-lait : 2.5 x 6 = 7.5 Frs (en action)
	où Petit-lait est le nom de l’article, 2.5 son prix unitaire, 6 la quantité
	achetée, 7.5 le prix de l’achat et «(en action)» l'indication que l’article
	est en solde. Cette indication ne doit évidemment apparaitre que si
	l’article est en solde.
- toute autre méthode vous semblant nécessaire.*/

class Achat
{
public:
	Achat(Article article, int nb) : article(article), nb(nb) {};
	void display() const;
	double total() const { return nb*article.price()/(1 + (int)article.inSale()); };

private:
	Article article;
	unsigned int nb; // réduire le domaine, une valeur négative n'a pas de sens
};

void Achat::display() const
{
	cout << article.name() << " : " << article.price() << " x " << nb << " = "
		<< total() << " Frs" << (article.inSale()?"(en action)":"")
		<< endl;
}

// =============================================================================
/* Caddie
Pour les caddies :
- remplir(..) conforme au programme principal fourni.
Réfléchissez à comment stocker le contenu du caddie (qui sera scanné par la
suite).
- toute autre méthode vous semblant nécessaire. */

class Caddie
{
public:
	//Caddie() {}; --> pas la peine de donner le constructeur, s'il correspond
	//à celui par défault
	void remplir(Article& article, int nb = 1);
	double scanner() const;

private:
	vector<Achat> achats;
};

void Caddie::remplir(Article& article, int nb)
{
	achats.push_back(Achat(article, nb));
}

/* Scanne le contenue du caddie et renvoie le total correspondant
Example:
Les malheurs de Sophie : 16.5 x 1 = 8.25 F (en action)
Cremeux 100%MG : 5.8 x 1 = 5.8 F
Pois surgeles : 4.35 x 2 = 8.7 F
Poires Williams : 4.8 x 2 = 9.6 F
-----
Total à payer : 32.35 F.*/
double Caddie::scanner() const
{
	double total = 0.0;

	for (size_t i = 0; i < achats.size(); ++i)
	{
		achats[i].display();
		total += achats[i].total();
	}

	return total;
}

// =============================================================================
/* Caisse
Pour les caisses :
- afficher() qui affiche son numéro et la valeur de son champ montant total
selon la forme de l’exemple suivant :
	La caisse 1 a encaisse 121.15 Frs aujourd'hui.
	où 1 est le numéro de la caisse et 121.15 le montant total. Vous supposerez
	que ce montant total est stocké comme attribut (et qu'il est mis à jour par
	la méthode scanner(..), ci-dessous).
- scanner(...) : cette méthode, qui doit être conforme au programme principal
fourni, permet à la caisse d’afficher le ticket de caisse correspondant au
contenu du caddie. Cette méthode doit aussi mettre à jour le montant total
de la caisse en y ajoutant le montant des achats du caddie.

L’affichage du ticket de caisse doit se faire selon le modèle ci-dessous et doit
utiliser la méthode afficher précédemment codée.
*/

class Caisse
{
public:
	Caisse() : total(0.0) {};
	void scanner(Caddie& caddie);
	void afficher() const;

private:
	double total;
};

void Caisse::scanner(Caddie& caddie)
{
	double totalCaddie = caddie.scanner();
	cout << "-----" << endl;
	cout << "Total à payer : " << totalCaddie << " F." << endl;
	total += totalCaddie;
}

void Caisse::afficher() const
{
	cout << total << " F";
};

// =============================================================================
int main()
{
  // Les articles vendus dans le supermarché
  Article choufleur ("Chou-fleur extra"      ,  3.50 );
  Article roman     ("Les malheurs de Sophie", 16.50, true );
  Article camembert ("Cremeux 100%MG"        ,  5.80 );
  Article cdrom     ("C++ en trois jours"    , 48.50 );
  Article boisson   ("Petit-lait"            ,  2.50, true);
  Article petitspois("Pois surgeles"         ,  4.35 );
  Article poisson   ("Sardines"              ,  6.50 );
  Article biscuits  ("Cookies de grand-mere" ,  3.20 );
  Article poires    ("Poires Williams"       ,  4.80 );
  Article cafe      ("100% Arabica"          ,  6.90, true);
  Article pain      ("Pain d'epautre"        ,  6.90 );

  // Les caddies du supermarché, disons 3 ici
  vector<Caddie> caddies(3);

  // Les caisses du supermarché, disons 2
  vector<Caisse> caisses(2);

  // Les clients font leurs achats :
  // le second argument de la méthode remplir correspond à une quantité

  // remplissage du 1er caddie
  caddies[0].remplir(choufleur, 2);
  caddies[0].remplir(cdrom       );
  caddies[0].remplir(biscuits , 4);
  caddies[0].remplir(boisson  , 6);
  caddies[0].remplir(poisson  , 2);

  // remplissage du 2eme caddie
  caddies[1].remplir(roman        );
  caddies[1].remplir(camembert    );
  caddies[1].remplir(petitspois, 2);
  caddies[1].remplir(poires    , 2);

  // remplissage du 3eme caddie
  caddies[2].remplir(cafe     , 2);
  caddies[2].remplir(pain        );
  caddies[2].remplir(camembert, 2);

  // Les clients passent à la caisse :
  caisses[0].scanner(caddies[0]);
  cout << "=========================================" << endl;
  caisses[0].scanner(caddies[1]);
  cout << "=========================================" << endl;
  caisses[1].scanner(caddies[2]);
  cout << "=========================================" << endl;

  // Affichage du résultat des caisses
  cout << "Résultats du jour :" << endl;
  for (size_t i(0); i < caisses.size(); ++i) {
    cout << "Caisse " << i+1 << " : " ;
    caisses[i].afficher();
    cout << endl;
  }

  return 0;
}
