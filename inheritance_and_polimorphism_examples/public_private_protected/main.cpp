#include <iostream>

class Animal {
public:
    void eat() {
        std::cout << "Animal is eating" << std::endl;
    }
protected:
    void sleep() {
        std::cout << "Animal is sleeping" << std::endl;
    }
private:
    void move() {
        std::cout << "Animal is moving" << std::endl;
    }
};

class Pet {
public:
    void play() {
        std::cout << "Pet is playing" << std::endl;
    }
};

class WildAnimal {
public:
    void roam() {
        std::cout << "Wild animal is roaming" << std::endl;
    }
};

class Cat : public Animal, protected Pet, private WildAnimal {
public:
    void catSpecificMethod() {
        std::cout << "This is a method specific to the Cat class" << std::endl;
    }
    
    void catAccessTest() {
        eat();   // OK - публичен метод на Animal
        sleep(); // OK - защитен метод на Animal
        //move();  // Грешка - частен метод на Animal
        
        play();  // OK - защитен метод на Pet
        
        roam();  // Грешка - частен метод на WildAnimal
    }
};

int main() {
    Cat cat;
    
    cat.eat();   // OK - публичен метод на Animal
    //cat.sleep(); // Грешка - защитен метод на Animal
    //cat.move();  // Грешка - частен метод на Animal
    
    //cat.play();  // Грешка - защитен метод на Pet
    
    //cat.roam();  // Грешка - частен метод на WildAnimal
    
    cat.catSpecificMethod(); // OK - метод на Cat
    
    cat.catAccessTest(); // Извикване на методите в рамките на Cat
    
    return 0;
}
