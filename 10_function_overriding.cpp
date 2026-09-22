// Program 10: Function Overriding
// Unit II - Function overriding with virtual and override
// Compile: g++ -std=c++17 -Wall program10.cpp -o program10

#include <iostream>

class Vehicle {
public:
     // virtual: the version to run is chosen by the real object type.
     virtual void move() const {
         std::cout << "Vehicle is moving\n";
     }

     // Virtual destructor: needed when objects are deleted through a base pointer.
     virtual ~Vehicle() = default;
};

class Car : public Vehicle {
public:
     // override: the compiler checks that this really overrides the base function.
     void move() const override {
         std::cout << "Car moves on roads\n";
     }
};

class Boat : public Vehicle {
public:
     void move() const override {
         std::cout << "Boat moves on water\n";
     }
};

int main() {
     Car car;
     Boat boat;

     car.move();
     boat.move();
     return 0;
}
