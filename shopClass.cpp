#include "shopClass.h"
#include "mh.h"

shopClass::shopClass()
{
	money = 20000;
	//небольшой разброс цен на каждый день
	bread_cost = rand() % 20 + 50.0f;
	meat_cost = rand() % 1000 + 2000.0f;
	lemonade_cost = rand() % 50 + 70.0f;
	coffe_cost = rand() % 150 + 450.0f;
	yogurt_cost = rand() % 101 + 200;

	//товара может и не быть вообще
	lemonade_count = rand() % 11;
	bread_count = rand() % 9;
	meat_count = rand() % 6;
	yogurt_count = rand() % 7;

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

float shopClass::get_money()
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
	yogurt_count = rand() % 7;

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

void shopClass::show_shop(shopClass& shop, person& pers)
{
	bool isIn = 1;

	while (isIn)
	{
		system("cls");
		cout << "=====Магазин====="; GotoXY(30, 0); cout << "Денег в кошельке: " << pers.getMoney() << endl;
		SetColor(DarkGray, 0);
		for (short y = 1; y < 21; y += 2)
		{
			for (short x = 1; x < 75; x++)
			{
				GotoXY(x, y); cout << "-";
			}
				
		}

		for (short i = 0; i < 4; i++)
		{
			short x = 0;
			if (i == 0) x = 1;
			else if (i == 1) x = 11;
			else if (i == 2) x = 60;
			else if (i == 3) x = 75;

			for (short y = 1; y < 20; y++)
			{
				GotoXY(x, y); cout << "|";
			}

		}
		SetColor(15, 0);
		GotoXY(2, 2); cout << "Товар"; GotoXY(50, 2); cout << "Количество"; GotoXY(61, 2); cout << "Стоимость";

		cout << endl;
		GotoXY(2, 4); cout << "1|Хлеб"; GotoXY(58, 4); cout << shop.bread_count; GotoXY(61, 4); cout << shop.bread_cost << endl;
		GotoXY(2, 6); cout << "2|Мясо"; GotoXY(58, 6); cout << shop.meat_count; GotoXY(61, 6); cout << shop.meat_cost << endl;
		GotoXY(2, 8); cout << "3|Лимонад"; GotoXY(58, 8); cout << shop.lemonade_count; GotoXY(61, 8); cout << shop.lemonade_cost << endl;
		GotoXY(2, 10); cout << "4|Кофе"; GotoXY(58, 10); cout << shop.coffe_count; GotoXY(61, 10); cout << shop.coffe_cost << endl;
		GotoXY(2, 12); cout << "5|Йогурт"; GotoXY(58, 12); cout << shop.yogurt_count; GotoXY(61, 12); cout << shop.yogurt_cost << endl;



		SetColor(8, 0); 
		GotoXY(1, 20); cout << "|--------------------|" << endl;
		GotoXY(1, 21); cout << "|1-5 -- купить товар |" << endl;
		GotoXY(1, 22); cout << "|0 -- уйти           |" << endl;
		GotoXY(1, 23); cout << "|--------------------|" << endl;
		SetColor(15, 0);

		isIn = to_buy(shop, pers);
	}
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

