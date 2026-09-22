// Program 12: Virtual Base Class (Diamond Problem)
// Unit II - Virtual base class and diamond inheritance
// Compile: g++ -std=c++17 -Wall program12.cpp -o program12

#include <iostream>
#include <string>
#include <utility>

class Person {
protected:
     std::string name;

public:
     explicit Person(std::string personName) : name(std::move(personName)) {}

     void displayName() const {
         std::cout << "Name: " << name << '\n';
     }
};

// virtual inheritance: both branches share a single Person object.
class Student : virtual public Person {
public:
     Student() : Person("Unknown") {}
};

class Employee : virtual public Person {
public:
     Employee() : Person("Unknown") {}
};

// Diamond shape: Person -> Student/Employee -> TeachingAssistant.
class TeachingAssistant : public Student, public Employee {
public:
     // The most derived class initialises the shared virtual base Person directly.
     explicit TeachingAssistant(std::string assistantName)
         : Person(std::move(assistantName)), Student(), Employee() {}
};

int main() {
     TeachingAssistant assistant("Riya");
     // No ambiguity: only one Person part exists.
     assistant.displayName();
     return 0;
}
