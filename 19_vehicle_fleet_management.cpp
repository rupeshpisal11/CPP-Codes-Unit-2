// Program 19: Vehicle Fleet Management (Real-Time Application)
// Unit II - Inheritance, overriding, base-class pointers
// Compile: g++ -std=c++17 -Wall program19.cpp -o program19

#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

// Base class with data and behaviour common to every fleet vehicle.
class Vehicle {
protected:
     string vehicleId;
     string registrationNumber;
     double fuelLevel;

public:
     Vehicle(string vid, string reg)
         : vehicleId(vid), registrationNumber(reg), fuelLevel(100.0) {}

     // Non-virtual: the same behaviour for every vehicle.
     void startEngine() const {
         cout << "Vehicle " << vehicleId << " engine started." << endl;
     }

     // Fuel level is capped at 100%.
     void refuel(double amount) {
         fuelLevel += amount;
         if (fuelLevel > 100.0) {
             fuelLevel = 100.0;
         }
     }

     // virtual: derived classes override it to add their own details.
     virtual void displayInfo() const {
         cout << "Vehicle ID: " << vehicleId
             << " | Registration: " << registrationNumber
             << " | Fuel: " << fuelLevel << "%" << endl;
     }

     virtual ~Vehicle() = default;
};

// Truck adds cargo capacity.
class Truck : public Vehicle {
private:
     double cargoCapacity;

public:
     Truck(string vid, string reg, double capacity)
         : Vehicle(vid, reg), cargoCapacity(capacity) {}

     void displayInfo() const override {
         cout << "Truck | ";
         // Call the base version first, then print the Truck-specific data.
         Vehicle::displayInfo();
         cout << "Cargo capacity: " << cargoCapacity << " tonnes" << endl;
     }
};

class DeliveryVan : public Vehicle {
private:
     int packageCount;

public:
     DeliveryVan(string vid, string reg, int packages)
         : Vehicle(vid, reg), packageCount(packages) {}

     void displayInfo() const override {
         cout << "Delivery Van | ";
         Vehicle::displayInfo();
         cout << "Packages loaded: " << packageCount << endl;
     }
};

// Bike adds an optional delivery box.
class Bike : public Vehicle {

private:
     bool hasDeliveryBox;

public:
     Bike(string vid, string reg, bool hasBox)
         : Vehicle(vid, reg), hasDeliveryBox(hasBox) {}

     void displayInfo() const override {
         cout << "Delivery Bike | ";
         Vehicle::displayInfo();
         cout << "Delivery box: " << (hasDeliveryBox ? "Available" : "Not available") << endl;
     }
};

int main() {
     // One container holds different vehicle types.
     vector<unique_ptr<Vehicle>> fleet;
     fleet.push_back(make_unique<Truck>("V001", "MH12-AB-1234", 10.5));
     fleet.push_back(make_unique<DeliveryVan>("V002", "MH12-CD-5678", 50));
     fleet.push_back(make_unique<Bike>("V003", "MH12-EF-9012", true));

     cout << "=== Fleet Status ===" << endl;
     for (const auto& vehicle : fleet) {
         vehicle->startEngine();
         // Chooses the Truck, DeliveryVan or Bike version at run time.
         vehicle->displayInfo();
         cout << endl;
     }
}
