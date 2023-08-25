#include <stdlib.h>
#define _USE_MATH_DEFINES // for C with VS
#include <math.h>
#include "bad_assert.h"
#include "shape.h"

static Shape *allocate_shape(Shape_type shape_type)
{
   Shape *shape = (Shape *)malloc(sizeof(Shape));
   _ASSERT_(shape);
   shape->shape_type = shape_type;
   shape->shape_data = NULL;
   return shape;
}

Shape *create_rectangle(float lenght_side1, float lenght_side2)
{
   Shape *shape = allocate_shape(Rectangle);
   Rectangle_data *data = (Rectangle_data *)malloc(sizeof(Rectangle_data));
   _ASSERT_(data);
   data->lenght_side1 = lenght_side1;
   data->lenght_side2 = lenght_side2;
   shape->shape_data = (void *)data;
   return shape;
}

Shape *create_triangle(float lenght_side1, float lenght_side2,
                       float lenght_side3)
{
   Shape *shape = allocate_shape(Triangle);
   Triangle_data *data = (Triangle_data *)malloc(sizeof(Triangle_data));
   _ASSERT_(data);
   data->lenght_side1 = lenght_side1;
   data->lenght_side2 = lenght_side2;
   data->lenght_side3 = lenght_side3;
   shape->shape_data = (void *)data;
   return shape;
}

Shape *create_circle(float radius)
{
   Shape *shape = allocate_shape(Circle);
   Circle_data *data = (Circle_data *)malloc(sizeof(Triangle_data));
   _ASSERT_(data);
   data->radius = radius;
   shape->shape_data = (void *)data;
   return shape;
}

void check_pointer_Shape(const Shape *shape)
{
   _ASSERT_(shape);
   _ASSERT_(shape->shape_data);
}

float get_surface_rectangle_base(const Shape *shape)
{
   Rectangle_data *data = (Rectangle_data *)shape->shape_data;
   return data->lenght_side1 * data->lenght_side2;
}

float get_surface_triangle_base(const Shape *shape)
{
   Triangle_data *data = (Triangle_data *)shape->shape_data;
   float a = data->lenght_side1;
   float b = data->lenght_side2;
   float c = data->lenght_side2;
   float d = (a + b + c) / 2.f;
   return sqrtf(d * (d - a) * (d - b) * (d - c));
}

float get_surface_circle_base(const Shape *shape)
{
   Circle_data *data = (Circle_data *)shape->shape_data;
   float radius = data->radius;
   return (float)M_PI * radius * radius;
}

void print_data_rectangle_base(const Shape *shape)
{
   Rectangle_data *data = (Rectangle_data *)shape->shape_data;
   printf("Shape type : Rectangle with sides : %f %f\n",
          data->lenght_side1, data->lenght_side2);
}
void print_data_triangle_base(const Shape *shape)
{
   Triangle_data *data = (Triangle_data *)shape->shape_data;
   printf("Shape type : Triangle with sides : %f %f %f\n",
          data->lenght_side1, data->lenght_side2, data->lenght_side3);
}
void print_data_circle_base(const Shape *shape)
{
   Circle_data *data = (Circle_data *)shape->shape_data;
   printf("Shape type : Circle with radius : %f\n",
          data->radius);
}

float get_surface(const Shape *shape)
{
   check_pointer_Shape(shape);
   switch (shape->shape_type)
   {
   case Rectangle:
   {
      return get_surface_rectangle_base(shape);
   }
   case Triangle:
   {
      return get_surface_triangle_base(shape);
   }
   case Circle:
   {
      return get_surface_circle_base(shape);
   }
   default:
      _ASSERT_(0);
   }
}

void print_data(const Shape *shape)
{
   check_pointer_Shape(shape);
   switch (shape->shape_type)
   {
   case Rectangle:
   {
      print_data_rectangle_base(shape);
      break;
   }
   case Triangle:
   {
      print_data_triangle_base(shape);
      break;
   }
   case Circle:
   {
      print_data_circle_base(shape);
      break;
   }
   default:
      _ASSERT_(0);
   }
}