#include <stdlib.h>
#include "bad_assert.h"
#include "shape_bis.h"

void print_data_square_bis(const Shape_bis *shape_bis){
   Rectangle_data *data = (Rectangle_data *)shape_bis->shape_data;
   printf("Shape type : Square with side : %f\n",
          data->length);
}

Shape_bis *create_square_bis(float length_side)
{
    Shape_bis *shape = create_rectangle_bis(length_side, length_side);
    shape->print_data = &print_data_square_bis;
    return shape;
}