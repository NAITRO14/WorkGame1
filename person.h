#pragma once
#include "shopClass.h"
#include "BankClass.h"
class shopClass;

class person
{
	//������
	float money;

	//����� ���������
	bool isHungry;
	short exLvl = 0;

	//��������� � �������
	short bread_count;
	short meat_count;
	short lemonade_count;
	short coffe_count;

public:

	person();

	//�������
	bool get_hunger();
	void print_money();
	float getMoney();
	int get_ex();

	//������� �������
	void to_work(BankClass& bank);
	void show_inv(short mang);
	void to_eat(short mang);
	void sleep();

	//������
	friend bool isGameLost(person& pers, shopClass& shop, BankClass& bank);
	friend bool to_buy(shopClass& shop, person& pers);
	friend BankClass; friend shopClass;
	

	person operator -= (float n);
};

