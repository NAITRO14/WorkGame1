#pragma once
#include "shopClass.h"
class shopClass; class person;

class BankClass
{
	float money;
public:
	BankClass();
	float get_money();

	void taxes(shopClass& shop, person& pers);
	float salary();

	/*friend ostream& operator << (ostream& os, BankClass& bank);*/
};

