#include <stdlib.h>

#define _USE_MATH_DEFINES // for C
#include <math.h>
#include "bad_assert.h"
#include "shape_bis.h"

float get_surface_rectangle_bis(const Shape_bis *shape_bis)
{
    const Shape *shape = (const Shape *)shape_bis;
    check_pointer_Shape(shape);
    return get_surface_rectangle_base(shape);
}

float get_surface_triangle_bis(const Shape_bis *shape_bis)
{
    const Shape *shape = (const Shape *)shape_bis;
    check_pointer_Shape(shape);
    return get_surface_triangle_base(shape);
}

float get_surface_circle_bis(const Shape_bis *shape_bis)
{
    const Shape *shape = (const Shape *)shape_bis;
    check_pointer_Shape(shape);
    return get_surface_circle_base(shape);
}

void print_data_rectangle_bis(const Shape_bis *shape_bis)
{
    const Shape *shape = (const Shape *)shape_bis;
    check_pointer_Shape(shape);
    print_data_rectangle_base(shape);
}
void print_data_triangle_bis(const Shape_bis *shape_bis)
{
    const Shape *shape = (const Shape *)shape_bis;
    check_pointer_Shape(shape);
    print_data_triangle_base(shape);
}
void print_data_circle_bis(const Shape_bis *shape_bis)
{
    const Shape *shape = (const Shape *)shape_bis;
    check_pointer_Shape(shape);
    print_data_circle_base(shape);
}

static Shape_bis *allocate_Shape()
{
    Shape_bis *shape = (Shape_bis *)malloc(sizeof(Shape_bis));
    _ASSERT_(shape);
    shape->shape_data = NULL;
    return shape;
}

Shape_bis *create_rectangle_bis(float lenght_side1, float lenght_side2)
{
    Shape_bis *shape = allocate_Shape();
    Rectangle_data *data = (Rectangle_data *)malloc(sizeof(Rectangle_data));
    _ASSERT_(data);
    data->lenght_side1 = lenght_side1;
    data->lenght_side2 = lenght_side2;
    shape->shape_data = (void *)data;
    shape->get_surface = &get_surface_rectangle_bis;
    shape->print_data = &print_data_rectangle_bis;
    return shape;
}

Shape_bis *create_triangle_bis(float lenght_side1, float lenght_side2,
                               float lenght_side3)
{
    Shape_bis *shape = allocate_Shape();
    Triangle_data *data = (Triangle_data *)malloc(sizeof(Triangle_data));
    _ASSERT_(data);
    data->lenght_side1 = lenght_side1;
    data->lenght_side2 = lenght_side2;
    data->lenght_side3 = lenght_side3;
    shape->shape_data = (void *)data;
    shape->get_surface = &get_surface_triangle_bis;
    shape->print_data = &print_data_triangle_bis;
    return shape;
}

Shape_bis *create_circle_bis(float radius)
{
    Shape_bis *shape = allocate_Shape();
    Circle_data *data = (Circle_data *)malloc(sizeof(Triangle_data));
    _ASSERT_(data);
    data->radius = radius;
    shape->shape_data = (void *)data;
    shape->get_surface = &get_surface_circle_bis;
    shape->print_data = &print_data_circle_bis;
    return shape;
}

