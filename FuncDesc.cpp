#include "mh.h"

void enter_num(short& num)
{
	while (true) {
		if (cin >> num) {  // ���� ���� ����������
			break;         // ����� �� �����
		}
		else {
			cout << "������ �����. ������� ����� ������." << endl;
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
		cout << "�� ����� ������ � ������ �� ������ ��������. . ." << endl;
	}
	return wpd;
}

int sleep_act(int wpd, shopClass & shop, person& pers)
{
	cout << "��������� ����� ����, �� ����� ���!" << endl;
	wpd = 0;

	shop_sleep(shop);
	return wpd;
}

void shop_sleep(shopClass& shop)
{
	shop.bread_count = rand() % 5 + 1;
	shop.meat_count = rand() % 5 + 1;
	shop.lemonade_count = rand() % 11;

	shop.bread_cost = rand() % 20 + 50;
	shop.meat_cost = rand() % 1000 + 2000;
	shop.lemonade_cost = rand() % 50 + 70;

	cout << "���������, ��� ������ � �������� . . ." << endl;
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
		
		cout << "--------------------" << endl;
		cout << "������ ������ ���-��?" << endl;
		cout << "1-3 -- ������ �����" << endl;
		cout << "0 -- ����" << endl;
		cout << "--------------------" << endl;

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
			if (shop.bread_count == 0) { cout << "������ ���, ������� ������, �����, �������" << endl; continue; }
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
	if (pers.money < 0)
	{
		system("cls");
		cout << "�� ����������! � ��� ������ ��� �����, ����� ���������� �� ��� ��� ������" << endl;
		return true;
	}

	if (shop.money < 0)
	{
		system("cls");
		cout << "������������ ������� � ����� ������ ���������! �� �� ��� ������ ����������� � ��������. ����� ����� �� ������ �� ������ . . ." << endl;
		return true;
	}

	return false;
}




