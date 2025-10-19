#include "mh.h"

void enter_num(short& num)
{
	while (true) {
		if (cin >> num) {  // если ввод корректный
			break;         // выйти из цикла
		}
		else {
			SetColor(4, 0); cout << "Ошибка ввода. Введите число заново." << endl; SetColor(15, 0);
			cout << "Ввод: ";
			cin.clear(); // очистка ошибки
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // очистить буфер
		}
	}
}

void work_act(person& pers, BankClass& bank)
{
	if (pers.exLvl < 3)
	{
		pers.to_work(pers, bank);
		pers.exLvl++;
	}
	else
	{
		SetColor(4, 0); cout << "Вы очень устали и больше не можете работать. . ." << endl; SetColor(15, 0);
	}
}

void sleep_act(shopClass & shop, person& pers)
{
	if (pers.get_hunger())
	{
		pers.show_inv(2);
	}

	system("cls");
	SetColor(2, 0); cout << "Наступает новый день, вы полны сил!" << endl; SetColor(15, 0);

	shop.bread_count = rand() % 5 + 1;
	shop.meat_count = rand() % 5 + 1;
	shop.lemonade_count = rand() % 11;

	short chance;
	for (short i = 0; i < 3; i++)
	{
		chance = rand() % 5 + 1; //шанс выпадения кофе - 0.2
		if (chance == 1)
		{
			shop.coffe_count++;
		}
	}

	shop.bread_cost = rand() % 20 + 50;
	shop.meat_cost = rand() % 1000 + 2000;
	shop.lemonade_cost = rand() % 50 + 70;
	shop.coffe_cost = rand() % 150 + 450;

	
	pers.exLvl = 0;

	SetColor(14, 0); cout << "Интересно, что нового в магазине . . ." << endl; SetColor(15, 0);
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

				pers -= shop.coffe_count * count;
				shop += shop.coffe_count * count;
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

bool isGameLost(person& pers, shopClass& shop)
{
	if (pers.isHungry)//смерть от голода
	{
		system("cls");
		SetColor(4, 0); cout << "Вы не поели сегодня и умерли от истощения" << endl; SetColor(15, 0);
		return false;
	}

	if (pers.money < 0)// кончились деньги у игрока
	{
		system("cls");
		SetColor(4, 0); cout << "Вы разорились! У вас больше нет денег, чтобы завплатить за еду или налоги" << endl; SetColor(15, 0);
		return false;
	}

	if (shop.money < 0)// кончились деньги у магазина
	{
		system("cls");
		SetColor(4, 0); cout << "Единственный магазин в вашем городе разорился! Он не мог больше содержаться и закрылся. Через время вы умерли от голода . . ." << endl; SetColor(15, 0);
		return false;
	}

	pers.isHungry = 1;

	return true;
}




