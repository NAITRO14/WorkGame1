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

	cout << "Ваш налог на сегодня составил "; SetColor(12, 0);  cout << persTax << " руб." << endl; SetColor(15, 0);
}

float BankClass::salary()
{
	float sal = (rand() % 1801 + 700) + (rand() % 99 + 1) / 10.0f;
	money -= sal; // выплатить деньги за работу

	return sal;
}

float BankClass::get_money()
{
	return money;
}

int BankClass::get_clint()
{
	return clients;
}

int BankClass::get_comp()
{
	return companies;
}

//ostream& operator<<(ostream& os, BankClass& bank)
//{
//	cout << "s" << endl;
//	
//	return os;
//}
