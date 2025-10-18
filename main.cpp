#include "mh.h"
#include "shopClass.h"
#include "person.h"
#include "BankClass.h"

int main()
{
	setlocale(LC_ALL, "ru"); srand(time(NULL));

	shopClass shop; person pers; BankClass bank;
	short man; short works_per_day = 0;
	short day = 0; bool isIn = 1;
	while (isIn)
	{
		system("cls");
		
		

		cout << "����� � ��������: "; pers.print_money(); cout << "    ����: " << day; cout << "    ����� � �����: " << bank.get_money() << endl;
		cout << "1|����������\n2|����� � �������\n3|���� �����" << endl;
		cout << "�������� ��������: "; enter_num(man);

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
			works_per_day = sleep_act(works_per_day, shop, pers);
			bank.taxes(shop, pers);
			if (isGameLost(pers, shop))
			{
				isIn = false;
			}
			day++;
		}break;
		}
		system("pause");
	}

}