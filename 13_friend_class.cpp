// Program 13: Friend Class
// Unit II - Friend class
// Compile: g++ -std=c++17 -Wall program13.cpp -o program13

#include <iostream>

class Account {
private:
     double balance;

     // Auditor is allowed to access the private members of Account.
     friend class Auditor;

public:
     explicit Account(double initialBalance) : balance(initialBalance) {}
};

// A friend class. Friendship is not inherited and not mutual.
class Auditor {
public:
     void inspect(const Account& account) const {
         // Direct access to a private member, allowed because of the friend declaration.
         std::cout << "Account Balance: " << account.balance << '\n';
     }
};

int main() {
     Account account(5000.0);
     Auditor auditor;

    auditor.inspect(account);
    return 0;
}
