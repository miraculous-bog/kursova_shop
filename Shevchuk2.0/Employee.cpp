#include "Employee.h"

Employee::Employee() :
	Human("Noname", 0, Human::MALE)
{
	this->is_manager = false;
	this->salary = 0;
}

Employee::Employee(std::string name, int age, Human::SEX sex, double salary) : Human(name, age, sex)
{
	this->salary = salary;
	this->is_manager = false;
}

void Employee::sell(double revenue)
{
	this->salary += revenue * 0.01;
}

double Employee::getSalary()
{
	return this->salary;
}

void Employee::promote()
{
	if (!is_manager) {
		this->is_manager = true;
		this->salary *= 2;
	}
	else {
		std::cout << "Employee " << this->getName() << " is already a manager" << std::endl;
	}
}

bool operator==(Employee a, Employee b) {
	return a.getAge() == b.getAge() && a.getName() == b.getName() && a.getSalary() == b.getSalary() && a.getSex() == b.getSex();
}
