#include "shopClass.h"
#include "mh.h"

shopClass::shopClass()
{
	money = 20000;
	//��������� ������� ��� �� ������ ����
	bread_cost = rand() % 20 + 50.0f;
	meat_cost = rand() % 1000 + 2000.0f;
	lemonade_cost = rand() % 50 + 70.0f;
	coffe_cost = rand() % 150 + 450.0f;
	yogurt_cost = rand() % 101 + 200;

	//������ ����� � �� ���� ������
	lemonade_count = rand() % 11;
	bread_count = rand() % 9;
	meat_count = rand() % 6;
	yogurt_count = rand() % 7;

	coffe_count = 0;

	short chance;
	for (short i = 0; i < 3; i++)
	{
		chance = rand() % 6;
		if (chance == 1)
		{
			coffe_count++;
		}
	}

	BankClass::companies++;
}

int shopClass::get_b()
{
	return bread_count;
}

int shopClass::get_m()
{
	return meat_count;
}

void shopClass::print_money()
{
	cout << "����� � ��������: " << money << endl;
}

float shopClass::get_money()
{
	return money;
}

shopClass shopClass::operator+=(float n)
{
	money += n;

	return shopClass();
}

void shopClass::sleep()
{
	//������ ���-�� �������
	bread_count = rand() % 5 + 1;
	meat_count = rand() % 5 + 1;
	lemonade_count = rand() % 11;
	yogurt_count = rand() % 7;

	//������ ����(���� ���������)
	short chance;
	for (short i = 0; i < 3; i++)
	{
		chance = rand() % 5 + 1; //���� ��������� ���� - 0.2
		if (chance == 1)
		{
			coffe_count++;
		}
	}

	//������� ���
	bread_cost = rand() % 20 + 50.0f;
	meat_cost = rand() % 1000 + 2000.0f;
	lemonade_cost = rand() % 50 + 70.0f;
	coffe_cost = rand() % 150 + 450.0f;

	SetColor(14, 0); cout << "���������, ��� ������ � �������� . . ." << endl; SetColor(15, 0);

}

void shopClass::show_shop(shopClass& shop, person& pers)
{
	bool isIn = 1;

	while (isIn)
	{
		system("cls");
		shop.print_money();

		cout << "1|����: " << shop.bread_count << " | ���������: " << shop.bread_cost << endl;
		cout << "2|����: " << shop.meat_count << " | ���������: " << shop.meat_cost << endl;
		cout << "3|�������: " << shop.lemonade_count << " | ���������: " << shop.lemonade_cost << endl;
		cout << "4|����: " << shop.coffe_count << " | ���������: " << shop.coffe_cost << endl;
		cout << "5|������: " << shop.yogurt_count << " | ���������: " << shop.yogurt_cost << endl;



		SetColor(8, 0);
		cout << "--------------------" << endl;
		cout << "������ ������ ���-��?" << endl;
		cout << "1-4 -- ������ �����" << endl;
		cout << "0 -- ����" << endl;
		cout << "--------------------" << endl;
		SetColor(15, 0);

		isIn = to_buy(shop, pers);
	}
}

//ostream& operator<<(ostream& os, shopClass& shop)
//{
//	cout << "���������� � ��������" << endl;
//	cout << "��������� ������: ����, ����, ������� " << endl;
//	cout << "������� ��������: ������� ����������" << endl;
//	cout << "������ ��������: " << shop.get_money() << endl;
//
//	return os;
//}

