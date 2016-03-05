#!/usr/bin/env python3
""" s01d02 tirelire """

class Tirelire:
    """ models a tirelire """

    def __init__(self):
        self.empty()

    def empty(self):
        """Set amount to null"""
        self.amount = 0.0

    def __str__(self):
        if self.amount > 0.0:
            return "Vous avez " + str(self.amount) + "euros dans la tirelire"
        else:
            return "Vous etes pauvre"

    def shuffle(self):
        """Produce sound"""
        if self.amount > 0.0:
            print("Bing bing")

    def add(self, amount):
        """Add a positive amout to the content"""
        if amount > 0.0:
            self.amount += amount

    def take(self, amount):
        """Take a positive amout from the content and eventually empties it"""
        if amount > 0.0:
            if self.amount-amount > 0:
                self.amount -= amount
            else:
                self.empty()

    def get_solde(self, budget):
        """Evaluate the remaining solde of a valid budget"""
        if budget < 0.0:
            budget = 0.0
        return self.amount - budget

    def enough_budget(self, budget):
        """Evaluate the possibility to spend a budget"""
        enough = False
        solde = self.get_solde(budget)
        if solde >= 0.0:
            enough = True
        else:
            solde = -solde # we return a positive value
        return enough, solde

def main():
    """test function for Tirelire"""

    piggy = Tirelire()
    piggy.shuffle()
    print(piggy)

    piggy.take(20.0)
    piggy.shuffle()
    print(piggy)

    piggy.add(550.0)
    piggy.shuffle()
    print(piggy)

    piggy.take(10.0)
    piggy.take(5.0)
    print(piggy)

    budget = float(input("Donnez le budget de vos vacances : "))
    enough, solde = piggy.enough_budget(budget)

    if enough:
        print("Vous êtes assez riche pour partir en vacances !"
              + "Il vous restera " + str(solde) + " euros à la rentrée.")
        piggy.take(budget)
    else:
        print("Il vous manque " + str(solde)
              + " euros pour partir en vacances !")


if __name__ == "__main__":
    main()
