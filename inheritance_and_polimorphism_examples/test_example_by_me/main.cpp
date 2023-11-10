#include <iostream>
#include <vector>
#include <string>
#include <memory>

class Person
{
protected:
    std::string name_;
    int egn_ = 0;
    int age_ = 0;

public:
    Person(std::string name, int age) : name_(name), age_(age){};

    std::string getName() {return name_;}
    virtual int getEGN(){
        int egn;
        std::cout << "You can place your EGN here: _ _ _ _ _ _ _ _ _ _" << std::endl;
        std::cout << "You can place your EGN here:";
        std::cin >> egn;
        std::cin.ignore();

        this->egn_ = egn;
        return egn_;

    }
};


class Employee : public Person {
public:
    Employee(std::string name, int age) : Person(name, age) {}
    int getEGN() override {
        if (this->age_ > 18){
            int egn;
            std::cout << "Employee with name " << this->name_ << ", please insert your EGN here: _ _ _ _ _ _ _ _ _ _" << std::endl;
            std::cout << "You can place your EGN here:";
            std::cin >> egn;
            std::cin.ignore();
            this->egn_ = egn;

        }else{
            std::cout << this->name_ << "  you are too young to be employee..." << std::endl;
        }
        return egn_;
    }
};


int main(){
    std::vector<std::unique_ptr<Person>> employees;

    employees.push_back(std::make_unique<Employee>("Reni", 31));
    employees.push_back(std::make_unique<Employee>("Adi", 2));
    employees.push_back(std::make_unique<Employee>("Boyan", 33));

    for (auto & employee : employees)
    {   
        employee->getEGN();
        std::cout << std::endl;
    }
    
    

    return 0;
}