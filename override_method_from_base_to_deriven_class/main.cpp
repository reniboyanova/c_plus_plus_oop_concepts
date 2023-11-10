#include <iostream>

struct Animal {
    virtual void makeSound() {
        std::cout << "The animal makes a sound" << std::endl;
    }

    virtual void makeSound(int volume) {
        std::cout << "The animal makes a loud sound with volume " << volume << std::endl;
    }
};

struct Dog : public Animal {
    using Animal::makeSound; // Използваме using декларацията за името на overloaded методите от базовия клас

    void makeSound() override { // Override само на първата версия на makeSound()
        std::cout << "The dog barks" << std::endl;
    }
};

int main() {
    Dog d;
    d.makeSound(); // Извикване на override-ната версия на makeSound()
    d.makeSound(4); // Извикване на втората версия на makeSound() от базовия клас

    return 0;
}
