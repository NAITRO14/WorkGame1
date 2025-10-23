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

void sleep_act(shopClass & shop, person& pers)
{
	pers.sleep();
	shop.sleep();
}



bool to_buy(shopClass& shop, person& pers)
{
	short man; short count;

	cout << "Ввод: ";
	enter_num(man);
	switch (man)
	{
	case 0:
	{
		return 0;
	}break;
	case 1:
	{
		if (shop.bread_count == 0) { cout << "Больше нет, приходи завтра, может, завезут" << endl; system("pause"); return 1; }
		cout << "Сколько вам ?" << endl;
		cout << "Ввод: "; enter_num(count);

		if (count * shop.bread_cost > pers.money)
		{
			cout << "Кажется, у меня не хватит на это денег . . ." << endl;
			system("pause");
			return 1;
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
		if (shop.meat_count == 0) { cout << "Больше нет, приходи завтра, может, завезут" << endl; system("pause"); return 1; }
		cout << "Сколько вам ?" << endl;
		cout << "Ввод: "; enter_num(count);

		if (count * shop.meat_cost > pers.money)
		{
			cout << "Кажется, у меня не хватит на это денег . . ." << endl;
			system("pause");
			return 1;
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
		if (shop.lemonade_count == 0) { cout << "Больше нет, приходи завтра, может, завезут" << endl; system("pause"); return 1; }
		cout << "Сколько вам ?" << endl;
		cout << "Ввод: "; enter_num(count);

		if (count * shop.lemonade_cost > pers.money)
		{
			cout << "Кажется, у меня не хватит на это денег . . ." << endl;
			system("pause");
			return 1;
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
		if (shop.coffe_count == 0) { cout << "Больше нет, приходи завтра, может, завезут" << endl; system("pause"); return 1; }
		cout << "Сколько вам ?" << endl;
		cout << "Ввод: "; enter_num(count);

		if (count * shop.coffe_cost > pers.money)
		{
			cout << "Кажется, у меня не хватит на это денег . . ." << endl;
			system("pause");
			return 1;
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



bool isGameLost(person& pers, shopClass& shop, BankClass& bank)
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

	if (bank.money < 0)// кончились деньги у магазина
	{
		system("cls");
		SetColor(4, 0); cout << "Центральный банк вашего города, единственная экономическая опора, которая могла немного сдерживать хаос, разорился. Работы в городе нет, еды нет, а по улицам ходят раъяренные ситуацией люди и творят бесчинства. Через время вы умираете, из-за того, что вас сосед выстреливает вам голову из пистолета, чтобы украсть у вас еду" << endl; SetColor(15, 0);
		return false;
	}

	pers.isHungry = 1;

	return true;
}




