#include "mh.h"

void enter_num(short& num)
{
	while (true) {
		if (cin >> num) {  // ���� ���� ����������
			break;         // ����� �� �����
		}
		else {
			SetColor(4, 0); cout << "������ �����. ������� ����� ������." << endl; SetColor(15, 0);
			cout << "����: ";
			cin.clear(); // ������� ������
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // �������� �����
		}
	}
}

int work_act(short wpd, person& pers, BankClass& bank)
{
	if (wpd < 3)
	{
		pers.to_work(pers, bank);
		wpd++;
	}
	else
	{
		SetColor(4, 0); cout << "�� ����� ������ � ������ �� ������ ��������. . ." << endl; SetColor(15, 0);
	}
	return wpd;
}

void sleep_act(shopClass & shop, person& pers)
{
	if (pers.get_hunger())
	{
		pers.show_inv(2);
	}

	system("cls");
	SetColor(2, 0); cout << "��������� ����� ����, �� ����� ���!" << endl; SetColor(15, 0);

	shop.bread_count = rand() % 5 + 1;
	shop.meat_count = rand() % 5 + 1;
	shop.lemonade_count = rand() % 11;

	shop.bread_cost = rand() % 20 + 50;
	shop.meat_cost = rand() % 1000 + 2000;
	shop.lemonade_cost = rand() % 50 + 70;

	SetColor(14, 0); cout << "���������, ��� ������ � �������� . . ." << endl; SetColor(15, 0);
}

void show_shop(shopClass& shop, person& pers)
{
	bool isIn = 1;
	short man; short count;
	while (isIn)
	{
		system("cls");
		shop.print_money();

		cout << "1|����: " << shop.bread_count << " | ���������: " << shop.bread_cost << endl;
		cout << "2|����: " << shop.meat_count << " | ���������: " << shop.meat_cost << endl;
		cout << "3|�������: " << shop.lemonade_count << " | ���������: " << shop.lemonade_cost << endl;
		
		SetColor(8, 0);
		cout << "--------------------" << endl;
		cout << "������ ������ ���-��?" << endl;
		cout << "1-3 -- ������ �����" << endl;
		cout << "0 -- ����" << endl;
		cout << "--------------------" << endl;
		SetColor(15, 0);

		cout << "����: ";
		enter_num(man);
		switch (man)
		{
		case 0:
		{
			isIn = 0;
		}break;
		case 1:
		{
			if (shop.bread_count == 0) { cout << "������ ���, ������� ������, �����, �������" << endl; system("pause"); continue; }
			cout << "������� ��� ?" << endl;
			cout << "����: "; enter_num(count);

			if (count * shop.bread_cost > pers.money)
			{
				cout << "�������, � ���� �� ������ �� ��� ����� . . ." << endl;
				continue;
			}

			if (count <= shop.bread_count)
			{
				shop.bread_count -= count;
				pers.bread_count += count;

				pers -= shop.bread_cost * count;
				shop += shop.bread_cost * count;
			}
			else
			{
				cout << "������� ���. ���� ���������� ������ " << shop.bread_count << endl;
				system("pause");
			}

		}break;
		case 2:
		{
			if (shop.meat_count == 0) { cout << "������ ���, ������� ������, �����, �������" << endl; continue; }
			cout << "������� ��� ?" << endl;
			cout << "����: "; enter_num(count);

			if (count * shop.meat_cost > pers.money)
			{
				cout << "�������, � ���� �� ������ �� ��� ����� . . ." << endl;
				system("pause");
				continue;
			}

			if (count <= shop.meat_count)
			{
				shop.meat_count -= count;
				pers.meat_count += count;

				pers -= shop.meat_cost * count;
				shop += shop.meat_cost * count;
			}
			else
			{
				cout << "������� ���. ���� ���������� ������ " << shop.meat_count << endl;
				system("pause");
			}

		}break;
		case 3:
		{
			if (shop.lemonade_count == 0) { cout << "������ ���, ������� ������, �����, �������" << endl; continue; }
			cout << "������� ��� ?" << endl;
			cout << "����: "; enter_num(count);

			if (count * shop.lemonade_cost > pers.money)
			{
				cout << "�������, � ���� �� ������ �� ��� ����� . . ." << endl;
				continue;
			}

			if (count <= shop.lemonade_count)
			{
				shop.lemonade_count -= count;
				pers.lemonade_count += count;

				pers -= shop.lemonade_cost * count;
				shop += shop.lemonade_cost * count;
			}
			else
			{
				cout << "������� ���. ���� ���������� ������ " << shop.bread_count << endl;
				system("pause");
			}

		}break;
		}
	}
}

bool isGameLost(person& pers, shopClass& shop)
{
	if (pers.isHungry)//������ �� ������
	{
		system("cls");
		SetColor(4, 0); cout << "�� �� ����� ������� � ������ �� ���������" << endl; SetColor(15, 0);
		return false;
	}

	if (pers.money < 0)// ��������� ������ � ������
	{
		system("cls");
		SetColor(4, 0); cout << "�� ����������! � ��� ������ ��� �����, ����� ���������� �� ��� ��� ������" << endl; SetColor(15, 0);
		return false;
	}

	if (shop.money < 0)// ��������� ������ � ��������
	{
		system("cls");
		SetColor(4, 0); cout << "������������ ������� � ����� ������ ���������! �� �� ��� ������ ����������� � ��������. ����� ����� �� ������ �� ������ . . ." << endl; SetColor(15, 0);
		return false;
	}

	pers.isHungry = 1;

	return true;
}




