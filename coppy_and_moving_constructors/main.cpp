#include <iostream>

class Fruit {
public:
    Fruit() = default;
    virtual ~Fruit() = default;

    Fruit(const Fruit&) = delete;
    Fruit& operator=(const Fruit&) = delete;

    Fruit(Fruit&&) = delete;
    Fruit& operator=(Fruit&&) = delete;

    virtual void eat() {
        std::cout << "Eating fruit" << std::endl;
    }
};

class Apple : public Fruit {
public:
    Apple() = default;
    ~Apple() override {
        std::cout << "Destroying apple" << std::endl;
    }

    // Експлицитна реализация на копиращия конструктор за Apple
    Apple(const Apple& other) {
        // Извършете необходимата логика за копиране на членовете на Apple
        std::cout << "Copying apple" << std::endl;
    }

    // Експлицитна реализация на преместващия конструктор за Apple
    Apple(Apple&& other) noexcept {
        // Извършете необходимата логика за преместване на членовете на Apple
        std::cout << "Moving apple" << std::endl;
    }

    Apple& operator=(const Apple& other) {
        // Извършете необходимата логика за присвояване на членовете на Apple
        std::cout << "Assigning apple" << std::endl;
        return *this;
    }

    Apple& operator=(Apple&& other) noexcept {
        // Извършете необходимата логика за преместване на членовете на Apple
        std::cout << "Moving and assigning apple" << std::endl;
        return *this;
    }

    void eat() override {
        std::cout << "Eating apple" << std::endl;
    }
};

class Banana : public Fruit {
public:
    Banana() = default;
    ~Banana() override {
        std::cout << "Destroying banana" << std::endl;
    }

    // Експлицитна реализация на копиращия конструктор за Banana
    Banana(const Banana& other) {
        // Извършете необходимата логика за копиране на членовете на Banana
        std::cout << "Copying banana" << std::endl;
    }

    // Експлицитна реализация на преместващия конструктор за Banana
    Banana(Banana&& other) noexcept {
        // Извършете необходимата логика за преместване на членовете на Banana
        std::cout << "Moving banana" << std::endl;
    }

    Banana& operator=(const Banana& other) {
        // Извършете необходимата логика за присвояване на членовете на Banana
        std::cout << "Assigning banana" << std::endl;
        return *this;
    }

    Banana& operator=(Banana&& other) noexcept {
        // Извършете необходимата логика за преместване на членовете на Banana
        std::cout << "Moving and assigning banana" << std::endl;
        return *this;
    }

    void eat() override {
        std::cout << "Eating banana" << std::endl;
    }
};

int main() {
    Apple apple;
    Banana banana;

    Apple appleCopy(apple); // Копиране на apple
    Banana bananaCopy(banana); // Копиране на banana

    Apple appleMoved(std::move(apple)); // Преместване на apple
    Banana bananaMoved(std::move(banana)); // Преместване на banana

    return 0;
}
