// Program 05: Hierarchical Inheritance
// Unit II - Hierarchical inheritance (one base, many derived)
// Compile: g++ -std=c++17 -Wall program05.cpp -o program05

#include <iostream>
#include <string>
#include <utility>

// One common base class for Car and Bike.
class Vehicle {
protected:
     std::string registrationNumber;

public:
     explicit Vehicle(std::string registration)
         : registrationNumber(std::move(registration)) {}

     void start() const {
         std::cout << "Vehicle " << registrationNumber << " started\n";
     }
};

// Hierarchical inheritance: Car and Bike both derive from Vehicle.
class Car : public Vehicle {
public:
     explicit Car(std::string registration) : Vehicle(std::move(registration)) {}

     // Feature that exists only in Car.
     void openBoot() const {

         std::cout << "Car boot opened\n";
     }
};

class Bike : public Vehicle {
public:
     explicit Bike(std::string registration) : Vehicle(std::move(registration)) {}

     // Feature that exists only in Bike.
     void helmetReminder() const {
         std::cout << "Please wear a helmet\n";
     }
};

int main() {
     Car car("MH12AB1234");
     Bike bike("MH12CD5678");

     // Both objects reuse start() from the common base class.
     car.start();
     car.openBoot();

     bike.start();
     bike.helmetReminder();

     return 0;
}
