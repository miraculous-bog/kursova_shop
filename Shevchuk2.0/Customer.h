#pragma once
#include "Human.h"

class Customer : public Human
{
	std::map<Goods, int> purchases;
public:
	Customer() = delete;
	Customer(std::string name, int age, Human::SEX sex);
	void buy(Goods g, int amount);
	void printPurchases();
	friend bool operator==(Customer a, Customer b);
};

