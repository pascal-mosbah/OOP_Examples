from math import sqrt, pi

class Rectangle:
    def __init__(self, length, width):
        self._length = length
        self._width = width

    def get_aera(self):
        return self._length * self._width
    
    def print_data(self):
        print("Shape type : Rectangle with sides : %f %f\n" % (self._length , self._width))

class Triangle:
    def __init__(self, length_side1, length_side2, length_side3):
        self._length_side1 = length_side1
        self._length_side2 = length_side2
        self._length_side3 = length_side3

    def get_aera(self):
        a = self._length_side1
        b = self._length_side2
        c = self._length_side3
        d = (a + b + c) / 2.
        return sqrt(d * (d - a) * (d - b) * (d - c))
    
    def print_data(self):
        print("Shape type : Triangle with sides : %f %f %f\n" % (self._length_side1, self._length_side2, self._length_side3))

class Circle:
    def __init__(self, radius):
        self._radius = radius

    def get_aera(self):
        return pi * self._radius * self._radius
    
    def print_data(self):
        print("Shape type : Circle with radius : %f\n" % self._radius)


list_of_shapes = []
list_of_shapes.append(Rectangle(5, 10))
list_of_shapes.append(Triangle(5, 12, 15))
list_of_shapes.append(Circle(20))

for shape in list_of_shapes:
    print("Aera : %f \n" % (shape.get_aera()))
    shape.print_data()