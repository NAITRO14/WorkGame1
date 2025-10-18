#include "shopClass.h"
#include "mh.h"

shopClass::shopClass()
{
	money = 20000;
	//��������� ������� ��� �� ������ ����
	bread_cost = rand() % 50 + 70;
	meat_cost = rand() % 2000 + 2500;
	lemonade_cost = rand() % 100 + 120;

	//������ ����� � �� ���� ������
	lemonade_count = rand() % 11;
	bread_count = rand() % 9;
	meat_count = rand() % 6;

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

int shopClass::get_money()
{
	return money;
}

shopClass shopClass::operator+=(float n)
{
	money += n;

	return shopClass();
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

