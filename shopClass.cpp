#include "shopClass.h"
#include "mh.h"

shopClass::shopClass()
{
	rub = 50000;
	pen = 0;
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
	cout << "Денег у магазина: " << rub << "." << pen << endl;
}

shopClass shopClass::operator+=(float n)
{
	rub += n;

	return shopClass();
}

