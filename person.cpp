#include "person.h"
#include "mh.h"

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
