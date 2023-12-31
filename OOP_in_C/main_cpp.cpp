#include <stdlib.h>
#include <stdio.h>
#include "shape_cpp.hpp"

#define _SIZE_ 3

int main()
{
    Rectangle rectangle(5.f, 10.f); // length_ = 5.f, width_ = 10.f;
    printf("aera Shape : %f...\n", rectangle.get_aera());
    rectangle.print_data();

    auto p_rectangle = &rectangle; // Rectangle *p_rectangle = &rectangle;
    printf("aera Shape : %f...\n", p_rectangle->get_aera());
    p_rectangle->print_data();

    Shape_cpp *p_shape = &rectangle;
    printf("aera Shape : %f...\n", p_shape->get_aera());
    p_shape->print_data();

    auto tab_shape = new Shape_cpp *[_SIZE_]; 
    // C++ equivalent to Shape_cpp **tab_shape  = (Shape_cpp **) malloc(_SIZE_ * sizeof(Shape_cpp*)) with some additions

    tab_shape[0] = new Rectangle(5, 10);
    tab_shape[1] = new Triangle(5, 12, 15);
    tab_shape[2] = new Circle(20);

    for (int i = 0; i < _SIZE_; ++i)
    {
        printf("aera Shape n° %d : %f...\n", i + 1, tab_shape[i]->get_aera());
        tab_shape[i]->print_data();
    }

    for (int i = 0; i < _SIZE_; ++i)
    {
        delete tab_shape[i];
    }
    delete [] tab_shape;
   
    return EXIT_SUCCESS;
}