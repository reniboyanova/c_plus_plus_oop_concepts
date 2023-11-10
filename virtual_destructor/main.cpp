#include <iostream>

class Fruit {
public:
    Fruit() = default;
    virtual ~Fruit(){
        std::cout << "You finish with fruits" <<std::endl;
    };

    Fruit(const Fruit&) = default;
    Fruit& operator=(const Fruit&) = default;

    Fruit(Fruit&&) = default;
    Fruit& operator=(Fruit&&) = default;

    virtual void eat() {
        std::cout << "Eating fruit" << std::endl;
    }
};

class Apple : public Fruit {
public:
    Apple() = default;
    ~Apple() override{
        std::cout << "You already ate this aplle" << std::endl;
    };
    void eat() override {
        std::cout << "Eating apple" << std::endl;
    }
};

class Banana : public Fruit {
public:
    Banana() = default;
    ~Banana() override {
        std::cout << "You already ate this banana" << std::endl;
    };

    void eat() override {
        std::cout << "Eating banana" << std::endl;
    }
};

int main() {
    Fruit* apple = new Apple();
    Fruit* banana = new Banana();

    apple->eat();
    banana->eat();

    delete apple;
    delete banana;

    return 0;
}
