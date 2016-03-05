#!/usr/bin/env python3
""" s01d01 """

class Patient:
    """Patient with a weight and a height"""
    #pylint: disable=too-few-public-methods

    def __init__(self, w, h):
        self.height = 0.0
        self.weight = 0.0
        if (h > 0.0) and (w > 0.0):
            self.height = h
            self.weight = w

    def __str__(self):
        return ("Patient : " + str(self.weight) + " kg pour " + str(self.height)
                + " m")

    def imc(self):
        """ compute patient imc """
        imc = 0.0

        if self.height > 0.0:
            imc = self.weight / (self.height*self.height)

        return imc


def main():
    """test function for Patient class"""

    weight = 0.0
    height = 0.0

    while weight*height == 0:
        user_input = input("Entrez un poids (kg) et une taille (m) : ")
        weight, height = [float(i) for i in user_input.split()]
        quidam = Patient(weight, height)
        print(quidam)
        print("IMC : " + str(quidam.imc()))


if __name__ == "__main__":
    main()
