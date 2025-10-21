#include "shopClass.h"
#include "mh.h"

shopClass::shopClass()
{
	money = 20000;
	//небольшой разброс цен на каждый день
	bread_cost = rand() % 50 + 70;
	meat_cost = rand() % 2000 + 2500;
	lemonade_cost = rand() % 100 + 120;
	coffe_cost = rand() % 150 + 450;

	//товара может и не быть вообще
	lemonade_count = rand() % 11;
	bread_count = rand() % 9;
	meat_count = rand() % 6;

	coffe_count = 0;

	short chance;
	for (short i = 0; i < 3; i++)
	{
		chance = rand() % 6;
		if (chance == 1)
		{
			coffe_count++;
		}
	}

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

void shopClass::sleep()
{
	//рандом кол-ва товаров
	bread_count = rand() % 5 + 1;
	meat_count = rand() % 5 + 1;
	lemonade_count = rand() % 11;

	//рандом кофе(реже остальных)
	short chance;
	for (short i = 0; i < 3; i++)
	{
		chance = rand() % 5 + 1; //шанс выпадения кофе - 0.2
		if (chance == 1)
		{
			coffe_count++;
		}
	}

	//разброс цен
	bread_cost = rand() % 20 + 50.0f;
	meat_cost = rand() % 1000 + 2000.0f;
	lemonade_cost = rand() % 50 + 70.0f;
	coffe_cost = rand() % 150 + 450.0f;

	SetColor(14, 0); cout << "Интересно, что нового в магазине . . ." << endl; SetColor(15, 0);

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

