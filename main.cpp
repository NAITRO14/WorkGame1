#include "mh.h"
#include "shopClass.h"
#include "person.h"

int main()
{
	setlocale(LC_ALL, "ru"); srand(time(NULL));

	shopClass shop;
	short man;
	while (true)
	{
		system("cls");
		cout << "1|Поработать\n2|Пойти в магазин\n3|Лечь спать" << endl;
		cout << "Выбирете действие: "; enter_num(man);

		switch (man)
		{
		case 1:
		{
			cout << "case 1" << endl;
		}break;
		case 2:
		{
			cout << "case 2" << endl;
		}break;
		case 3:
		{
			cout << "case 3" << endl;
		}break;
		}
		system("pause");
	}

}