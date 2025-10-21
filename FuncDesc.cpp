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




