// Program 07: Multiple-Inheritance Ambiguity
// Unit II - Scope-resolution operator to resolve ambiguity
// Compile: g++ -std=c++17 -Wall program07.cpp -o program07

#include <iostream>

class Academic {
public:
     void display() const {
         std::cout << "Academic information\n";
     }
};

class Sports {
public:

     void display() const {
         std::cout << "Sports information\n";
     }
};

// Both bases have display(), so calling display() directly would be ambiguous.
class Student : public Academic, public Sports {
public:
     void displayAll() const {
         // The scope-resolution operator (::) chooses which base version to call.
         Academic::display();
         Sports::display();
     }
};

int main() {
     Student student;

     // The same idea works from outside the class.
     student.Academic::display();
     student.Sports::display();
     student.displayAll();

     return 0;
}
