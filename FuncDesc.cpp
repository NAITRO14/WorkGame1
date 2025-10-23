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



bool to_buy(shopClass& shop, person& pers)
{
	short man; short count;

	cout << "����: ";
	enter_num(man);
	switch (man)
	{
	case 0:
	{
		return 0;
	}break;
	case 1:
	{
		if (shop.bread_count == 0) { cout << "������ ���, ������� ������, �����, �������" << endl; system("pause"); return 1; }
		cout << "������� ��� ?" << endl;
		cout << "����: "; enter_num(count);

		if (count * shop.bread_cost > pers.money)
		{
			cout << "�������, � ���� �� ������ �� ��� ����� . . ." << endl;
			system("pause");
			return 1;
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
		if (shop.meat_count == 0) { cout << "������ ���, ������� ������, �����, �������" << endl; system("pause"); return 1; }
		cout << "������� ��� ?" << endl;
		cout << "����: "; enter_num(count);

		if (count * shop.meat_cost > pers.money)
		{
			cout << "�������, � ���� �� ������ �� ��� ����� . . ." << endl;
			system("pause");
			return 1;
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
		if (shop.lemonade_count == 0) { cout << "������ ���, ������� ������, �����, �������" << endl; system("pause"); return 1; }
		cout << "������� ��� ?" << endl;
		cout << "����: "; enter_num(count);

		if (count * shop.lemonade_cost > pers.money)
		{
			cout << "�������, � ���� �� ������ �� ��� ����� . . ." << endl;
			system("pause");
			return 1;
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
	case 4:
	{
		if (shop.coffe_count == 0) { cout << "������ ���, ������� ������, �����, �������" << endl; system("pause"); return 1; }
		cout << "������� ��� ?" << endl;
		cout << "����: "; enter_num(count);

		if (count * shop.coffe_cost > pers.money)
		{
			cout << "�������, � ���� �� ������ �� ��� ����� . . ." << endl;
			system("pause");
			return 1;
		}

		if (count <= shop.coffe_count)
		{
			shop.coffe_count -= count;
			pers.coffe_count += count;

			pers -= shop.coffe_cost * count;
			shop += shop.coffe_cost * count;
		}
		else
		{
			cout << "������� ���. ���� ���������� ������ " << shop.bread_count << endl;
			system("pause");
		}

	}break;
	}
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




