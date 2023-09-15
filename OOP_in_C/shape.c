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

Shape *create_rectangle(float length, float width)
{
   Shape *shape = allocate_shape(Rectangle);
   Rectangle_data *data = (Rectangle_data *)malloc(sizeof(Rectangle_data));
   _ASSERT_(data);
   data->length = length;
   data->width = width;
   shape->shape_data = (void *)data;
   return shape;
}

Shape *create_triangle(float length_side1, float length_side2,
                       float length_side3)
{
   Shape *shape = allocate_shape(Triangle);
   Triangle_data *data = (Triangle_data *)malloc(sizeof(Triangle_data));
   _ASSERT_(data);
   data->length_side1 = length_side1;
   data->length_side2 = length_side2;
   data->length_side3 = length_side3;
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

Shape *create_Square_as_Shape(float length)
{
   Shape *shape = allocate_shape(Square_as_Shape);
   Square_as_Shape_data *data = (Square_as_Shape_data *) malloc(sizeof(Square_as_Shape_data));
   _ASSERT_(data);
   data->length = length;
   shape->shape_data = (void *)data;
   return shape;
}

Shape *create_Square_as_Rectangle(float length)
{
   Shape *shape = allocate_shape(Square_as_Shape);
  Rectangle_data *data = (Rectangle_data *)malloc(sizeof(Rectangle_data));
   _ASSERT_(data);
   data->length = length;
   data->width = length;
   shape->shape_data = (void *)data;
   return shape;
}


void delete_shape(Shape **shape)
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

void check_pointer_Shape(const Shape *shape)
{
   _ASSERT_(shape);
   _ASSERT_(shape->shape_data);
}

float get_aera_rectangle_base(const Shape *shape)
{
   Rectangle_data *data = (Rectangle_data *)shape->shape_data;
   return data->length * data->width;
}

float get_aera_triangle_base(const Shape *shape)
{
   Triangle_data *data = (Triangle_data *)shape->shape_data;
   float a = data->length_side1;
   float b = data->length_side2;
   float c = data->length_side2;
   float d = (a + b + c) / 2.f;
   return sqrtf(d * (d - a) * (d - b) * (d - c));
}

float get_aera_circle_base(const Shape *shape)
{
   Circle_data *data = (Circle_data *)shape->shape_data;
   float radius = data->radius;
   return (float)M_PI * radius * radius;
}

float get_aera_square_as_shape_base(const Shape *shape)
{
   Square_as_Shape_data *data = (Square_as_Shape_data *)shape->shape_data;
   _ASSERT_(data);
   float length = data->length;
   return length * length;
}

void print_data_rectangle_base(const Shape *shape)
{
   Rectangle_data *data = (Rectangle_data *)shape->shape_data;
   printf("Shape type : Rectangle with sides : %f %f\n",
          data->length, data->width);
}
void print_data_triangle_base(const Shape *shape)
{
   Triangle_data *data = (Triangle_data *)shape->shape_data;
   printf("Shape type : Triangle with sides : %f %f %f\n",
          data->length_side1, data->length_side2, data->length_side3);
}
void print_data_circle_base(const Shape *shape)
{
   Circle_data *data = (Circle_data *)shape->shape_data;
   printf("Shape type : Circle with radius : %f\n",
          data->radius);
}


void print_data_square_as_shape_base(const Shape *shape){
   Square_as_Shape_data *data = (Square_as_Shape_data *)shape->shape_data;
   printf("Shape type : Square as Shape with side lenght : %f\n",
          data->length);
}

float get_aera(const Shape *shape)
{
   check_pointer_Shape(shape);
   switch (shape->shape_type)
   {
   case Rectangle:
   {
      return get_aera_rectangle_base(shape);
   }
   case Triangle:
   {
      return get_aera_triangle_base(shape);
   }
   case Circle:
   {
      return get_aera_circle_base(shape);
   }
      case Square_as_Shape:
   {
      return get_aera_square_as_shape_base(shape);
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
        case Square_as_Shape:
   {
      print_data_square_as_shape_base(shape);
   }
   default:
      _ASSERT_(0);
   }
}