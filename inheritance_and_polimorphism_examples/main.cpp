#include <iostream>

class Base {
public:
    void print() {
        std::cout << "Base::print()" << std::endl;
    }
    virtual void virtualPrint() {
        std::cout << "Base::virtualPrint()" << std::endl;
    }
};

class Derived : public Base {
public:
    void print() {
        std::cout << "Derived::print()" << std::endl;
    }
    void virtualPrint() override {
        std::cout << "Derived::virtualPrint()" << std::endl;
    }
};

int main() {
    Base* basePtr = new Derived();

    basePtr->print();        // Извиква Base::print()
    basePtr->virtualPrint(); // Извиква Derived::virtualPrint()

    delete basePtr;

    return 0;
}
