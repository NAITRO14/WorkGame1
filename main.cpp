#include "mh.h"
#include "shopClass.h"
#include "person.h"

int main()
{
	setlocale(LC_ALL, "ru"); srand(time(NULL));

	shopClass shop; person pers;
	short man; short works_per_day = 0;
	short day = 0;
	while (true)
	{
		system("cls");
		cout << "Денег в кошельке: "; pers.print_money();
		cout << "1|Поработать\n2|Пойти в магазин\n3|Лечь спать" << endl;
		cout << "Выбирете действие: "; enter_num(man);

		switch (man)
		{
		case 1:
		{
			
			works_per_day = work_act(works_per_day, pers);
		}break;
		case 2:
		{
			show_shop(shop, pers);
		}break;
		case 3:
		{
			works_per_day = sleep_act(works_per_day, shop, pers);
		}break;
		}
		system("pause");
	}

}