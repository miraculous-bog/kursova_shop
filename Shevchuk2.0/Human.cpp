#include "Human.h"

Human::Human(std::string name, int age, Human::SEX sex)
{
	this->name = name;
	this->age = age;
	this->sex = sex;
}

std::string Human::getName()
{
	return this->name;
}

int Human::getAge()
{
	return this->age;
}

Human::SEX Human::getSex()
{
	return this->sex;
}
