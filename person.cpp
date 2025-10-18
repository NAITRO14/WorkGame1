#include "person.h"
#include "mh.h"

person::person()
{
	money = 1000;
	bread_count = 0;
	meat_count = 0;
	lemonade_count = 0;

	BankClass::clients++;
}

void person::print_money()
{
	cout << money;
}

void person::to_work(person& p, BankClass& bank)
{
	float mtmp = bank.salary();

	money += mtmp;

	cout << "Заработано: "; SetColor(2, 0); cout << mtmp << endl; SetColor(15, 0);
}

void person::show_inv()
{
	bool isEmpty = 0;
	system("cls");
	cout << "===Рюкзак===" << endl;
	if (bread_count > 0)
	{
		cout << "Хлеб: " << bread_count << endl;
		isEmpty = 1;
	}
	if (meat_count > 0)
	{
		cout << "Мясо: " << meat_count << endl;
		isEmpty = 1;
	}
	if (lemonade_count > 0)
	{
		cout << "Лимонад: " << lemonade_count << endl;
		isEmpty = 1;
	}
	if (isEmpty)
	{
		to_eat();
	}
}

bool person::to_eat()
{
	string inp; bool ate = 0;
	cout << "Введите название предмета, чтобы съесть" << endl;
	cout << "Ввод: ";
	cin >> inp;

	if (inp == "Хлеб" or inp == "хлеб")
	{
		bread_count--;
		ate = 1;
	}
	else if (inp == "Мясо" or inp == "мясо")
	{
		meat_count--;
		ate = 1;
	}
	else if (inp == "Лимонад" or inp == "лимонад")
	{
		lemonade_count--;
		ate = 1;
	}
	return ate;
}

person person::operator-=(float n)
{
	money -= n;
	return person();
}
