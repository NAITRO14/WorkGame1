#pragma once
#include "shopClass.h"
#include "BankClass.h"
class shopClass;

class person
{
	float money;

	bool isHungry;

	short bread_count;
	short meat_count;
	short lemonade_count;

public:

	person();

	//�������
	bool get_hunger();
	void print_money();

	//������� �������
	void to_work(person& p, BankClass& bank);
	void show_inv(short mang);
	void to_eat(short mang);

	//������
	friend void show_shop(shopClass& shop, person& pers);
	friend bool isGameLost(person& pers, shopClass& shop);

	friend BankClass;
	

	person operator -= (float n);
};

