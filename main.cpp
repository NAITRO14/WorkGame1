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
		
		cout << "����� � ��������: "; pers.print_money(); cout << "    ����: " << day; cout << "    ����� � �����: " << bank.get_money() << endl;
		cout << "1|����������\n2|����� � �������\n3|���� �����\n4|������� ������" << endl;
		
		SetColor(DarkGray, 0);
		cout << "----------------" << endl;
		cout << "1-4 -- ������� ��������" << endl;
		cout << "----------------" << endl;
		SetColor(15, 0);

		cout << "����: "; enter_num(man);

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
			sleep_act(shop, pers);
			bank.taxes(shop, pers);
			isIn = isGameLost(pers, shop);

			works_per_day = 0;
			day++;
			
		}break;
		case 4:
		{
			pers.show_inv(1);
			continue;
		}break;
		}
		system("pause");
	}

}