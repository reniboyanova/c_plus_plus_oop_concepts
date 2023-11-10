
#include <iostream>
#include <string>

class Cat {
public:
    // Конструктор по подразбиране (Default Constructor)
    Cat() {
        std::cout << "Default Constructor: A cat is created." << std::endl;
    }

    // Конструктор с параметри (Parameterized Constructor)
    Cat(const std::string& name, int age) : name_(name), age_(age) {
        std::cout << "Parameterized Constructor: A cat named " << name_ << " is created." << std::endl;
    }

    // Конструктор за копиране (Copy Constructor)
    Cat(const Cat& other) : name_(other.name_), age_(other.age_) {
        std::cout << "Copy Constructor: A cat named " << name_ << " is copied." << std::endl;
    }

    // Конструктор за преместване (Move Constructor)
    Cat(Cat&& other) noexcept : name_(std::move(other.name_)), age_(other.age_) {
        std::cout << "Move Constructor: A cat named " << name_ << " is moved." << std::endl;
    }

    // Деструктор (Destructor)
    ~Cat() {
        std::cout << "Destructor: The cat named " << name_ << " is destroyed." << std::endl;
    }

    // Оператор за присвояване (Assignment Operator)
    Cat& operator=(const Cat& other) {
        name_ = other.name_;
        age_ = other.age_;
        std::cout << "Assignment Operator: A cat named " << name_ << " is assigned." << std::endl;
        return *this;
    }

    // Оператор за присвояване с преместване (Move Assignment Operator)
    Cat& operator=(Cat&& other) noexcept {
        name_ = std::move(other.name_);
        age_ = other.age_;
        std::cout << "Move Assignment Operator: A cat named " << name_ << " is moved." << std::endl;
        return *this;
    }

private:
    std::string name_;
    int age_;
};

int main() {
    // Използване на различните конструктори и оператори
    Cat cat1;                               // Default Constructor: A cat is created.
    Cat cat2("Whiskers", 5);                // Parameterized Constructor: A cat named Whiskers is created.
    Cat cat3(cat2);                         // Copy Constructor: A cat named Whiskers is copied.
    Cat cat4(std::move(cat3));              // Move Constructor: A cat named Whiskers is moved.
    cat1 = cat4;                            // Assignment Operator: A cat named Whiskers is assigned.
    cat2 = std::move(cat1);                 // Move Assignment Operator: A cat named Whiskers is moved.

    return 0;
}
