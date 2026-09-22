// Program 02: Protected Member Access
// Unit II - protected access specifier
// Compile: g++ -std=c++17 -Wall program02.cpp -o program02

#include <iostream>
#include <string>

#include <utility>

class Employee {
// protected: derived classes can use 'name', outside code cannot.
protected:
     std::string name;

public:
     explicit Employee(std::string employeeName) : name(std::move(employeeName)) {}
};

// Developer inherits the protected member 'name' from Employee.
class Developer : public Employee {
private:
     std::string language;

public:
     Developer(std::string employeeName, std::string programmingLanguage)
         : Employee(std::move(employeeName)), language(std::move(programmingLanguage)) {}

     void display() const {
         // 'name' is accessible here only because it is protected.
         std::cout << "Developer: " << name << '\n';
         std::cout << "Language: " << language << '\n';
     }
};

int main() {
     Developer developer("Neha", "C++");
     developer.display();
     return 0;
}
