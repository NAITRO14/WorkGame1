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
		cout << "1|Поработать\n2|Пойти в магазин\n3|Лечь спать" << endl;
		cout << "Выбирете действие: "; enter_num(man);

		switch (man)
		{
		case 1:
		{
			if (works_per_day < 3)
			{
				to_work(pers);
				pers.print_money();
				works_per_day++;
			}
			else
			{
				cout << "Вы очень устали и больше не можете работать. . ." << endl;
			}
			
		}break;
		case 2:
		{
			cout << "case 2" << endl;
		}break;
		case 3:
		{
			cout << "Вы легли спать и на утро чувтсвуете, что отдохнули очень хорошо" << endl;
			works_per_day = 0;
		}break;
		}
		system("pause");
	}

}