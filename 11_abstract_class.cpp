// Program 11: Abstract Class
// Unit II - Abstract class and pure virtual function
// Compile: g++ -std=c++17 -Wall program11.cpp -o program11

#include <iostream>

class Shape {
public:
     // Pure virtual function: makes Shape abstract, so Shape objects cannot be created.
     virtual double area() const = 0;
     virtual ~Shape() = default;
};

// Concrete class: it implements every pure virtual function of Shape.
class Rectangle : public Shape {
private:
     double length;
     double width;

public:
     Rectangle(double givenLength, double givenWidth)
         : length(givenLength), width(givenWidth) {}

     double area() const override {
         return length * width;
     }
};

// Another concrete class with its own area formula.
class Circle : public Shape {
private:
     double radius;

public:
     explicit Circle(double givenRadius) : radius(givenRadius) {}

     double area() const override {
         // Value of pi.
         return 3.141592653589793 * radius * radius;
     }

};

int main() {
     Rectangle rectangle(5.0, 3.0);
     Circle circle(2.0);

     std::cout << "Rectangle Area: " << rectangle.area() << '\n';
     std::cout << "Circle Area: " << circle.area() << '\n';
     return 0;
}
