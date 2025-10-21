#pragma once
#include "shopClass.h"
#include "BankClass.h"
class shopClass;

class person
{
	//деньги
	float money;

	//статы персонажа
	bool isHungry;
	short exLvl = 0;

	//продуктов в рюкзаке
	short bread_count;
	short meat_count;
	short lemonade_count;
	short coffe_count;

public:

	person();

	//геттеры
	bool get_hunger();
	void print_money();
	int get_ex();

	//функции персоны
	void to_work(person& p, BankClass& bank);
	void show_inv(short mang);
	void to_eat(short mang);
	void sleep();

	//друзья
	friend void show_shop(shopClass& shop, person& pers);
	friend bool isGameLost(person& pers, shopClass& shop, BankClass& bank);
	friend void work_act(person& pers, BankClass& bank);


	friend void sleep_act(shopClass& shop, person& pers);
	friend BankClass;
	

	person operator -= (float n);
};

