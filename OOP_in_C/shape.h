#pragma once
#include <stdio.h>


typedef enum Shape_type
{
    Rectangle,
    Triangle,
    Circle
} Shape_type;

typedef struct Shape
{
    void *shape_data;
    Shape_type shape_type;
} Shape;

typedef struct Rectangle_data
{
    float lenght_side1;
    float lenght_side2;
} Rectangle_data;

typedef struct Triangle_data
{
    float lenght_side1;
    float lenght_side2;
    float lenght_side3;
} Triangle_data;

typedef struct Circle_data
{
    float radius;
} Circle_data;

Shape *create_rectangle(float lenght_side1, float lenght_side2);
Shape *create_triangle(float lenght_side1, float lenght_side2, float lenght_side3);
Shape *create_circle(float radius);

void check_pointer_Shape(const Shape *shape);

float get_surface_rectangle_base(const Shape *shape);
float get_surface_triangle_base(const Shape *shape);
float get_surface_circle_base(const Shape *shape);
void print_data_rectangle_base(const Shape *shape);
void print_data_triangle_base(const Shape *shape);
void print_data_circle_base(const Shape *shape);


float get_surface(const Shape *shape);
void print_data(const Shape *shape);

