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
	yogurt_count = 0;

	isHungry = 1;


	BankClass::clients++;
}

int person::get_ex()
{
	return exLvl;
}

short person::get_protein()
{
	return protein;
}

short person::get_carbon()
{
	return carbons;
}

short person::get_fat()
{
	return fats;
}

bool person::get_hunger()
{
	return isHungry;
}

void person::print_money()
{
	cout << money;
}

float person::getMoney()
{
	return money;
}

void person::to_work(BankClass& bank)
{
	if (exLvl == 3) { GotoXY(20, 18); SetColor(4, 0); cout << "Вы очень устали и больше не можете работать. . ." << endl; SetColor(15, 0); return; }
	if (protein < 20 or carbons < 20 or fats < 20) { GotoXY(10, 18); SetColor(4, 0); cout << "Вы слишком истощены, чтобы работать. Для начала, вам нужно поесть" << endl; SetColor(15, 0); return; }

	protein -= rand() % 10 + 3;
	carbons -= rand() % 10 + 3;
	fats -= rand() % 10 + 3;

	float mtmp = bank.salary();
	money += mtmp;

	GotoXY(28 , 10); cout << "Заработано: "; SetColor(2, 0); cout << mtmp << endl; SetColor(15, 0);
	exLvl++;
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
	if (yogurt_count > 0)
	{
		cout << "Йогурт: " << yogurt_count << endl;
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

	GotoXY(22, 14); cout << "Белки:    "; cout << "["; if (protein < 30) SetColor(4, 0); else SetColor(10, 0); for (short i = 0; i < protein / 10; i++) { cout << " # "; } SetColor(15, 0); for (short i = 0; i < 10 - protein / 10; i++) { cout << " * "; } cout << "]";
	GotoXY(22, 15); cout << "Жиры:     "; cout << "["; if (fats < 30) SetColor(4, 0); else SetColor(10, 0);  for (short i = 0; i < fats / 10; i++) { cout << " # "; } SetColor(15, 0); for (short i = 0; i < 10 - fats / 10; i++) { cout << " * "; } cout << "]";
	GotoXY(22, 16); cout << "Углеводы: "; cout << "["; if (carbons < 30) SetColor(4, 0); else SetColor(10, 0); for (short i = 0; i < carbons / 10; i++) { cout << " # "; }  SetColor(15, 0); for (short i = 0; i < 10 - carbons / 10; i++) { cout << " * "; } cout << "]";

	GotoXY(60, 6); cout << "Ввод: ";
	GotoXY(65, 6); cin >> inp;


	if (inp == "0")
	{
		return;
	}
	if (inp == "Хлеб" or inp == "хлеб")
	{
		bread_count--;
		isHungry = 0;

		carbons += rand() % 16 + 6; 
		fats += rand() % 3; // 0 - 2
		protein += rand() % 2; // 0 - 1
		
	}
	else if (inp == "Мясо" or inp == "мясо")
	{
		meat_count--;
		isHungry = 0;

		protein += rand() % 21 + 20;
		fats += rand() % 15 + 5; 
		carbons += rand() % 3; // 0 - 2
	}
	else if (inp == "Лимонад" or inp == "лимонад")
	{
		lemonade_count--;
		isHungry = 0;

		carbons += rand() % 17 + 5;
		
	}
	else if (inp == "Кофе" or inp == "кофе")
	{
		coffe_count--;
		isHungry = 0;
		
		//небольшой буст
		exLvl -= 2;
		protein += 15;
		fats += 15;
		carbons += 15;

	}
	else if (inp == "Йогурт" or inp == "йогурт")
	{
		yogurt_count--;
		isHungry = 0;

		protein += rand() % 3;;
		fats += rand() % 16 + 15;
		carbons += rand() % 4;

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
	if (protein > 100) protein = 100;
	if (fats > 100) fats = 100;
	if (carbons > 100) carbons = 100;

	return;
	
}

void person::sleep()
{
	if (isHungry)
	{
		show_inv(2);
	}
	system("cls");
	
	protein -= rand() % 15 + 6;
	carbons -= rand() % 15 + 6;
	fats -= rand() % 15 + 6;

	exLvl = 0;
	SetColor(2, 0); cout << "Наступает новый день, вы полны сил!" << endl; SetColor(15, 0);
}

person person::operator-=(float n)
{
	money -= n;
	return person();
}
