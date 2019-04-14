/***************************************************************************************************
Dans cet exercice, nous vous demandons d'élaborer un programme orienté objet de manière
indépendante pour la première fois. Nous avons donc organisé l'exercice en 2 parties :
1. une première (de 2.2 et 2.3) qui décrit le problème à résoudre et qui, idéalement devrait
suffire pour élaborer puis écrire le programme de façon autonome, certainement en
plusieurs tentatives ;
2. une seconde (partie 2.4), pour aider au cas où la première partie vous semble
insuffisante, vu que c'est votre première conception autonome d'un programme. Dans un
premier temps, essayez de ne pas la lire et revenez-y si nécessaire.

Buts du programme
On souhaite ici écrire un programme « simulant » le tour de magie élémentaire suivant :
Un magicien demande à un spectateur d'écrire sur un papier son âge et la somme qu'il a
en poche (moins de 100 francs).
Il lui demande ensuite de montrer le papier à son assistant, qui doit le lire (sans rien
dire), puis effectuer secrètement le calcul suivant :
* multiplier l'âge par 2,
* lui ajouter 5,
* multiplier le résultat par 50,
* ajouter la somme en poche,
* et soustraire le nombre de jours que contient une année,
* puis finalement donner le résultat à haute voix.
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
le faire évoluer pour se rapprocher de la situation « réelle » décrite.

Exemple de déroulement
[Spectateur] (j'entre en scène)
Quel âge ai-je ? 35
Combien d'argent ai-je en poche (<100) ? 112
Combien d'argent ai-je en poche (<100) ? 12
[Spectateur] (je suis là)
[Magicien] un petit tour de magie...
[Spectateur] (j'écris le papier)
[Spectateur] (je montre le papier)
[Assistant] (je lis le papier)
[Assistant] (je calcule mentalement)
[Assistant] J'annonce : 3397 !
[Magicien]
- hum... je vois que vous êtes agé de 35 ans
et que vous avez 12 francs en poche !
***************************************************************************************************/
#include <iostream>

using namespace std;

class Papier
{
public:
    void ecrit(int age, int argent) { m_age = age; m_argent = argent; }
    void lit(int& age, int& argent) const { age = m_age; argent = m_argent; }

private:
    int m_age;
    int m_argent;
};

class Personne
{
public:
    Personne(const string& type) : m_type(type) {}
    void log(const string& message) const { cout << "[" << m_type << "]:" << message << endl; }

private:
    const string m_type;
};

class Spectateur : public Personne
{
public:
    Spectateur();
    // used for debugging
    Spectateur(int age, int argent);
    void ecrit(Papier& papier) const;

private:
    int m_age;
    int m_argent;
};

class Assistant : public Personne
{
public:
    Assistant() : Personne("Assistant") {}
    int lit(const Papier& papier) const;

private:
    int calcule(int age, int argent) const;
};

class Magicien : public Personne
{
public:
    Magicien() : Personne("Magicien") { log("un petit tour de magie..."); }
    void magie(int valeur) const;
};


Spectateur::Spectateur() :
    Personne("Spectateur")
{
    log("j'entre en scène");
    cout << "Quel âge ai-je ?" << endl;
    cin >> m_age;
    do {
        cout << "Combien d'argent ai-je en poche (<100) ?" << endl;
        cin >> m_argent;
    } while (m_argent < 0 || m_argent >= 100);
}

Spectateur::Spectateur(int age, int argent) :
    Personne("Spectateur"), m_age(age), m_argent(argent)
{}

void Spectateur::ecrit(Papier& papier) const
{
    log("j'écris le papier");
    papier.ecrit(m_age, m_argent);
}

int Assistant::lit(const Papier& papier) const
{
    log("je lis le papier");
    int age, argent;
    papier.lit(age, argent);
    return calcule(age, argent);
}

int Assistant::calcule(int age, int argent) const
{
   log("je calcule mentalement");
   int valeur = (((age * 2) + 5) * 50) + argent - 365;
   log("j'annonce : " + to_string(valeur));
   return valeur;
};

void Magicien::magie(int valeur) const
{
    valeur += 115;
    int age = valeur / 100;
    int argent = valeur % 100;
    log("hum... je vois que vous êtes agé de " + to_string(age) + " ans et que vous avez "
        + to_string(argent) + " francs en poche !");
}


int main()
{
    Papier p;
    //Spectateur s;
    Spectateur s(34, 12);
    Magicien m;
    s.ecrit(p);

    Assistant a;
    int valeur = a.lit(p);

    m.magie(valeur);

    return 0;
}
