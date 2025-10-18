#include "mh.h"

BankClass::BankClass()
{
	money = 60000.0;
}

void BankClass::taxes(shopClass& shop, person& pers)
{
	float persTax = ((rand() % 10 + 1) / 10.0) * 1000;
	float shopTax = ((rand() % 10 + 1) / 10.0) * 5000;

	pers.money -= persTax;
	shop.money -= shopTax;

	//вернуть деньги банку
	money += persTax + shopTax;

	cout << "Ваш налог на сегодня составил " << persTax << " руб." << endl;
}

float BankClass::salary()
{
	float sal = (rand() % 1501 + 500) + (rand() % 99 + 1) / 10.0;
	money -= sal; // выплатить днбги за работу

	return sal;
}

float BankClass::get_money()
{
	return money;
}

//ostream& operator<<(ostream& os, BankClass& bank)
//{
//	cout << "s" << endl;
//	
//	return os;
//}
