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
	short man; short count;
	while (isIn)
	{
		system("cls");
		shop.print_money();

		cout << "1|Хлеб: " << shop.bread_count << " | Стоимость: " << shop.bread_cost << endl;
		cout << "2|Мясо: " << shop.meat_count << " | Стоимость: " << shop.meat_cost << endl;
		cout << "3|Лимонад: " << shop.lemonade_count << " | Стоимость: " << shop.lemonade_cost << endl;
		cout << "4|Кофе: " << shop.coffe_count << " | Стоимость: " << shop.coffe_cost << endl;


		SetColor(8, 0);
		cout << "--------------------" << endl;
		cout << "Хотите купить что-то?" << endl;
		cout << "1-4 -- купить товар" << endl;
		cout << "0 -- уйти" << endl;
		cout << "--------------------" << endl;
		SetColor(15, 0);

		cout << "Ввод: ";
		enter_num(man);
		switch (man)
		{
		case 0:
		{
			isIn = 0;
		}break;
		case 1:
		{
			if (shop.bread_count == 0) { cout << "Больше нет, приходи завтра, может, завезут" << endl; system("pause"); continue; }
			cout << "Сколько вам ?" << endl;
			cout << "Ввод: "; enter_num(count);

			if (count * shop.bread_cost > pers.money)
			{
				cout << "Кажется, у меня не хватит на это денег . . ." << endl;
				system("pause");
				continue;
			}

			if (count <= shop.bread_count)
			{
				shop.bread_count -= count;
				pers.bread_count += count;

				pers -= shop.bread_cost * count;
				shop += shop.bread_cost * count;
			}
			else
			{
				cout << "Столько нет. Могу предложить только " << shop.bread_count << endl;
				system("pause");
			}

		}break;
		case 2:
		{
			if (shop.meat_count == 0) { cout << "Больше нет, приходи завтра, может, завезут" << endl; system("pause"); continue; }
			cout << "Сколько вам ?" << endl;
			cout << "Ввод: "; enter_num(count);

			if (count * shop.meat_cost > pers.money)
			{
				cout << "Кажется, у меня не хватит на это денег . . ." << endl;
				system("pause");
				continue;
			}

			if (count <= shop.meat_count)
			{
				shop.meat_count -= count;
				pers.meat_count += count;

				pers -= shop.meat_cost * count;
				shop += shop.meat_cost * count;
			}
			else
			{
				cout << "Столько нет. Могу предложить только " << shop.meat_count << endl;
				system("pause");
			}

		}break;
		case 3:
		{
			if (shop.lemonade_count == 0) { cout << "Больше нет, приходи завтра, может, завезут" << endl; system("pause"); continue; }
			cout << "Сколько вам ?" << endl;
			cout << "Ввод: "; enter_num(count);

			if (count * shop.lemonade_cost > pers.money)
			{
				cout << "Кажется, у меня не хватит на это денег . . ." << endl;
				system("pause");
				continue;
			}

			if (count <= shop.lemonade_count)
			{
				shop.lemonade_count -= count;
				pers.lemonade_count += count;

				pers -= shop.lemonade_cost * count;
				shop += shop.lemonade_cost * count;
			}
			else
			{
				cout << "Столько нет. Могу предложить только " << shop.bread_count << endl;
				system("pause");
			}

		}break;
		case 4:
		{
			if (shop.coffe_count == 0) { cout << "Больше нет, приходи завтра, может, завезут" << endl; system("pause"); continue; }
			cout << "Сколько вам ?" << endl;
			cout << "Ввод: "; enter_num(count);

			if (count * shop.coffe_cost > pers.money)
			{
				cout << "Кажется, у меня не хватит на это денег . . ." << endl;
				system("pause");
				continue;
			}

			if (count <= shop.coffe_count)
			{
				shop.coffe_count -= count;
				pers.coffe_count += count;

				pers -= shop.coffe_cost * count;
				shop += shop.coffe_cost * count;
			}
			else
			{
				cout << "Столько нет. Могу предложить только " << shop.bread_count << endl;
				system("pause");
			}

		}break;
		}
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

