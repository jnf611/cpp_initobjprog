#!/usr/bin/env python3
""" models a 3D triangle """

import point_3d
from point_3d import Point3D


class Triangle3D:
    """ models a 3D triangle """
    def __init__(self):
        self.point = []
        for i in range(0, 3):
            print("Enter coordinates for point " + str(i))
            self.point.append(Point3D())

    def perimeter(self):
        """ compute figure perimeter """
        perimeter = 0.0
        for i in range(0, 3):
            point1 = self.point[i]
            point2 = self.point[(i+1)%3]
            perimeter += point_3d.distance(point1, point2)
        return perimeter

    def isocele(self):
        """ determine if the triangle is isocele """
        distance2 = []
        for i in range(0, 3):
            point1 = self.point[i]
            point2 = self.point[(i+1)%3]
            distance2.append(point_3d.square_distance(point1, point2))

        isocele = ((distance2[0] == distance2[1])
                   or (distance2[1] == distance2[2])
                   or (distance2[2] == distance2[0]))
        return isocele


def main():
    """ test of 3D triangle """
    triangle = Triangle3D()
    print("perimeter: " + str(triangle.perimeter()))
    string = "triangle "
    if triangle.isocele():
        string += "is"
    else:
        string += "is not"
    string += " isocele"
    print(string)


if __name__ == "__main__":
    main()
