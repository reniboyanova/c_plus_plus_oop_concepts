#include <iostream>
#include <memory>
#include <string>

// Главен клас Animal
class Animal {
public:
    virtual void makeSound() const {
        std::cout << "Animal makes a sound." << std::endl;
    }
};

// Клас Cat наследява Animal
class Cat : public Animal {
public:
    void makeSound() const override {
        std::cout << "Cat says Meow!" << std::endl;
    }
};

int main() {
    std::unique_ptr<Animal> animal = std::make_unique<Animal>();
    std::unique_ptr<Cat> cat = std::make_unique<Cat>();

    animal->makeSound();  // Animal makes a sound.
    cat->makeSound();     // Cat says Meow!

    return 0;
}
