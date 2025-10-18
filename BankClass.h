#pragma once
#include "shopClass.h"
class shopClass; class person;

class BankClass
{
	float money;

	static int clients; // количество клиентов
	static int companies; // количество компаний

public:
	BankClass();
	//геттеры
	float get_money();
	int get_clint();
	int get_comp();

	//функции банка
	void taxes(shopClass& shop, person& pers);
	float salary();

	//друзья
	friend class person; friend class shopClass;

	/*friend ostream& operator << (ostream& os, BankClass& bank);*/
};

