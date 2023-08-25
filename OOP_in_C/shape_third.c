#include <stdlib.h>
#include "bad_assert.h"
#include "shape_bis.h"

void print_data_square_bis(const Shape_bis *shape_bis){
   Rectangle_data *data = (Rectangle_data *)shape_bis->shape_data;
   printf("Shape type : Square with side : %f\n",
          data->lenght_side1);
}

Shape_bis *create_square_bis(float lenght_side)
{
    Shape_bis *shape = create_rectangle_bis(lenght_side, lenght_side);
    shape->print_data = &print_data_square_bis;
    return shape;
}