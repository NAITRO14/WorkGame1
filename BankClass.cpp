#include "mh.h"

BankClass::BankClass()
{
	money = 40000.0;
}

void BankClass::taxes(shopClass& shop, person& pers)
{
	short critTax = 1;
	if (money <= 5000)
	{
		critTax = 20;
		SetColor(4, 0); cout << "��-�� ���������� �����, ������ ���������" << endl; SetColor(15, 0);
	}

	float persTax = ((rand() % 10 + critTax) / 10.0f) * 1000.0f;
	float shopTax = ((rand() % 10 + critTax) / 10.0f) * 5000.0f;

	pers.money -= persTax;
	shop.money -= shopTax;

	//������� ������ �����
	money += persTax + shopTax;

	cout << "��� ����� �� ������� �������� "; SetColor(12, 0);  cout << persTax << " ���." << endl; SetColor(15, 0);
}

float BankClass::salary()
{
	float sal = (rand() % 1801 + 700) + (rand() % 99 + 1) / 10.0f;
	if (money <= 5000) { sal *= 0.5; SetColor(4, 0); cout << "��-�� ���������� �����, ������� �������." << endl; SetColor(15, 0); } // ������� �������� �����, ���� ���� �� ����� ���������
	
	money -= sal; // ��������� ������ �� ������

	return sal;
}

float BankClass::get_money()
{
	return money;
}

int BankClass::get_clint()
{
	return clients;
}

int BankClass::get_comp()
{
	return companies;
}



//ostream& operator<<(ostream& os, BankClass& bank)
//{
//	cout << "s" << endl;
//	
//	return os;
//}
