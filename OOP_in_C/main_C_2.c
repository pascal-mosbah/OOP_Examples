#include <stdlib.h>
#include "bad_assert.h"
#include "shape.h"
#include "shape_bis.h"

#define _SIZE_ 3

int main()
{

 /* Second version using pointer functions to a Structure of type Shape (bis) */
    Shape_bis **tab_shape_bis = (Shape_bis **)malloc(4 * sizeof(Shape_bis *));
    _ASSERT_(tab_shape_bis);
    tab_shape_bis[0] = create_rectangle_bis(5, 10);
    tab_shape_bis[1] = create_triangle_bis(5, 10, 15);
    tab_shape_bis[2] = create_circle_bis(20);

    for (int i = 0; i < 4; ++i)
    {
        Shape_bis *shape = tab_shape_bis[i];
        printf("aera Shape bis %d : %f...\n", i + 1, shape->get_aera(shape));
        shape->print_data(shape);
    }
    for (int i = 0; i < _SIZE_; ++i)
    {
        delete_shape_bis(&(tab_shape_bis[i]));
    }
    free(tab_shape_bis);
    return EXIT_SUCCESS;
}