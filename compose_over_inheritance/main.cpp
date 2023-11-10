#include <iostream>
#include <string>
#include <vector>

// Клас, представящ клиент на банката
class Customer {
private:
    std::string name;
    std::string address;

public:
    Customer(const std::string& name, const std::string& address)
        : name(name), address(address) {}

    std::string getName() const {
        return name;
    }

    std::string getAddress() const {
        return address;
    }
};

// Клас, представящ банкова сметка
class BankAccount {
private:
    std::string accountNumber;
    double balance;
    Customer owner;

public:
    BankAccount(const std::string& accountNumber, double balance, const Customer& owner)
        : accountNumber(accountNumber), balance(balance), owner(owner) {}

    std::string getAccountNumber() const {
        return accountNumber;
    }

    double getBalance() const {
        return balance;
    }

    std::string getOwnerName() const {
        return owner.getName();
    }

    std::string getOwnerAddress() const {
        return owner.getAddress();
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            std::cout << "Insufficient funds!" << std::endl;
        }
    }
};

// Клас, представящ банкова система
class BankSystem {
private:
    std::vector<BankAccount> accounts;

public:
    void addAccount(const BankAccount& account) {
        accounts.push_back(account);
    }

    void printAccountDetails() const {
        for (const auto& account : accounts) {
            std::cout << "Account Number: " << account.getAccountNumber() << std::endl;
            std::cout << "Owner: " << account.getOwnerName() << std::endl;
            std::cout << "Balance: " << account.getBalance() << std::endl;
            std::cout << std::endl;
        }
    }
};

int main() {
    // Създаване на клиенти
    Customer customer1("John Smith", "123 Main Street");
    Customer customer2("Jane Doe", "456 Elm Street");

    // Създаване на банкови сметки
    BankAccount account1("123456", 1000.0, customer1);
    BankAccount account2("789012", 500.0, customer2);

    // Създаване на банкова система и добавяне на сметките
    BankSystem bankSystem;
    bankSystem.addAccount(account1);
    bankSystem.addAccount(account2);

    // Извеждане на информацията за сметките
    bankSystem.printAccountDetails();

    return 0;
}
