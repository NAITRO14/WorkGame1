#pragma once
#include "person.h"
#include "BankClass.h"
#include <iostream>
class person;

class shopClass
{
	float money;
	short bread_count; short bread_cost;

	short lemonade_count; short lemonade_cost;

	short meat_count; short meat_cost;

	short coffe_count; short coffe_cost;

public:
	
	shopClass();

	int get_b();
	int get_m();
	void print_money();
	int get_money();

	//друг
	friend void sleep_act(shopClass& shop, person& pers);
	friend void show_shop(shopClass& shop, person& pers);
	friend bool isGameLost(person& pers, shopClass& shop);
	/*friend ostream& operator << (ostream& os, shopClass& shop);*/

	friend BankClass;


	shopClass operator += (float n);
};

