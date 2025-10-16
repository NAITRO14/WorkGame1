#include "shopClass.h"

shopClass::shopClass()
{
	rub = 5000;
	pen = 0;

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
