#include <iostream>
using namespace std;

class A
{
public:
    A()
    {
        x = 0;
        cout << "1";
    }
    A(int px)
    {
        x = px;
        cout << "2";
    }
    A(const A &pa)
    {
        x = pa.x;
        cout << "3";
    }

/*
    A operator=(const A& other){
        cout << "9";
        return A(other);
    }
*/
protected:
    int x;
};

class B
{
public:
    B(const A &pa = A()) : a(pa) { cout << "4"; }
    B(const A &pa, int py)
    {
        a = pa;
        y = py;
        cout << "5";
    }

protected:
    A a;
    int y;
};

class C : public B
{
public:
    C(int pz = 1)
    {
        z = pz;
        cout << "6";
    }
    C(A pa) : B(pa)
    {
        z = 0;
        cout << "7";
    }
    C(const B &pb) : B(pb), a(1)
    {
        z = 0;
        cout << "8";
    }

protected:
    A a;
    int z;
};

int main()
{
    cout << "-- A --\n";
    A a0;
    cout << endl;
    A a1(3);
    cout << endl;
    A a2(a1);
    cout << endl;
    A a3 = a2;
    cout << endl;
    a3 = a1;
    cout << endl;
    cout << "-- B --\n";
    B b0(a0, 3);
    cout << endl;
    B b1(a1);
    cout << endl;
    B b2;
    cout << endl;
    cout << "-- C --\n";
    C c0;
    cout << endl;
    C c1(a1);
    cout << endl;
    C c2(b2);
    cout << endl;
}
