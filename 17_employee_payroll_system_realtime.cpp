// Program 17: Employee Payroll System (Real-Time Application)
// Unit II - Abstract class, pure virtual function, inheritance
// Compile: g++ -std=c++17 -Wall program17.cpp -o program17

#include <iostream>
#include <string>
using namespace std;

// Abstract base class: common employee data lives in protected members.
class Employee {
protected:
  int empId;
  string name;
  string department;

public:
  Employee(int id, string n, string dept)
     : empId(id), name(n), department(dept) {}

  void displayBasicInfo() const {
     cout << "ID: " << empId
          << " | Name: " << name

            << " | Department: " << department;
     }

     // Pure virtual function: every employee type must implement it.
     virtual double calculateSalary() const = 0;
     virtual ~Employee() = default;
};

// Full-time: a fixed monthly salary.
class FullTimeEmployee : public Employee {
private:
     double monthlySalary;

public:
     FullTimeEmployee(int id, string n, string dept, double salary)
         : Employee(id, n, dept), monthlySalary(salary) {}

     double calculateSalary() const override {
         return monthlySalary;
     }

     void display() const {
         displayBasicInfo();
         cout << " | Type: Full-Time | Salary: Rs. "
            << calculateSalary() << endl;
     }
};

// Part-time: salary depends on hourly rate and hours worked.
class PartTimeEmployee : public Employee {
private:
     double hourlyRate;
     int hoursWorked;

public:
     PartTimeEmployee(int id, string n, string dept, double rate, int hours)
         : Employee(id, n, dept), hourlyRate(rate), hoursWorked(hours) {}

     double calculateSalary() const override {
         // Salary = rate x hours.
         return hourlyRate * hoursWorked;
     }

     void display() const {
         displayBasicInfo();
         cout << " | Type: Part-Time | Salary: Rs. "
            << calculateSalary() << endl;
     }
};

// Intern: receives a fixed stipend.
class Intern : public Employee {
private:
     double stipend;

public:
     Intern(int id, string n, string dept, double stipendAmount)
         : Employee(id, n, dept), stipend(stipendAmount) {}

     double calculateSalary() const override {
         return stipend;
     }

     void display() const {
         displayBasicInfo();
         cout << " | Type: Intern | Stipend: Rs. "
            << calculateSalary() << endl;

     }
};

int main() {
     // Create one object of each concrete class.
     FullTimeEmployee f1(101, "Amit", "IT", 65000);
     PartTimeEmployee p1(102, "Sneha", "HR", 250, 120);
     Intern i1(103, "Rohan", "Marketing", 15000);

     cout << "=== Employee Payroll ===" << endl;
     f1.display();
     p1.display();
     i1.display();
}
