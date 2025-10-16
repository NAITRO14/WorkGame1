#include "mh.h"

void enter_num(short& num)
{
	while (true) {
		if (cin >> num) {  // если ввод корректный
			break;         // выйти из цикла
		}
		else {
			cout << "ќшибка ввода. ¬ведите число заново." << endl;
			cout << "¬вод: ";
			cin.clear(); // очистка ошибки
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // очистить буфер
		}
	}
}