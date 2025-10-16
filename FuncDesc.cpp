#include "mh.h"

void enter_num(short& num)
{
	while (true) {
		if (cin >> num) {  // если ввод корректный
			break;         // выйти из цикла
		}
		else {
			cout << "Ошибка ввода. Введите число заново." << endl;
			cout << "Ввод: ";
			cin.clear(); // очистка ошибки
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // очистить буфер
		}
	}
}

void to_work(person& p)
{
	float mtmp = (rand() % 1001 + 500) + (rand() % 99 + 1)/10.0;

	p.money += mtmp;

	cout << "Заработано: " << mtmp << endl;
	
}

int work_act(short wpd, person& pers)
{
	if (wpd < 3)
	{
		to_work(pers);
		wpd++;
	}
	else
	{
		cout << "Вы очень устали и больше не можете работать. . ." << endl;
	}
	return wpd;
}

int sleep_act(int wpd, shopClass & shop, person& pers)
{
	cout << "Наступает новый день, вы полны сил!" << endl;
	wpd = 0;

	shop_sleep(shop);
	taxes(shop, pers);
	return wpd;
}

void shop_sleep(shopClass& shop)
{
	shop.bread_count = rand() % 5 + 1;
	shop.meat_count = rand() % 5 + 1;

	cout << "Интересно, что нового в магазине . . ." << endl;
}

void show_shop(shopClass& shop, person& pers)
{
	bool isIn = 1;
	short man; short count;
	while (isIn)
	{
		system("cls");
		shop.print_money();

		cout << "1|Хлеб: " << shop.bread_count << " | Стоимость: " << shop.bread_cost << endl;
		cout << "2|Мясо: " << shop.meat_count << " | Стоимость: " << shop.meat_cost << endl;
		
		cout << "--------------------" << endl;
		cout << "Хотите купить что-то?" << endl;
		cout << "1-2 -- купить товар" << endl;
		cout << "0 -- уйти" << endl;
		cout << "--------------------" << endl;

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
			if (shop.bread_count == 0) { cout << "Больше нет, приходи завтра, может, завезут" << endl; continue; }
			cout << "Сколько вам ?" << endl;
			cout << "Ввод: "; enter_num(count);

			if (count * shop.bread_cost > pers.money)
			{
				cout << "Кажется, у меня не хватит на это денег . . ." << endl;
				continue;
			}

			if (count <= shop.bread_count)
			{
				shop.bread_count -= count;
				pers -= shop.bread_cost;
				shop += shop.bread_cost;
			}
			else
			{
				cout << "Столько нет. Могу предложить только " << shop.bread_count << endl;
				system("pause");
			}

		}break;
		case 2:
		{
			if (shop.meat_count == 0) { cout << "Больше нет, приходи завтра, может, завезут" << endl; continue; }
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
				pers -= shop.meat_cost;
				shop += shop.meat_cost;
			}
			else
			{
				cout << "Столько нет. Могу предложить только " << shop.meat_count << endl;
				system("pause");
			}

		}break;
		}
	}
}

void taxes(shopClass& shop, person& pers)
{
	float persTax = (rand() % 10 + 1)/10.0;
	float shopTax = (rand() % 10 + 1)/10.0;

	pers.money -= 1000 * persTax;
	shop.money -= 5000 * shopTax;

	cout << "Ваш налог на сегодня составил " << 1000 * persTax << " руб." << endl;
}

bool isGameLost(person& pers, shopClass& shop)
{
	if (pers.money < 0)
	{
		system("cls");
		cout << "Вы разорились! У вас больше нет денег, чтобы завплатить за еду или налоги" << endl;
		return true;
	}

	if (shop.money < 0)
	{
		system("cls");
		cout << "Единственный магазин в вашем городе разорился! Он не мог больше содержаться и закрылся. Через время вы умерли от голода . . ." << endl;
		return true;
	}

	return false;
}


