#pragma once
#include "shopClass.h"
class shopClass;

class person
{
	float money;
	short bread_count;
	short meat_count;

public:

	person() : money(100.0), bread_count(0), meat_count(0){}

	int get_b();
	int get_m();
	void print_money();

	//друзья
	friend void to_work(person& p);

	friend void show_shop(shopClass& shop, person& pers);

	friend void taxes(shopClass& shop, person& pers);

	friend bool isGameLost(person& pers, shopClass& shop);
	

	person operator -= (float n);
};

