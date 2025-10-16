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

void to_work(person& p)
{
	float mtmp = (rand() % 1001 + 500) + (rand() % 99 + 1)/10.0;

	p.money += mtmp;

	cout << "����������: " << mtmp << endl;
	
}

int work_act(short wpd, person& pers)
{
	if (wpd < 3)
	{
		to_work(pers);
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
	taxes(shop, pers);
	return wpd;
}

void shop_sleep(shopClass& shop)
{
	shop.bread_count = rand() % 5 + 1;
	shop.meat_count = rand() % 5 + 1;

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
		
		cout << "--------------------" << endl;
		cout << "������ ������ ���-��?" << endl;
		cout << "1-2 -- ������ �����" << endl;
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
				pers -= shop.bread_cost;
				shop += shop.bread_cost;
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
				pers -= shop.meat_cost;
				shop += shop.meat_cost;
			}
			else
			{
				cout << "������� ���. ���� ���������� ������ " << shop.meat_count << endl;
				system("pause");
			}

		}break;
		}
	}
}

void taxes(shopClass& shop, person& pers)
{
	float persTax = (rand() % 10 + 1)/10.0;
	float shopTax = (rand() % 10 + 1)/10.0;

	pers.money -= 1000 * persTax;
	shop.money -= 5000 * shopTax;

	cout << "��� ����� �� ������� �������� " << 1000 * persTax << " ���." << endl;
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


