#include "mh.h"
#include "shopClass.h"
#include "person.h"
#include "BankClass.h"

int BankClass::clients = 0;
int BankClass::companies = 0;


int main()
{
	setlocale(LC_ALL, "ru"); srand(time(NULL));
	SetConsoleCP(1251); SetConsoleOutputCP(1251);

	shopClass shop; person pers; BankClass bank;
	short man; short works_per_day = 0;
	short day = 0; bool isIn = 1;
	

	while (isIn)
	{
		system("cls");
		
		cout << "Денег в кошельке: "; pers.print_money(); cout << "    День: " << day; cout << "    Денег у банка: " << bank.get_money() << endl;
		cout << "1|Поработать\n2|Пойти в магазин\n3|Лечь спать\n4|Открыть рюкзак" << endl;
		cout << "Выбирете действие: "; enter_num(man);

		switch (man)
		{
		case 1:
		{
			works_per_day = work_act(works_per_day, pers, bank);
		}break;
		case 2:
		{
			show_shop(shop, pers);
			continue;
		}break;
		case 3:
		{
			if (!sleep_act(shop, pers))
			{
				isIn = 0;
				SetColor(4, 0); cout << "Вы не поели сегодня и умерли от истощения" << endl; SetColor(15, 0);
				continue;
			}
			bank.taxes(shop, pers);
			if (isGameLost(pers, shop))
			{
				isIn = false;
			}
			works_per_day = 0;
			day++;
		}break;
		case 4:
		{
			pers.show_inv();
		}break;
		}
		system("pause");
	}

}