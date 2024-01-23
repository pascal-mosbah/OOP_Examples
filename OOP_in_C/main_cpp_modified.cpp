#include <stdlib.h>
#include <stdio.h>
#include "shape_cpp.hpp"

//#define _SIZE_ 5

int main()
{
    const int const_size = 5;
    
    auto tab_shape = new Shape_cpp *[const_size]; 
    // C++ equivalent to Shape_cpp **tab_shape  = (Shape_cpp **) malloc(_SIZE_ * sizeof(Shape_cpp*)) with some additions

    tab_shape[0] = new Rectangle(5, 10);
    tab_shape[1] = new Triangle(5, 12, 15);
    tab_shape[2] = new Circle(20);
    tab_shape[3] = new Square_as_shape(20);
    tab_shape[4] = new Square_as_rectangle(20);

    for (int i = 0; i < const_size; ++i)
    {
        printf("aera Shape n° %d : %f...\n", i + 1, tab_shape[i]->get_aera());
        tab_shape[i]->print_data();
    }

    for (int i = 0; i < const_size; ++i)
    {
        delete tab_shape[i];
    }
    delete [] tab_shape;
   
    return EXIT_SUCCESS;
}
