#pragma once

struct Shape_cpp
{
    virtual float get_aera() = 0;
    virtual void print_data() = 0;
};

struct Rectangle : Shape_cpp
{
    float length_;
    float width_;
    float get_aera();
    void print_data();
    Rectangle(const float &length, const float &width);
};

struct Triangle : Shape_cpp
{
    float length_side1_;
    float length_side2_;
    float length_side3_;
    float get_aera();
    void print_data();
    Triangle(const float &length_side1, const float &length_side2,
             const float &length_side3);
};

struct Circle : Shape_cpp
{
    float radius_;
    float get_aera();
    void print_data();
    Circle(const float &radius);
};