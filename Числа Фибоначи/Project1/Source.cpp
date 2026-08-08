#include <iostream>
#include <ctime>

int Fibonachi(int choice) {

	if (choice == 1) {
		return 0;
	}
	if (choice == 2) {
		return 1;
	}

	return Fibonachi(choice - 1) + Fibonachi(choice - 2);
}

void main() {

	setlocale(LC_CTYPE, "rus");

	bool flag = true;

	do {

		int choice;
		printf_s("Введите число:\n");
		scanf_s("%d", &choice);
		if (choice <= 0) {
			flag = false;
		}
		int timer_s = time(0);
		printf_s("Число Фибоначи: %d\n", Fibonachi(choice));
		int timer_e = time(0);
		printf_s("%d\n", timer_e - timer_s);
	} while (flag);
}