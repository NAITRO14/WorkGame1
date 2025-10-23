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
	short man;
	short day = 0; bool isIn = 1;
	

	while (isIn)
	{
		system("cls");
		
		cout << "Денег в кошельке: "; pers.print_money(); cout << "    День: " << day << endl;
		
		GotoXY(40, 0); cout << "Энергия: ";
		cout << "["; if (pers.get_ex() < 3) { for (short i = 3; i > pers.get_ex(); i--) { cout << " # "; } }
		else { cout << " ! "; } cout << "]";

		GotoXY(27, 14); cout << "Белки:    "; cout << "["; if (pers.get_protein() < 30) SetColor(4, 0); else SetColor(10, 0); for (short i = 0; i < pers.get_protein() / 10; i++) { cout << " # "; } SetColor(15, 0); for (short i = 0; i < 10 - pers.get_protein() / 10; i++) { cout << " * "; } cout << "]";
		GotoXY(27, 15); cout << "Жиры:     "; cout << "["; if (pers.get_fat() < 30) SetColor(4, 0); else SetColor(10, 0);  for (short i = 0; i < pers.get_fat() / 10; i++) { cout << " # "; } SetColor(15, 0); for (short i = 0; i < 10 - pers.get_fat() / 10; i++) { cout << " * "; } cout << "]";
		GotoXY(27, 16); cout << "Углеводы: "; cout << "["; if (pers.get_carbon() < 30) SetColor(4, 0); else SetColor(10, 0); for (short i = 0; i < pers.get_carbon() / 10; i++) { cout << " # "; }  SetColor(15, 0); for (short i = 0; i < 10 - pers.get_carbon() / 10; i++) { cout << " * "; } cout << "]";



		GotoXY(10, 4); cout << "1|Поработать ";
		GotoXY(10, 5); cout << "2|Пойти в магазин"; 
		GotoXY(50, 4); cout << "3|Лечь спать";
		GotoXY(50, 5); cout << "4|Открыть рюкзак";
		
		SetColor(8, 0);
		GotoXY(27, 7); cout << "|-----------------------|" << endl;
		GotoXY(27, 8); cout << "|1-4 -- выбрать действие|" << endl;
		GotoXY(27, 9); cout << "|-----------------------|" << endl;
		GotoXY(27, 10); cout << "|                       |" << endl;
		//ввод
		GotoXY(27, 11); cout << "|-----------------------|" << endl;
		SetColor(15, 0);

		GotoXY(28, 10); cout << "Ввод: "; enter_num(man);

		switch (man)
		{
		case 1:
		{
			pers.to_work(bank);
		}break;
		case 2:
		{
			shop.show_shop(shop, pers);
			continue;
		}break;
		case 3:
		{
			sleep_act(shop, pers);
			bank.taxes(shop, pers);
			isIn = isGameLost(pers, shop, bank);

			day++;
			
		}break;
		case 4:
		{
			pers.show_inv(1);
			continue;
		}break;
		//вывод служебной информации
		case 1001: //количество клиентов
		{
			cout << "Количество клиентов: " << bank.get_clint() << endl;
		}break;
		case 1002: //количество компаний
		{
			cout << "Количество компаний: " << bank.get_comp() << endl; 
		}break;
		case 1003: //Денег у банка
		{
			cout << "Денег у банка: " << bank.get_money() << endl;
		}break;
		case 1004: //Денег у магазина
		{
			cout << "Денег у магазина: " << shop.get_money() << endl;
		}break;
		case 1005: //Посмотреть БЖУ
		{
			SetColor(8, 0);
			cout << "----------------" << endl;
			cout << "Белки: " << pers.get_protein() << endl;
			cout << "Жиры:" << pers.get_fat() << endl;
			cout << "Углеводы:" << pers.get_carbon() << endl;
			cout << "----------------" << endl;
			SetColor(15, 0);
		}break;
		}
		system("pause");
	}

}