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
	void to_work(BankClass& bank);
	void show_inv(short mang);
	void to_eat(short mang);
	void sleep();

	//друзья
	friend bool isGameLost(person& pers, shopClass& shop, BankClass& bank);

	friend BankClass; friend shopClass;
	

	person operator -= (float n);
};

