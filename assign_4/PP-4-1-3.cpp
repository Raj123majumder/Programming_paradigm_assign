#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const double PI = 3.14;

class Shape {
public:
    virtual void read() = 0;
    virtual double calc_area() = 0;
};

class Triangle : public Shape {
    double Base;
    double Height;

public:
    Triangle() : Base(0), Height(0) {}
    Triangle(const double base, const double height) : Base(base), Height(height) {}
    double calc_area() {
        return 0.5 * Base * Height;
    }
    void read();
};

void Triangle::read() {
    cout << "Enter Base: ";
    cin >> Base;
    cout << "Enter Height: ";
    cin >> Height;
}

class Rectangle : public Shape {
    double Length;
    double Breadth;

public:
    Rectangle() : Length(0), Breadth(0) {}
    Rectangle(const double length, const double breadth) : Length(length), Breadth(breadth) {}
    double calc_area()
    {
        return Length * Breadth;
    }

    void read();
};

void Rectangle::read() {
    cout << "Enter Length: ";
    cin >> Length;
    cout << "Enter Breadth: ";
    cin >> Breadth;
}

class Circle : public Shape {
    double Radius;

public:
    Circle() : Radius(0) {}
    Circle(const double radius) : Radius(radius) {}
    double calc_area() {
        return PI * Radius * Radius;
    }
    void read();
};

void Circle::read() {
    cout << "Enter Radius: ";
    cin >> Radius;
}

int main() {
    float total_area = 0;
    Shape *shape_ptr[3];

    shape_ptr[0] = new Triangle(rand() % 10 + 1, rand() % 10 + 1);

    shape_ptr[1] = new Rectangle(rand() % 10 + 1, rand() % 10 + 1);

    shape_ptr[2] = new Circle(rand() % 10 + 1);

    for (int i = 0; i < 3; i++) {
        total_area += shape_ptr[i]->calc_area();
    }

    cout << "Sum of Areas: " << total_area << endl;
    return 0;
}
