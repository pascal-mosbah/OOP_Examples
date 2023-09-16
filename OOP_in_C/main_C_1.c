#include <stdlib.h>
#include "bad_assert.h"
#include "shape.h"

#define _SIZE_ 5

int main()
{
    /* First version using additionnal functions acting on a Structure of type Shape */
    Shape **tab_shape = (Shape **)malloc(_SIZE_ * sizeof(Shape *));
    _ASSERT_(tab_shape);

    tab_shape[0] = create_rectangle(5, 10);
    tab_shape[1] = create_triangle(5, 12, 15);
    tab_shape[2] = create_circle(20);
    tab_shape[3] = create_square_as_shape(20);
    tab_shape[4] = create_square_as_rectangle(20);

    for (int i = 0; i < _SIZE_; ++i)
    {
        printf("aera Shape n° %d : %f...\n", i + 1, get_aera(tab_shape[i]));
        print_data(tab_shape[i]);
    }

    printf("\n*******************************************\n");

    for (int i = 0; i < _SIZE_; ++i)
    {
        delete_shape(&(tab_shape[i]));
    }
    free(tab_shape);
    return EXIT_SUCCESS;
}