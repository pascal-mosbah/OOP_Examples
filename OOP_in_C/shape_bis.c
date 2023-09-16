#include <stdlib.h>

#define _USE_MATH_DEFINES // for C
#include <math.h>
#include "bad_assert.h"
#include "shape_bis.h"

float get_aera_rectangle_bis(const Shape_bis *shape_bis)
{
    const Shape *shape = (const Shape *)shape_bis;
    check_pointer_Shape(shape);
    return get_aera_rectangle_base(shape);
}

float get_aera_triangle_bis(const Shape_bis *shape_bis)
{
    const Shape *shape = (const Shape *)shape_bis;
    check_pointer_Shape(shape);
    return get_aera_triangle_base(shape);
}

float get_aera_circle_bis(const Shape_bis *shape_bis)
{
    const Shape *shape = (const Shape *)shape_bis;
    check_pointer_Shape(shape);
    return get_aera_circle_base(shape);
}

float get_aera_square_as_shape_bis(const Shape_bis *shape_bis)
{
    const Shape *shape = (const Shape *)shape_bis;
    check_pointer_Shape(shape);
    return get_aera_square_as_shape_base(shape);
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

void print_data_square_as_shape_bis(const Shape_bis *shape_bis)
{
    const Shape *shape = (const Shape *)shape_bis;
    check_pointer_Shape(shape);
    print_data_square_as_shape_base(shape);
}

static Shape_bis *allocate_Shape()
{
    Shape_bis *shape = (Shape_bis *)malloc(sizeof(Shape_bis));
    _ASSERT_(shape);
    shape->shape_data = NULL;
    return shape;
}

Shape_bis *create_rectangle_bis(float length, float width)
{
    Shape_bis *shape = allocate_Shape();
    Rectangle_data *data = (Rectangle_data *)malloc(sizeof(Rectangle_data));
    _ASSERT_(data);
    data->length = length;
    data->width = width;
    shape->shape_data = (void *)data;
    shape->get_aera = &get_aera_rectangle_bis;
    shape->print_data = &print_data_rectangle_bis;
    return shape;
}

Shape_bis *create_triangle_bis(float length_side1, float length_side2,
                               float length_side3)
{
    Shape_bis *shape = allocate_Shape();
    Triangle_data *data = (Triangle_data *)malloc(sizeof(Triangle_data));
    _ASSERT_(data);
    data->length_side1 = length_side1;
    data->length_side2 = length_side2;
    data->length_side3 = length_side3;
    shape->shape_data = (void *)data;
    shape->get_aera = &get_aera_triangle_bis;
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
    shape->get_aera = &get_aera_circle_bis;
    shape->print_data = &print_data_circle_bis;
    return shape;
}


Shape_bis *create_square_as_shape_bis(float length){
    Shape_bis *shape = allocate_Shape();
    Square_as_Shape_data *data = (Square_as_Shape_data *)malloc(sizeof(Square_as_Shape_data));
    _ASSERT_(data);
    data->length = length;
    shape->shape_data = (void *)data;
    shape->get_aera = &get_aera_square_as_shape_bis;
    shape->print_data = &print_data_square_as_shape_bis;
    return shape;

}
Shape_bis *create_square_as_rectangle_bis(float length){
    return create_rectangle_bis(length, length);
}

void delete_shape_bis(Shape_bis **shape)
{
   if (*shape)
   {
      if ((*shape)->shape_data)
      {
         free((*shape)->shape_data);
      }
      free(*shape);
      *shape = NULL;
   }
}