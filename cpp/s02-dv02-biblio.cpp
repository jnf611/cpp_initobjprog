#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*******************************************
 * Completez le programme a partir d'ici.
 *******************************************/
//==============================================================================
/* Tools
Uncopyable classe*/

class Uncopyable
{
protected:
	Uncopyable(){}; // allow construction and destruction
	~Uncopyable(){}; // the destructor doesn't need to be virtual as the
	//inheritance is private

private:
	Uncopyable(const Uncopyable&);
	Uncopyable& operator=(const Uncopyable&); // forbids assignment
};

//==============================================================================
/* Auteur
La classe Auteur Un auteur est caractérisé par son nom (une string) ainsi
qu’une indication permettant de savoir s’il a été primé.
Les méthodes qui sont spécifiques à cette classe et font partie de son interface
d’utilisation sont :
— des constructeurs conformes au main fourni, avec l’ordre suivant pour les
paramètres : le nom et l’indication permettant de savoir si l’auteur a été
primé. Par défaut un auteur n’est pas primé ;
— une méthode getNom retournant le nom de l’auteur ;
— une méthode getPrix retournant true si l’auteur a été primé.
Par ailleurs, il ne devra pas être possible de copier un Auteur.*/

class Auteur : private Uncopyable
{
public:
	Auteur(const string& nom, bool prix = false) : nom(nom), prix(prix) {}
	string getNom() const { return nom; }
	bool getPrix() const { return prix; }

	void print() const {cout << nom << ": " << (prix?"":"non ") << "primé" << endl;};
private:
	const string nom;
	bool prix;
};

//==============================================================================
/* Oeuvre
La classe Oeuvre Une Oeuvre est caractérisée par son titre (de type string),
(une référence constante à) l’auteur qui l’a rédigée et la langue dans laquelle elle
a été rédigée (de type string).
Les méthodes qui sont spécifiques à cette classe et font partie de son interface
d’utilisation sont :
— des constructeurs conformes au main fourni, avec l’ordre suivant pour les
paramètres : le titre, la référence à l’auteur et la langue ;
— une méthode getTitre retournant le titre de l’œuvre ;
4
— une méthode getAuteur retournant une référence constante sur l’auteur
(veillez à bien respecter ce type) ;
— une méthode getLangue retournant la langue de l’œuvre ;
— et une méthode affiche affichant les caractéristiques de l’œuvre en respectant
strictement le format suivant :
<titre>, <nom de l’auteur>, en <langue>
où <titre> est à remplacer par le titre de l’œuvre, <nom de l’auteur>,
par le nom de son auteur et <langue> par sa langue ;
— un destructeur affichant un message respectant strictement le format suivant
:
L’oeuvre "<titre>, <nom de l’auteur>, en <langue>" n’est plus
disponible.
Voir l’exemple de déroulement fourni plus bas pour des exemples d’affichage.
Par ailleurs, il ne devra pas être possible de copier une Oeuvre.*/

class Oeuvre : private Uncopyable
{
public:
	Oeuvre(const string& titre, const Auteur& auteur, const string& langue)
	: titre(titre), auteur(auteur), langue(langue) {};
	~Oeuvre()
	{
		cout << "L'oeuvre \"" << titre << ", " << auteur.getNom() << ", en "
			<< langue << "\" n'est plus disponible." << endl;
	}

	const string& getTitre() const { return titre; }
	const Auteur& getAuteur() const { return auteur; }
	const string& getLangue() const { return langue; }

	void affiche() const
	{
		cout << titre << ", " << auteur.getNom() << ", en " << langue;
	}

private:
	const string titre;
	const Auteur& auteur;
	const string langue;
};

//==============================================================================
/* Exemplaire
La classe Exemplaire La classe Exemplaire modélise les exemplaires
d’un œuvre. Une instance de cette classe est caractérisée par (une référence à)
l’œuvre dont elle constitue un exemplaire.
Les méthodes spécifiques à la classe Exemplaire et qui doivent faire partie de
son interface d’utilisation sont :
— un constructeur prenant en argument une référence à une œuvre et affi-
chant un message respectant strictement le format suivant :
Nouvel exemplaire de : <titre>, <nom de l’auteur>, en <langue>
suivi d’un saut de ligne ;
— un constructeur de copie affichant un message respectant strictement le
format suivant :
Copie d’un exemplaire de : <titre>, <nom de l’auteur>
en <langue>
sur une seule ligne terminée par un saut de ligne ;
— d’un destructeur affichant un message respectant strictement le format suivant
:
Un exemplaire de "<titre>, <nom de l’auteur>, en <langue>"
a été jeté !
sur une seule ligne terminée par un saut de ligne ;
— une méthode getOeuvre retournant une référence constante à l’œuvre ;
— et une méthode affiche affichant une description de l’exemplaire respectant
strictement le format suivant :
Exemplaire de : <titre>, <nom de l’auteur>, en <langue>
sans saut de ligne.*/

class Exemplaire
{
public:
	Exemplaire(const Oeuvre& oeuvre) : oeuvre(oeuvre)
	{
		cout << "Nouvel exemplaire de : ";
		oeuvre.affiche();
		cout << endl;
	}
	Exemplaire(const Exemplaire& exemplaire) : oeuvre(exemplaire.getOeuvre())
	{
		cout << "Copie d’un exemplaire de : ";
		oeuvre.affiche();
		cout << endl;
	}
	~Exemplaire()
	{
		cout << "Un exemplaire de \"";
		oeuvre.affiche();
		cout << "\" a été jeté !" << endl;
	}

	const Oeuvre& getOeuvre() const { return oeuvre; }

	void affiche() const
	{
		cout << "Exemplaire de : ";
		oeuvre.affiche();
	}

private:
	const Oeuvre& oeuvre;
};

//==============================================================================
/* Bibliotheque
Une bibliothèque est caractérisée par un nom et
contient un ensemble de pointeurs sur des exemplaires. L’ensemble sera modélisé
au moyen d’un vector.
Les méthodes spécifiques à la classe Bibliotheque et qui font partie de son
interface d’utilisation sont :
— un constructeur conforme au main fourni et affichant le message :
La bibliothèque <nom> est ouverte ! suivi d’un saut de ligne,
où <nom> est à remplacer par le nom de la bibliothèque ;
— une méthode getNom retournant le nom de la bibliothèque ;
— une méthode stocker permettant d’ajouter un ou plusieurs exemplaires
d’une œuvre dans la bibliothèque ; elle doit être conforme au main fourni,
avec l’ordre suivant des paramètres : la référence à une œuvre et le nombre
n d’exemplaires à ajouter, dont la valeur par défaut est 1 ; cette méthode
va ajouter à l’ensemble d’exemplaires de la bibliothèque n exemplaires de
l’œuvre fournie, dynamiquement alloués ; les nouveaux exemplaires devront
impérativement être ajoutés à la fin du tableau dynamique ;
— une méthode lister_exemplaires affichant tous les exemplaires d’une
œuvre écrite dans une langue donnée ; si aucune langue n’est donnée (chaîne
vide), tous les exemplaires de la bibliothèque seront affichés ;
les exemplaires devront être affichés au moyen de la méthode d’affichage
qui leur est spécifique et il y aura un saut de ligne à la fin de l’affichage de
chaque exemplaire (voir l’exemple de déroulement fourni plus bas) ;
— une méthode compter_exemplaires retournant le nombre d’exemplaires
d’une œuvre donnée passée en paramètre ;
— une méthode afficher_auteurs prenant en paramètre un booléen
(valant par défaut false) indiquant si l’on veut afficher uniquement les
auteurs à prix ;
cette méthode affichera les noms des auteurs dont un exemplaire est stocké
dans la bibliothèque ; si le booléen vaut true, seuls s’afficheront les
noms des auteurs avec un prix ; un saut de ligne sera fait après l’affichage
de chaque nom ; le nom d’un auteur sera répété autant de fois qu’il y a
d’exemplaires écrits par cet auteur.
— un destructeur qui affiche le message suivant :
La bibliothèque <nom> ferme ses portes,
et détruit ses exemplaires :
où <nom> est le nom de la bibliothèque, puis libère les zones mémoires
liées à ses exemplaires.*/

class Bibliotheque : private Uncopyable
{
public:
	Bibliotheque(const string& nom)
	: nom(nom)
	{
		cout << "La bibliothèque " << nom << " est ouverte !" << endl;
	}
	~Bibliotheque()
	{
		cout << "La bibliothèque " << nom << " ferme ses portes," << endl
			<< "et détruit ses exemplaires :" << endl;
		for (size_t i = 0; i < catalogue.size(); ++i)
		{
			delete catalogue[i];
		}
	}

	const string& getNom() { return nom; };

	void stocker(const Oeuvre& oeuvre, unsigned int nb = 1)
	{
		for (unsigned int i = 0; i < nb; ++i)
		{
			Exemplaire* e = new Exemplaire(oeuvre);
			catalogue.push_back(e);
		}
	}
	void lister_exemplaires(const string& langue = "")
	{
		for (size_t i = 0; i < catalogue.size(); ++i)
		{
			Exemplaire* e = catalogue[i];
			if (langue.empty() || langue.compare(e->getOeuvre().getLangue()) == 0)
			{
				e->affiche();
				cout << endl;
			}
		}
	}
	unsigned int compter_exemplaires(const Oeuvre& oeuvre) const
	{
		unsigned int nb = 0;

		for (size_t i = 0; i < catalogue.size(); ++i)
		{
			const Oeuvre& o = catalogue[i]->getOeuvre();
			if ((o.getAuteur().getNom().compare(oeuvre.getAuteur().getNom()) == 0) &&
				(o.getLangue()         .compare(oeuvre.getLangue())          == 0) &&
				(o.getTitre()          .compare(oeuvre.getTitre())           == 0))
			{
				++nb;
			}
		}

		return nb;
	}
	void afficher_auteurs(bool prix = false)
	{
		for (size_t i = 0; i < catalogue.size(); ++i)
		{
			const Auteur& a = catalogue[i]->getOeuvre().getAuteur();
			if(!prix || a.getPrix())
			{
				cout << a.getNom() << endl;
			}
		}
	}

private:
	const string nom;
	vector<Exemplaire*> catalogue;
};

/*******************************************
 * Ne rien modifier apres cette ligne.
 *******************************************/

int main()
{
  Auteur a1("Victor Hugo"),
         a2("Alexandre Dumas"),
         a3("Raymond Queneau", true);

  Oeuvre o1("Les Misérables"           , a1, "français" ),
         o2("L'Homme qui rit"          , a1, "français" ),
         o3("Le Comte de Monte-Cristo" , a2, "français" ),
         o4("Zazie dans le métro"      , a3, "français" ),
         o5("The Count of Monte-Cristo", a2, "anglais" );

  Bibliotheque biblio("municipale");
  biblio.stocker(o1, 2);
  biblio.stocker(o2);
  biblio.stocker(o3, 3);
  biblio.stocker(o4);
  biblio.stocker(o5);

  cout << "La bibliothèque " << biblio.getNom()
       << " offre les exemplaires suivants :" << endl;
  biblio.lister_exemplaires();

  const string langue("anglais");
  cout << " Les exemplaires en "<< langue << " sont :" << endl;
  biblio.lister_exemplaires(langue);

  cout << " Les auteurs à succès sont :" << endl;
  biblio.afficher_auteurs(true);

  cout << " Il y a " << biblio.compter_exemplaires(o3) << " exemplaires de "
       << o3.getTitre() << endl;

  return 0;
}
