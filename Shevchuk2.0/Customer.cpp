#include "Customer.h"
#include <iostream>

Customer::Customer(std::string name, int age, Human::SEX sex) :
	Human(name, age, sex)
{

}

void Customer::buy(Goods g, int amount)
{
	purchases.emplace(g, amount);
}

void Customer::printPurchases()
{
	for (auto el : purchases) {
		Goods g = el.first;
		std::cout << g.toStr() << "Amount: " << el.second << std::endl;
	}
}

bool operator==(Customer a, Customer b) {
	return a.getAge() == b.getAge() && a.getName() == b.getName() && a.getSex() == b.getSex();
}