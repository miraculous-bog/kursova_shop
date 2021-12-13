#include "Shop.h"
#include <algorithm>
using namespace std;
Shop::Shop(Employee owner, int space)
{
	this->staff.push_back(owner);
	this->onDuty = owner;
	this->space = space;
	this->profit = 0;
}

void Shop::refill(Distributor d, Goods g, int amount)
{
	if (d.sell(g, amount)) {
		Goods newg(g.getType(), g.getVolume(), g.getPrice() * 2);
		if (this->space >= g.getVolume() * amount) {
			this->stock.emplace(newg, amount);
			this->profit -= g.getPrice() * amount;
			this->space -= g.getVolume() * amount;
		}
		else {
			cout << "No space left in stock!" << endl;
		}
	}
	else {
		cout << "Refilling declined!" << endl;
	}
}

void Shop::sell(Customer c, Goods g, int amount)
{
	bool is_regular = false, is_sale = false;

	if (this->stock.find(g) != this->stock.end()) {
		if (this->stock[g] >= amount) {
			auto iter_r = find(regularCustomers.begin(), regularCustomers.end(), c);
			if (iter_r != regularCustomers.end()) {
				is_regular = true;
			}

			auto iter_s = sales.find(g);
			if (iter_s != sales.end()) {
				is_sale = true;
			}
			
			c.buy(g, amount);
			double revenue = g.getPrice() * amount;
			if (is_sale) {
				revenue *= sales[g];
			}
			if (is_regular) {
				revenue *= 0.85;
			}
			this->profit += revenue;
			this->onDuty.sell(revenue);
			this->stock[g] -= amount;
			this->space -= g.getVolume() * amount;
		}
		else {
			cout << "Too big order, not enough in stock!" << endl;
		}
	}
	else {
		cout << "There is no such goods on out store!" << endl;
	}
}

void Shop::setOnSale(Goods g, double sale)
{
	this->sales.emplace(g, sale);
}

void Shop::addFreeSpace(int space)
{
	this->space += space;
}

int Shop::getFreeSpace()
{
	return this->space;
}

void Shop::hire(Human h)
{
	this->staff.push_back(Employee(h.getName(), h.getAge(), h.getSex(), 6500));
}

void Shop::promote(Employee e)
{
	e.promote();
}

void Shop::fire(Employee e)
{
	auto iter = find(staff.begin(), staff.end(), e);
	if (iter != staff.end()) {
		staff.erase(iter);
	}
	else {
		cout << "No such employee in our shop!" << endl;
	}
}

void Shop::setOnDuty(Employee e)
{
	auto iter = find(staff.begin(), staff.end(), e);
	if (iter != staff.end()) {
		this->onDuty = e;
	}
	else {
		cout << "No such employee in our shop!" << endl;
	}
}

void Shop::addToRegular(Customer c)
{
	this->regularCustomers.push_back(c);
}

double Shop::getProfit()
{
	return this->profit;
}


