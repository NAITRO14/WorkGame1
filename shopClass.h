#pragma once
#include <fstream>
#include "person.h"
class person;

class shopClass
{
	float money;
	short bread_count; short bread_cost;
	short meat_count; short meat_cost;

public:
	
	shopClass();

	int get_b();
	int get_m();
	void print_money();

	//друг
	friend void shop_sleep(shopClass& shop);
	friend void show_shop(shopClass & shop, person& pers);
	friend void taxes(shopClass& shop, person& pers);
	friend bool isGameLost(person& pers, shopClass& shop);

	shopClass operator += (float n);
};

