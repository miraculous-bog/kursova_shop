#pragma once
#include "Human.h"
#include "Employee.h"
#include "Customer.h"
#include "Goods.h"
#include "Distributor.h"
#include <map>
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

class Shop
{
	map<Goods, int> stock;
	map<Goods, double> sales;
	int space;

	vector<Customer> regularCustomers;
	vector<Employee> staff;
	Employee onDuty;

	double profit;

public:
	Shop(Employee owner, int space);
	void refill(Distributor d, Goods g, int amount);
	void sell(Customer c, Goods g, int amount);
	void setOnSale(Goods g, double sale);
	void addFreeSpace(int space);
	int getFreeSpace();

	void hire(Human h);
	void promote(Employee e);
	void fire(Employee e);
	void setOnDuty(Employee e);
	void addToRegular(Customer c);

	double getProfit();

	void getStats();
};

