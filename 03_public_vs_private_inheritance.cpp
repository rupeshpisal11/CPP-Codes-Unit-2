// Program 03: Public versus Private Inheritance
// Unit II - Inheritance modes (public and private)
// Compile: g++ -std=c++17 -Wall program03.cpp -o program03

#include <iostream>

class Base {
public:
     void show() const {
         std::cout << "Base public function\n";
     }
};

// Public inheritance: show() stays public for outside code.
class PublicDerived : public Base {
};

// Private inheritance: show() becomes private inside PrivateDerived.
class PrivateDerived : private Base {
public:
     void callBaseShow() const {
         // Allowed: the derived class can still use the base function internally.
         show();
     }
};

int main() {
     PublicDerived publicObject;
     // Works because show() is still public.
     publicObject.show();

     PrivateDerived privateObject;
     // Only this wrapper function is reachable from outside.
     privateObject.callBaseShow();

    // privateObject.show(); // Error: show() is private through private inheritance.

    return 0;
}
