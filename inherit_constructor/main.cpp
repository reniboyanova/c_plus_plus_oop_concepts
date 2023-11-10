#include <iostream>
#include <string>

class BankAccount {
public:
    BankAccount(const std::string& accountOwner, double initialBalance)
        : owner(accountOwner), balance(initialBalance) {}

    BankAccount(const std::string& accountOwner)
        : BankAccount(accountOwner, 0.0) {}

    void printAccountInfo() {
        std::cout << "Owner: " << owner << std::endl;
        std::cout << "Balance: " << balance << std::endl;
    }

private:
    std::string owner;
    double balance;
};

class SavingsAccount : public BankAccount {
public:
    using BankAccount::BankAccount; // Наследяване на конструкторите от BankAccount

    // Допълнително дефиниране на конструктора, който само приема accountOwner
    SavingsAccount(const std::string& accountOwner)
        : BankAccount(accountOwner, DEFAULT_SAVINGS_ACCOUNT_INITIAL_BALANCE) {}

private:
    static constexpr double DEFAULT_SAVINGS_ACCOUNT_INITIAL_BALANCE = 1000.0;
};

int main() {
    BankAccount bankAccount1("John Doe", 5000.0);
    bankAccount1.printAccountInfo();

    BankAccount bankAccount2("Jane Smith");
    bankAccount2.printAccountInfo();

    SavingsAccount savingsAccount1("Alice Johnson");
    savingsAccount1.printAccountInfo();

    SavingsAccount savingsAccount2("Bob Thompson");
    savingsAccount2.printAccountInfo();

    return 0;
}
