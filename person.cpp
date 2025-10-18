#include "person.h"
#include "mh.h"

person::person()
{
	money = 1000;
	bread_count = 0;
	meat_count = 0;
	lemonade_count = 0;

	BankClass::clients++;
}

void person::print_money()
{
	cout << money;
}

void person::to_work(person& p, BankClass& bank)
{
	float mtmp = bank.salary();

	money += mtmp;

	cout << "Заработано: " << mtmp << endl;
}

person person::operator-=(float n)
{
	money -= n;
	return person();
}
