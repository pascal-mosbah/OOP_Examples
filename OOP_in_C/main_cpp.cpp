#include <stdlib.h>
#include <stdio.h>
#include "shape_cpp.hpp"

#define _SIZE_ 3

int main()
{
    auto tab_shape = new Shape_cpp*[_SIZE_]; // Not (so) equivalent to Shape_cpp **tab_shape  = (Shape_cpp **) malloc(_SIZE_ * sizeof(Shape_cpp*))
   
    tab_shape[0] = new Rectangle(5, 10);
    tab_shape[1] = new Triangle(5, 12, 15);
    tab_shape[2] = new Circle(20);

    for (int i = 0; i < _SIZE_; ++i)
    {
        printf("aera Shape n° %d : %f...\n", i + 1, tab_shape[i]->get_aera());
        tab_shape[i]->print_data();
    }
}