#include "mh.h"

void enter_num(short& num)
{
	while (true) {
		if (cin >> num) {  // если ввод корректный
			break;         // выйти из цикла
		}
		else {
			cout << "Ошибка ввода. Введите число заново." << endl;
			cout << "Ввод: ";
			cin.clear(); // очистка ошибки
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // очистить буфер
		}
	}
}

void to_work(person& p)
{
	short rtmp = rand() % 4001 + 1000;
	short ptmp = rand() % 100 + 1;
	p.rub += rtmp;
	p.pen += ptmp;

	cout << "Заработано: " << rtmp << "." << ptmp << endl;
	
}
