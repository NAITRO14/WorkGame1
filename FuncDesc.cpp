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

void sleep_act(shopClass & shop, person& pers)
{
	pers.sleep();
	shop.sleep();
}



bool isGameLost(person& pers, shopClass& shop, BankClass& bank)
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

	if (bank.money < 0)// ��������� ������ � ��������
	{
		system("cls");
		SetColor(4, 0); cout << "����������� ���� ������ ������, ������������ ������������� �����, ������� ����� ������� ���������� ����, ���������. ������ � ������ ���, ��� ���, � �� ������ ����� ���������� ��������� ���� � ������ ����������. ����� ����� �� ��������, ��-�� ����, ��� ��� ����� ������������ ��� ������ �� ���������, ����� ������� � ��� ���" << endl; SetColor(15, 0);
		return false;
	}

	pers.isHungry = 1;

	return true;
}




