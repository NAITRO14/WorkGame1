#pragma once
#include "shopClass.h"
class shopClass;

class person
{
	int rub; int pen;
	short bread_count;
	short meat_count;

public:

	person() : rub(100), pen(0), bread_count(0), meat_count(0){}

	int get_b();
	int get_m();
	void print_money();

	//друзья
	friend void to_work(person& p);

	friend void show_shop(shopClass& shop, person& pers);

	friend void taxes(shopClass& shop, person& pers);
	

	person operator -= (float n);
};

