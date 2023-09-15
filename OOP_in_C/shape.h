#pragma once
#include <stdio.h>


typedef enum Shape_type
{
    Rectangle,
    Triangle,
    Circle,
    Square_as_Shape
} Shape_type;

typedef struct Shape
{
    void *shape_data;
    Shape_type shape_type;
} Shape;

typedef struct Rectangle_data
{
    float length;
    float width;
} Rectangle_data;

typedef struct Triangle_data
{
    float length_side1;
    float length_side2;
    float length_side3;
} Triangle_data;

typedef struct Circle_data
{
    float radius;
} Circle_data;

typedef struct Square_as_Shape_data
{
    float length;
} Square_as_Shape_data;


Shape *create_rectangle(float length, float width);
Shape *create_triangle(float length_side1, float length_side2, float length_side3);
Shape *create_circle(float radius);

Shape *create_Square_as_Shape(float length);
Shape *create_Square_as_Rectangle(float length);


void delete_shape(Shape **shape);

void check_pointer_Shape(const Shape *shape);

float get_aera_rectangle_base(const Shape *shape);
float get_aera_triangle_base(const Shape *shape);
float get_aera_circle_base(const Shape *shape);
float get_aera_square_as_shape_base(const Shape *shape);



void print_data_rectangle_base(const Shape *shape);
void print_data_triangle_base(const Shape *shape);
void print_data_circle_base(const Shape *shape);
void print_data_square_as_shape_base(const Shape *shape);


float get_aera(const Shape *shape);
void print_data(const Shape *shape);

