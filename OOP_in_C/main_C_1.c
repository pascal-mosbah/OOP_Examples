#include <stdlib.h>
#include "bad_assert.h"
#include "shape.h"
#include "shape_bis.h"

#define _SIZE_ 3

int main()
{
    /* First version using additionnal functions acting on a Structure of type Shape */
    Shape **tab_shape = (Shape **)malloc(_SIZE_ * sizeof(Shape *));
    _ASSERT_(tab_shape);
    
    tab_shape[0] = create_rectangle(5, 10);
    tab_shape[1] = create_triangle(5, 12, 15);
    tab_shape[2] = create_circle(20);

    for (int i = 0; i < _SIZE_; ++i)
    {
        printf("aera Shape n° %d : %f...\n", i + 1, get_aera(tab_shape[i]));
        print_data(tab_shape[i]);
    }

    printf("\n*******************************************\n");
}