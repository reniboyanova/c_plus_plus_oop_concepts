#include <iostream>
#include <memory>
#include <vector>

// Главен клас Animal
class Animal {
protected:
    std::string name_;

public:
    Animal(const std::string& name) : name_(name) {}

    virtual void makeSound() const {
        std::cout << "Animal " << name_ << " makes a sound." << std::endl;
    }

    virtual void eat() const {
        std::cout << "Animal " << name_ << " is eating." << std::endl;
    }
};

// Клас Cat наследява Animal
class Cat : public Animal {
public:
    Cat(const std::string& name) : Animal(name) {}

    void makeSound() const override {
        std::cout << "Cat " << name_ << " says Meow!" << std::endl;
    }

    void eat() const override {
        std::cout << "Cat " << name_ << " is eating fish." << std::endl;
    }
};

// Клас Dog наследява Animal
class Dog : public Animal {
public:
    Dog(const std::string& name) : Animal(name) {}

    void makeSound() const override {
        std::cout << "Dog " << name_ << " says Woof!" << std::endl;
    }

    void eat() const override {
        std::cout << "Dog " << name_ << " is eating bones." << std::endl;
    }
};

int main() {
    std::vector<std::unique_ptr<Animal>> animals;

    animals.push_back(std::make_unique<Cat>("Whiskers"));
    animals.push_back(std::make_unique<Dog>("Buddy"));

    for (const auto& animal : animals) {
        animal->makeSound();
        animal->eat();
    }

    return 0;
}

