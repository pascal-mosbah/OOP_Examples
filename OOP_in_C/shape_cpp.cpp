#include <stdio.h>
#define _USE_MATH_DEFINES // for C with VS
#include <math.h>
#include "shape_cpp.hpp"

Rectangle::Rectangle(const float &length, const float &width)
{ // or : length_(length), width_(width) {

    this->length_ = length; // or length_ = length; (see below)
    width_ = width;
}

float Rectangle::get_aera()
{
    return length_ * width_;
}

void Rectangle::print_data()
{
    printf("Shape type : Rectangle with sides : %f %f\n",
          length_, width_);
}

Triangle::Triangle(const float &length_side1, const float &length_side2,
                   const float &length_side3) : length_side1_(length_side1), length_side2_(length_side2), length_side3_(length_side3)
{
}

float Triangle::get_aera()
{
    return 0;
}

void Triangle::print_data()
{
     printf("Shape type : Triangle with sides : %f %f %f\n",
         length_side1_, length_side2_, length_side3_);
}

Circle::Circle(const float &radius) : radius_(radius){

}
float Circle::get_aera()
{
    return (float)M_PI * radius_ * radius_;
}

void Circle::print_data()
{
       printf("Shape type : Circle with radius : %f\n",
          radius_);
}

Square_as_shape::Square_as_shape(const float &length){
    length_ = length;
}

float Square_as_shape::get_aera()
{
    return (float)M_PI * length_ * length_;
}

void Square_as_shape::print_data()
{
       printf("Shape type : Square as Shape with side length : %f\n",
          length_);
}

void Square_as_rectangle::print_data()
{
       printf("Shape type : Square as Rectangle with side length : %f\n",
          length_ /*or width_*/);
}


Square_as_rectangle::Square_as_rectangle(const float &length) : Rectangle(length, length){

}