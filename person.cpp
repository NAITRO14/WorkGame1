#include "person.h"
#include "mh.h"

person::person()
{
	money = 1500;

	//продукты
	bread_count = 1;
	meat_count = 0;
	lemonade_count = 0;
	coffe_count = 0;

	isHungry = 1;


	BankClass::clients++;
}

bool person::get_hunger()
{
	return isHungry;
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

void person::show_inv(short mang)
{
	bool isEmpty = 1;
	system("cls");
	if (mang == 2)
	{
		SetColor(LightRed, 0); cout << "Вы еще не если сегодня, перд сном вам нужно поесть" << endl; SetColor(15, 0);

	}
	cout << "===Рюкзак===" << endl;
	if (bread_count > 0)
	{
		cout << "Хлеб: " << bread_count << endl;
		isEmpty = 0;
	}
	if (meat_count > 0)
	{
		cout << "Мясо: " << meat_count << endl;
		isEmpty = 0;
	}
	if (lemonade_count > 0)
	{
		cout << "Лимонад: " << lemonade_count << endl;
		isEmpty = 0;
	}
	if (coffe_count > 0)
	{
		cout << "Кофе: " << coffe_count << endl;
		isEmpty = 0;
	}

	if (isEmpty)
	{
		cout << "У вас ничего нет" << endl;
	}

	to_eat(mang);
}

void person::to_eat(short mang)
{
	string inp; bool isIn = 1;
	SetColor(8, 0);
	cout << "---------------------------------------" << endl;
	cout << "Введите название предмета, чтобы съесть" << endl;
	if (mang == 1)
	{
		cout << "0 -- вернуться назад" << endl;
	}
	else
	{
		cout << "0 -- не есть(смерть)" << endl;
	}
	cout << "---------------------------------------" << endl;
	SetColor(15, 0);
	cout << "Ввод: ";
	cin >> inp;


	if (inp == "0")
	{
		return;
	}
	if (inp == "Хлеб" or inp == "хлеб")
	{
		bread_count--;
		isHungry = 0;
		
	}
	else if (inp == "Мясо" or inp == "мясо")
	{
		meat_count--;
		isHungry = 0;
		
	}
	else if (inp == "Лимонад" or inp == "лимонад")
	{
		lemonade_count--;
		isHungry = 0;
		
	}
	else if (inp == "Кофе" or inp == "кофе")
	{
		coffe_count--;
		isHungry = 0;
		exLvl -= 2;

	}
	else
	{
		cout << "Повторите ввод" << endl;
		system("pause");
		show_inv(mang); //повторить выводк текста
		return; //прервать функцию
	}
	if (mang == 1)
	{
		show_inv(mang);
	}
	return;
	
}

person person::operator-=(float n)
{
	money -= n;
	return person();
}
