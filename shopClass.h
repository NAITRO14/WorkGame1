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

	short yogurt_count; short yogurt_cost;

public:
	
	shopClass();

	int get_b();
	int get_m();
	void print_money();
	float get_money();
	void sleep();
	void show_shop(shopClass& shop, person& pers);

	void ent_value(short *count);
	void nothingLeft();

	//друг
	friend bool to_buy(shopClass& shop, person& pers);
	friend bool isGameLost(person& pers, shopClass& shop, BankClass& bank);
	/*friend ostream& operator << (ostream& os, shopClass& shop);*/

	friend BankClass;


	shopClass operator += (float n);
};

