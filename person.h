#pragma once
#include "shopClass.h"
#include "BankClass.h"
class shopClass;

class person
{
	float money;

	short bread_count;
	short meat_count;
	short lemonade_count;

public:

	person();

	//геттеры
	int get_b();
	int get_m();
	void print_money();

	//функции персоны
	void to_work(person& p, BankClass& bank);
	bool show_inv();
	bool to_eat();

	//друзья
	friend void show_shop(shopClass& shop, person& pers);
	friend bool isGameLost(person& pers, shopClass& shop);

	friend BankClass;
	

	person operator -= (float n);
};

