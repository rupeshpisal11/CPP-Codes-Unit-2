// Program 01: Basic Single Inheritance
// Unit II - Single inheritance (Person -> Student)
// Compile: g++ -std=c++17 -Wall program01.cpp -o program01

#include <iostream>
#include <string>
#include <utility>

// Base class: holds data common to every person.
class Person {
// protected: visible inside Person and its derived classes.
protected:
     std::string name;

public:
     explicit Person(std::string personName) : name(std::move(personName)) {}

     void displayName() const {
         std::cout << "Name: " << name << '\n';
     }
};

// Public inheritance: a Student 'is a' Person.
class Student : public Person {
private:

     int rollNumber;

public:
     // The derived constructor passes the name to the base-class constructor.
     Student(std::string studentName, int roll)
         : Person(std::move(studentName)), rollNumber(roll) {}

     void displayStudent() const {
         // Inherited base-class function called from the derived class.
         displayName();
         std::cout << "Roll Number: " << rollNumber << '\n';
     }
};

int main() {
     Student student("Amit", 101);
     student.displayStudent();
     return 0;
}
