#include "shopClass.h"
#include "mh.h"

shopClass::shopClass()
{
	money = 20000;
	//небольшой разброс цен на каждый день
	bread_cost = rand() % 50 + 70;
	meat_cost = rand() % 2000 + 2500;
	lemonade_cost = rand() % 100 + 120;

	//товара может и не быть вообще
	lemonade_count = rand() % 11;
	bread_count = rand() % 9;
	meat_count = rand() % 6;

	BankClass::companies++;
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

int shopClass::get_money()
{
	return money;
}

shopClass shopClass::operator+=(float n)
{
	money += n;

	return shopClass();
}

//ostream& operator<<(ostream& os, shopClass& shop)
//{
//	cout << "Информация о магазине" << endl;
//	cout << "Возможные товары: хлеб, мясо, лимонад " << endl;
//	cout << "Владлец магазина: местное управление" << endl;
//	cout << "Бюджет магазина: " << shop.get_money() << endl;
//
//	return os;
//}

