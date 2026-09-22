# Chapter 2: Inheritance

## Student Details

| Field | Details |
|---|---|
| Student Name | Rupesh Rajaram Pisal |
| PRN | 126UAD2028 |
| Class / Division | S.Y. B.Tech. (Artificial Intelligence and Data Science) / Div. F |
| Course Name | Object-Oriented Programming with C++ (ADPC303) |
| GitHub Username | [rupeshpisal11](https://github.com/rupeshpisal11) |

## Programs (19)

| Program | Title | OOP Concept | Description |
|---|---|---|---|
| [01_basic_single_inheritance.cpp](01_basic_single_inheritance.cpp) | Basic Single Inheritance | Single inheritance (Person -> Student) | Student inherits from Person, so it reuses the name and displayName() of the base class and adds a roll number. It shows the 'is-a' relationship of single inheritance. |
| [02_protected_member_access.cpp](02_protected_member_access.cpp) | Protected Member Access | protected access specifier | A Developer class directly uses the protected name member inherited from Employee. It shows that protected members are open to derived classes but hidden from outside code. |
| [03_public_vs_private_inheritance.cpp](03_public_vs_private_inheritance.cpp) | Public versus Private Inheritance | Inheritance modes (public and private) | Compares two derived classes of the same base: one with public inheritance and one with private inheritance. It shows how the inheritance mode changes whether base members are reachable from outside. |
| [04_multilevel_inheritance.cpp](04_multilevel_inheritance.cpp) | Multilevel Inheritance | Multilevel inheritance (Person -> Employee -> Manager) | Builds a three-level chain where Manager inherits from Employee, which inherits from Person. It shows how features pass down through several levels of inheritance. |
| [05_hierarchical_inheritance.cpp](05_hierarchical_inheritance.cpp) | Hierarchical Inheritance | Hierarchical inheritance (one base, many derived) | Car and Bike both inherit from the common Vehicle class and each adds its own feature. It shows how one base class can be shared by several derived classes. |
| [06_multiple_inheritance.cpp](06_multiple_inheritance.cpp) | Multiple Inheritance | Multiple inheritance (two base classes) | Student inherits from both Academic and Sports and adds the two mark totals together. It shows that a derived class can combine features of more than one base class. |
| [07_multiple_inheritance_ambiguity.cpp](07_multiple_inheritance_ambiguity.cpp) | Multiple-Inheritance Ambiguity | Scope-resolution operator to resolve ambiguity | Two base classes both have a display() function, so the derived class must say which one it wants. It shows how the scope-resolution operator (::) removes the ambiguity. |
| [08_constructor_destructor_order.cpp](08_constructor_destructor_order.cpp) | Constructor and Destructor Order | Object lifecycle in inheritance | Creates a derived object and prints a message from every constructor and destructor. It shows that constructors run base-first and destructors run derived-first. |
| [09_parameterized_base_constructor.cpp](09_parameterized_base_constructor.cpp) | Parameterized Base Constructor | Initializer list and base-class constructor call | Student passes the name to the Person constructor through the initializer list. It shows how a derived class supplies arguments to a base class that has no default constructor. |
| [10_function_overriding.cpp](10_function_overriding.cpp) | Function Overriding | Function overriding with virtual and override | Car and Boat each override the virtual move() function of Vehicle with their own version. It shows overriding, and how virtual and override keep the intent clear. |
| [11_abstract_class.cpp](11_abstract_class.cpp) | Abstract Class | Abstract class and pure virtual function | Shape declares a pure virtual area() function, and Rectangle and Circle each implement it. It shows that an abstract class cannot be instantiated and forces derived classes to provide the function. |
| [12_virtual_base_class_diamond_problem.cpp](12_virtual_base_class_diamond_problem.cpp) | Virtual Base Class (Diamond Problem) | Virtual base class and diamond inheritance | TeachingAssistant inherits from Student and Employee, which both inherit from Person. Virtual inheritance makes sure only one Person part exists, which removes the duplicate-base ambiguity. |
| [13_friend_class.cpp](13_friend_class.cpp) | Friend Class | Friend class | The Auditor class is declared a friend of Account so it can read the private balance. It shows how a friend class gets special access to private data. |
| [14_nested_class.cpp](14_nested_class.cpp) | Nested Class | Nested class | Defines a Department class inside a University class and creates a Department object. It shows how a class can be declared inside another class. |
| [15_vehicle_rental_system.cpp](15_vehicle_rental_system.cpp) | Mini-Project: Vehicle Rental System | Inheritance, virtual functions and overriding (mini-project) | A rental system where Car and Bike inherit from Vehicle; Bike overrides the rent calculation to give a 10% discount. It shows reuse through inheritance and how derived classes customise base behaviour. |
| [16_employee_payroll_system.cpp](16_employee_payroll_system.cpp) | Mini-Project: Employee Payroll System | Abstract base class and overriding (mini-project) | Permanent and contract employees inherit from an abstract Employee class and each calculates salary in its own way. A base-class reference prints the pay slip for either type. |
| [17_employee_payroll_system_realtime.cpp](17_employee_payroll_system_realtime.cpp) | Employee Payroll System (Real-Time Application) | Abstract class, pure virtual function, inheritance | An abstract Employee class is extended by full-time, part-time and intern employees, each with its own salary rule. It shows how inheritance and pure virtual functions model different kinds of staff. |
| [18_digital_payment_gateway.cpp](18_digital_payment_gateway.cpp) | Digital Payment Gateway (Real-Time Application) | Abstract interface, inheritance, run-time polymorphism | A payment gateway processes credit-card, UPI and net-banking payments through one common PaymentMethod interface stored in a vector of smart pointers. The right processPayment() runs for each payment type at run time. |
| [19_vehicle_fleet_management.cpp](19_vehicle_fleet_management.cpp) | Vehicle Fleet Management (Real-Time Application) | Inheritance, overriding, base-class pointers | A fleet of trucks, delivery vans and bikes shares one Vehicle base class, and each type overrides displayInfo() to show its own details. The fleet is stored as base-class smart pointers in one vector. |

## How to Compile and Run

Linux / macOS:
```bash
g++ -std=c++17 filename.cpp -o program
./program
```

Windows (MinGW):
```bash
g++ -std=c++17 filename.cpp -o program.exe
program.exe
```

## Notes

- All programs are self-contained, compilable `.cpp` files verified with `g++ -std=c++17 -Wall`.
- Numbered programs are followed by real-time application programs (sourced from the *Unit-Wise Real-Time Applications and Live Examples* document).
- No compiled binaries, output files, or screenshots are included — only source code.
