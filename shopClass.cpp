#include "shopClass.h"
#include "mh.h"

shopClass::shopClass()
{
	money = 30000;
	//��������� ������� ��� �� ������ ����
	bread_cost = rand() % 20 + 50;
	meat_cost = rand() % 1000 + 2000;
	lemonade_cost = rand() % 50 + 70;

	//������ ����� � �� ���� ������
	lemonade_count = rand() % 11;
	bread_count = rand() % 6;
	meat_count = rand() % 6;

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

