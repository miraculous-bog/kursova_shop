#pragma once
#include <string>
#include <map>
#include "Goods.h";
#include <iostream>

class Human
{
public:
	enum SEX {
		MALE, FEMALE
	};
private:
	std::string name;
	int age;
	Human::SEX sex;
public:
	//Human() = delete;
	Human(std::string name, int age, Human::SEX sex);
	std::string getName();
	int getAge();
	Human::SEX getSex();
};

