#include <iostream>
#include <memory>
#include <vector>

/*

Дефинирайте абстрактен базов клас AbstractEmployee с pure virtual метод
calculateSalary().
Дефинирайте два класа, които го наследяват, всеки от които има различна стратегия
за изчисляване на заплатата:
● HourlyEmployee, който има hourlyRate - почасова заплата. Заплатата е
произведението от почасовата заплата и броя часове, посветени на работа (за
които дефинираме member в HourlyEmployee)
● SalariedEmplyee, който има фиксирана месечна заплата.
Тествайте в main с указатели и с референции.
*/


class AbstractEmployee
{
protected:
    std::string m_employeeName;
    int m_monthSalary = 0;

public:
    AbstractEmployee(std::string name) : m_employeeName(name) {}
    virtual void calculateSalary() = 0;
};

class HourlyEmployee : public AbstractEmployee
{
public:
    HourlyEmployee(std::string name) : AbstractEmployee(name) {}
    void calculateSalary() override
    {
        int payForHour = 70;
        m_monthSalary = (22 * 8) * payForHour;
        std::cout << m_employeeName << " has an hourly payment of " << payForHour << " per hour. And monthly salary - " << m_monthSalary << std::endl;
    }
};

class SalariedEmployee : public AbstractEmployee
{
public:
    SalariedEmployee(std::string name) : AbstractEmployee(name) {}
    void calculateSalary() override
    {
        m_monthSalary = 2800;
        std::cout << m_employeeName << " has a fixed monthly payment of " << m_monthSalary << std::endl;
    }
};

int main()
{
    std::vector<std::unique_ptr<AbstractEmployee>> employees;

    employees.push_back(std::make_unique<HourlyEmployee>("Reni"));
    employees.push_back(std::make_unique<HourlyEmployee>("Ani"));
    employees.push_back(std::make_unique<HourlyEmployee>("Nina"));
    employees.push_back(std::make_unique<SalariedEmployee>("Reni"));
    employees.push_back(std::make_unique<SalariedEmployee>("Nina"));
    employees.push_back(std::make_unique<SalariedEmployee>("Ani"));

    for (const auto& employee : employees)
    {
        employee->calculateSalary();
    }

    HourlyEmployee employeeIzabela("Izabela");
    SalariedEmployee employeeRicardo("Ricardo");
    AbstractEmployee& iza(employeeIzabela);
    AbstractEmployee * ric(&employeeRicardo);
    iza.calculateSalary();
    ric->calculateSalary();

    return 0;
}
