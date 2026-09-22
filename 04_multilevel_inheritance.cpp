// Program 04: Multilevel Inheritance
// Unit II - Multilevel inheritance (Person -> Employee -> Manager)
// Compile: g++ -std=c++17 -Wall program04.cpp -o program04

#include <iostream>
#include <string>
#include <utility>

// Level 1: top-most base class.
class Person {
protected:
    std::string name;

public:
    explicit Person(std::string personName) : name(std::move(personName)) {}

    void showPerson() const {
        std::cout << "Name: " << name << '\n';
    }

};

// Level 2: Employee inherits from Person.
class Employee : public Person {
protected:
     int employeeId;

public:
     Employee(std::string employeeName, int id)
         : Person(std::move(employeeName)), employeeId(id) {}

     void showEmployee() const {
         std::cout << "Employee ID: " << employeeId << '\n';
     }
};

// Level 3: Manager inherits from Employee and, indirectly, from Person.
class Manager : public Employee {
private:
     int teamSize;

public:
     Manager(std::string managerName, int id, int size)
         : Employee(std::move(managerName), id), teamSize(size) {}

     void showManager() const {
         // Functions from all three levels are available inside Manager.
         showPerson();
         showEmployee();
         std::cout << "Team Size: " << teamSize << '\n';
     }
};

int main() {
     Manager manager("Ravi", 501, 8);
     manager.showManager();
     return 0;

}
