#include <iostream>
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
    Animal* animal = new Animal();
    Cat* cat = new Cat();

    animal->makeSound();  // Animal makes a sound.
    cat->makeSound();     // Cat says Meow!

    delete animal;
    delete cat;

    return 0;
}
