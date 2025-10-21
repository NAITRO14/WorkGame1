#pragma once
#include "person.h"
#include "BankClass.h"
#include <iostream>
class person;

class shopClass
{
	float money;
	short bread_count; float bread_cost;

	short lemonade_count; float lemonade_cost;

	short meat_count; float meat_cost;

	short coffe_count; float coffe_cost;

public:
	
	shopClass();

	int get_b();
	int get_m();
	void print_money();
	int get_money();
	void sleep();

	//друг
	friend void show_shop(shopClass& shop, person& pers);
	friend bool isGameLost(person& pers, shopClass& shop, BankClass& bank);
	/*friend ostream& operator << (ostream& os, shopClass& shop);*/

	friend BankClass;


	shopClass operator += (float n);
};

