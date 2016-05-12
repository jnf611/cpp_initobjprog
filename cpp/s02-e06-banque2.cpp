#include <iostream>
#include <string>
#include <vector>
using namespace std;

double tauxCourant(0.01);
double tauxEpargne(0.02);

/*==============================================================================
* Un compte est crée avec un montant nul
*/
class Compte
{
private:
	double taux;
	double solde;
	const string type;
public:
	Compte(double taux, string const& type)
		: taux(taux), solde(0.0), type(type) {};
	const string& get_type() const { return type; };
	void credite(double montant);
	void boucler();
	void display() const;
};

// Credite le compte d'un montant
void Compte::credite(double montant)
{
	solde += montant;
}

// Affiche le solde du compte
void Compte::display() const
{
	cout << "   Compte " << type << ": " << solde << " francs" << endl;
}

// Ajoute les intérêts aux solde du compte
void Compte::boucler()
{
  double interets(taux * solde);
  solde += interets;
}

/*==============================================================================
 * Un client a au moins un compte courant
 */
class Client
{
private:
	const string nom;
	string ville;
	bool masculin;
	vector<Compte> portefeuille;
public:
	Client(string const & nom, string ville, bool masculin = true, double taux = 0.01)
		: nom(nom), ville(ville), masculin(masculin),
		portefeuille(1, Compte(taux, "courant")) {};
	void display() const;
	void credite(string const& type, double montant);
	void boucler();
	void ajouteCompte(string const& type, double taux);
};

// Affiche les données d'un client
void Client::display() const
{
	cout << "Client" << (masculin?"":"e") << " " << nom << " de " << ville << endl;
	for (size_t i = 0; i < portefeuille.size(); ++i)
		portefeuille[i].display();
}

// Cette fonction ajoute les intérêts aux soldes des comptes d'un client
void Client::credite(string const& type, double montant)
{
	for (size_t i = 0; i < portefeuille.size(); ++i)
	{
		if (portefeuille[i].get_type() == type)
			portefeuille[i].credite(montant);
	}
}

// Ajoute les intérêts aux soldes des comptes d'un client
void Client::boucler()
{
	for (size_t i = 0; i < portefeuille.size(); ++i)
		portefeuille[i].boucler();
}

// Ajoute un nouveau compte à un client
// TODO: devrait vérifier qu'il n'existe pas encore
void Client::ajouteCompte(string const& type, double taux)
{
	portefeuille.push_back(Compte(taux, type));
}

/*==============================================================================
 */
class Banque
{
public:
	Banque(): pClient(0) {};
	void ajouteClient(Client* client);
	void display() const;
	void boucler();
private:
	vector<Client*> pClient;
};

void Banque::ajouteClient(Client* c)
{
	pClient.push_back(c);
	cout << "pClient.size():" << pClient.size() << endl;
}

void Banque::display() const
{
	cout << "pClient.size():" << pClient.size() << endl;
	for (size_t i = 0; i < pClient.size(); ++i)
	{
		cout << "i:" << i << endl;
		pClient[i]->display();
	}
}

void Banque::boucler()
{
	for (size_t i = 0; i < pClient.size(); ++i)
		pClient[i]->boucler();
}

/*==============================================================================
 */
int main()
{
	Banque maBank;
	
	// Données pour les 2 clients
	Client client1("Pedro", "Genève", true, 0.01);
	maBank.ajouteClient(&client1);
	client1.credite("courant", 1000.0);
	client1.ajouteCompte("epargne", 0.02);
	client1.credite("epargne", 2000.0);
	Client client2("Alexandra", "Lausanne", false, 0.01);
	maBank.ajouteClient(&client2);
	client2.credite("courant", 2000.0);
	client2.ajouteCompte("epargne", 0.02);
	client2.credite("epargne", 4000.0);
	
	
	// Afficher les données des clients
	cout << "Données avant le bouclement des comptes :" << endl;
	maBank.display();

	// Bouclement des comptes des 2 clients
	maBank.boucler();
  
	// Afficher les données des clients
	cout << "Données apres le bouclement des comptes :" << endl;
	maBank.display();
	
	return 0;
}
