#include <iostream>

class Animal {
public:
    virtual ~Animal() = default;
    virtual void eat() {
        std::cout << "Animal eats" << std::endl;
    }
};

class Bird : virtual public Animal {
public:
    void fly() {
        std::cout << "Bird flies" << std::endl;
    }
};

class Fish : virtual public Animal {
public:
    void swim() {
        std::cout << "Fish swims" << std::endl;
    }
};

class FlyingSwimmer : public Bird, public Fish {
public:
    void performActions() {
        Bird::eat();  // Извиква eat() от Bird
        Fish::eat();  // Извиква eat() от Fish
        fly();        // Извиква fly() от Bird
        swim();       // Извиква swim() от Fish
    }
};

int main() {
    FlyingSwimmer penguin;
    penguin.performActions();

    return 0;
}

