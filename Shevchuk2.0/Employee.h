#pragma once
#include "Human.h"
class Employee : public Human
{
    bool is_manager;
    double salary;
public:
    Employee();
    Employee(std::string name, int age, Human::SEX sex, double salary);
    void sell(double revenue);
    double getSalary();
    void promote();
    friend bool operator==(Employee a, Employee b);
};

