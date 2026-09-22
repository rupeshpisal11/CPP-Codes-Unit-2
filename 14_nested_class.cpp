// Program 14: Nested Class
// Unit II - Nested class
// Compile: g++ -std=c++17 -Wall program14.cpp -o program14

#include <iostream>
#include <string>
#include <utility>

// Outer class.
class University {
public:
    // Nested class: it lives inside the scope of University.
    class Department {
    private:
         std::string name;

    public:
         explicit Department(std::string departmentName)
             : name(std::move(departmentName)) {}

         void display() const {
             std::cout << "Department: " << name << '\n';
         }
    };

};

int main() {
     // A nested class is reached through the outer class name and ::.
     University::Department department("Artificial Intelligence and Data Science");
     department.display();
     return 0;
}
