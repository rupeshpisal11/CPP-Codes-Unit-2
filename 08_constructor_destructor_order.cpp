// Program 08: Constructor and Destructor Order
// Unit II - Object lifecycle in inheritance
// Compile: g++ -std=c++17 -Wall program08.cpp -o program08

#include <iostream>

class Base {
public:
     // Constructors run from base to derived.
     Base() {
         std::cout << "Base constructor\n";
     }

     // Destructors run in the reverse order: derived first, then base.
     ~Base() {
         std::cout << "Base destructor\n";
     }
};

class Derived : public Base {
public:
     Derived() {
         std::cout << "Derived constructor\n";
     }

     ~Derived() {
         std::cout << "Derived destructor\n";
     }
};

int main() {
     // Creating the object prints both constructor messages; leaving main() prints both destructor messages.
     Derived object;
     return 0;
}
