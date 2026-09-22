// Program 09: Parameterized Base Constructor
// Unit II - Initializer list and base-class constructor call
// Compile: g++ -std=c++17 -Wall program09.cpp -o program09

#include <iostream>
#include <string>
#include <utility>

class Person {
protected:
     std::string name;

public:
     // explicit prevents accidental implicit conversion from a string.
     explicit Person(std::string personName) : name(std::move(personName)) {}
};

class Student : public Person {
private:
     int rollNumber;

public:
     // The derived constructor must give the base constructor the data it needs.
     Student(std::string studentName, int roll)

         : Person(std::move(studentName)), rollNumber(roll) {}

     void display() const {
         // 'name' is a protected member inherited from Person.
         std::cout << "Name: " << name << '\n';
         std::cout << "Roll Number: " << rollNumber << '\n';
     }
};

int main() {
     Student student("Kiran", 24);
     student.display();
     return 0;
}
