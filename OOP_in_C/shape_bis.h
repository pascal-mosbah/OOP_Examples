#pragma once
#include "shape.h"

typedef struct Shape_bis
{
    void *shape_data;
    float (*get_surface)(const struct Shape_bis* shape);
    void (*print_data)(const struct Shape_bis* shape);
} Shape_bis;

Shape_bis *create_rectangle_bis(float lenght_side1, float lenght_side2);
Shape_bis *create_triangle_bis(float lenght_side1, float lenght_side2, float lenght_side3);
Shape_bis *create_circle_bis(float radius);

