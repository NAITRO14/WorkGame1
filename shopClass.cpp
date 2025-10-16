#include "shopClass.h"
#include "mh.h"

shopClass::shopClass()
{
	money = 30000;
	bread_cost = rand() % 20 + 50;
	meat_cost = rand() % 1000 + 2000;

	bread_count = rand() % 5 + 1;
	meat_count = rand() % 5 + 1;

}

int shopClass::get_b()
{
	return bread_count;
}

int shopClass::get_m()
{
	return meat_count;
}

void shopClass::print_money()
{
	cout << "Денег у магазина: " << money << endl;
}

shopClass shopClass::operator+=(float n)
{
	money += n;

	return shopClass();
}

