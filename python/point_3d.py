#!/usr/bin/env python3
""" Models a 3D point """

import math


class Point3D:
    """ 3D point """
    # pylint: disable=too-few-public-methods
    # pylint: disable=invalid-name

    def __init__(self, x=None, y=None, z=None):
        if x is None:
            self.x = float(input("x:"))
            self.y = float(input("y:"))
            self.z = float(input("z:"))
        else:
            self.x = x
            self.y = y
            self.z = z

    def compare(self, p):
        """ test if the point is the same """
        different = ((self.x == p.x) or (self.y == p.y) or (self.z == p.z))
        return not different

    def __str__(self):
        return "(" + str(self.x) + "," + str(self.y) + "," + str(self.z) + ")"


def square_distance(point1, point2):
    """ compute the square distance """
    delta_x = point1.x - point2.x
    delta_y = point1.y - point2.y
    delta_z = point1.z - point2.z
    return delta_x*delta_x + delta_y*delta_y + delta_z*delta_z


def distance(point1, point2):
    """ compute euclidian distance """
    return math.sqrt(square_distance(point1, point2))


def main():
    """ test of 3D point """
    point1 = Point3D(1.0, 2.0, -0.1)
    point2 = Point3D()
    point3 = point1

    print("Point 1 :")
    print(point1)
    print("Point 2 :")
    print(point2)

    string = "Le point 1 est "
    if point1.compare(point2):
        string += "identique au"
    else:
        string += "différent du"
    string += " point 2."
    print(string)

    string = "Le point 1 est "
    if point1.compare(point3):
        string += "identique au"
    else:
        string += "différent du"
    string += " point 3."
    print(string)


if __name__ == "__main__":
    main()
