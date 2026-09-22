// Program 18: Digital Payment Gateway (Real-Time Application)
// Unit II - Abstract interface, inheritance, run-time polymorphism
// Compile: g++ -std=c++17 -Wall program18.cpp -o program18

#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

// Abstract interface shared by every payment type.
class PaymentMethod {
protected:
     string transactionId;
     double amount;

public:
     PaymentMethod(string tid, double amt)
         : transactionId(tid), amount(amt) {}

     // Pure virtual: each payment method processes payment in its own way.
     virtual bool processPayment() const = 0;
     virtual ~PaymentMethod() = default;
};

// Card payment: keeps a masked card number.
class CreditCardPayment : public PaymentMethod {
private:
     string maskedCardNumber;

public:
     CreditCardPayment(string tid, double amt, string card)
         : PaymentMethod(tid, amt), maskedCardNumber(card) {}

     bool processPayment() const override {
         cout << "Credit-card transaction " << transactionId
            << " for Rs. " << amount
            << " using " << maskedCardNumber << " completed." << endl;
         return true;
     }
};

class UPIPayment : public PaymentMethod {

private:
     string upiId;

public:
     UPIPayment(string tid, double amt, string upi)
         : PaymentMethod(tid, amt), upiId(upi) {}

     bool processPayment() const override {
         cout << "UPI transaction " << transactionId
            << " for Rs. " << amount
            << " from " << upiId << " completed." << endl;
         return true;
     }
};

class NetBankingPayment : public PaymentMethod {
private:
     string bankName;

public:
     NetBankingPayment(string tid, double amt, string bank)
         : PaymentMethod(tid, amt), bankName(bank) {}

     bool processPayment() const override {
         cout << "Net-banking transaction " << transactionId
            << " for Rs. " << amount
            << " through " << bankName << " completed." << endl;
         return true;
     }
};

int main() {
    // Base-class smart pointers can hold any derived payment object.
    vector<unique_ptr<PaymentMethod>> payments;
    // make_unique creates the derived object; unique_ptr deletes it automatically.
    payments.push_back(make_unique<CreditCardPayment>("TXN001", 2500, "XXXX-XXXX-1234"));
    payments.push_back(make_unique<UPIPayment>("TXN002", 1200, "student@upi"));
    payments.push_back(make_unique<NetBankingPayment>("TXN003", 5000, "Example Bank"));

    cout << "=== Payment Gateway ===" << endl;
    for (const auto& payment : payments) {
        // Run-time polymorphism: the correct version runs for each object.
        payment->processPayment();
    }
}
