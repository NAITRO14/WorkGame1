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
		cout << "1|����������\n2|����� � �������\n3|���� �����" << endl;
		cout << "�������� ��������: "; enter_num(man);

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
				cout << "�� ����� ������ � ������ �� ������ ��������. . ." << endl;
			}
			
		}break;
		case 2:
		{
			cout << "case 2" << endl;
		}break;
		case 3:
		{
			cout << "�� ����� ����� � �� ���� ����������, ��� ��������� ����� ������" << endl;
			works_per_day = 0;
		}break;
		}
		system("pause");
	}

}