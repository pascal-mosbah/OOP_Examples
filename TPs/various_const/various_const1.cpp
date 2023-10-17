#pragma once
class Shape
{
private:
    const int id_; // index to be initialized
protected:
    int color_;
    int getId();
//    Shape(const int &id) : id_(id) {}

public:
    // constructor
    int get_color();
    void set_color();
};

class Circle : public Shape
{
private:
    float radius_;

public:
    // constructor

//    Circle() : Shape(1) {}

    float get_radius();
    void set_radius(const float &);
    float get_area();
    float get_perimeter();
    void print();
};

int main()
{
    Circle c;
}