// Program 06: Multiple Inheritance
// Unit II - Multiple inheritance (two base classes)
// Compile: g++ -std=c++17 -Wall program06.cpp -o program06

#include <iostream>

class Academic {
protected:
     int academicMarks;

public:
     explicit Academic(int marks) : academicMarks(marks) {}

     void showAcademic() const {
         std::cout << "Academic Marks: " << academicMarks << '\n';
     }
};

class Sports {
protected:
     int sportsMarks;

public:
     explicit Sports(int marks) : sportsMarks(marks) {}

     void showSports() const {
         std::cout << "Sports Marks: " << sportsMarks << '\n';
     }
};

// Multiple inheritance: Student has two base classes.
class Student : public Academic, public Sports {
public:
     // Both base-class constructors are called in the initializer list.
     Student(int academic, int sports)
         : Academic(academic), Sports(sports) {}

     void showTotal() const {
         // Protected members of both base classes are accessible here.
         std::cout << "Total Marks: " << academicMarks + sportsMarks << '\n';
     }
};

int main() {
     Student student(80, 15);
     student.showAcademic();
     student.showSports();
     student.showTotal();
     return 0;
}
