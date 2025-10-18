#include "mh.h"

BankClass::BankClass()
{
	money = 40000.0;
}

void BankClass::taxes(shopClass& shop, person& pers)
{
	float persTax = ((rand() % 10 + 1) / 10.0f) * 1000.0f;
	float shopTax = ((rand() % 10 + 1) / 10.0f) * 5000.0f;

	pers.money -= persTax;
	shop.money -= shopTax;

	//вернуть деньги банку
	money += persTax + shopTax;

	cout << "Ваш налог на сегодня составил " << persTax << " руб." << endl;
}

float BankClass::salary()
{
	float sal = (rand() % 1501 + 500) + (rand() % 99 + 1) / 10.0f;
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
