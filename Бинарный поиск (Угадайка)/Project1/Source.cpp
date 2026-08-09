#include <iostream>
#include <cmath>
#include <climits>

void main() {

	setlocale(LC_CTYPE, "rus");

	long long max_limit = INT_MIN;
	while (max_limit <= 0) {

		printf_s("Введите число:\n");
		scanf_s("%lld", &max_limit);
	}

	bool flag = true;

	long long max = max_limit;
	long long min = 1;

	do {
		
		long long middle = (max - min) / 2 + min;
		printf_s("\nПредполагаемое число: %lld\n", middle);
		printf_s("1. Да; 2. Нет;\n");
		
		int choice;
		printf_s("Введите число:\n");
		scanf_s("%d", &choice);

		switch (choice) {

		case 1:
			printf_s("Компьютер угадал!\n");
			flag = false;
			break;
		case 2:
			printf_s("\n1. Много; 2.Мало;\n");
			printf_s("Введите число:\n");
			scanf_s("%d", &choice);
			switch (choice) {
			case 1:
				max = middle - 1;
				break;
			case 2:
				min = middle + 1;
				break;
			default:
				printf_s("ОШИБКА ВВОДА!\n");
				break;
			}
			break;
		default:
			printf_s("ОШИБКА ВВОДА!\n");
			break;
		}

		if (min > max) {
			printf_s("ОШИБКА В ПРОЦЕССЕ ПОИСКА!\n");
		}


	} while (flag);

	max = max_limit;
	min = 1;
	int steps = 0;

	
	while (min <= max) {
		steps++;
		long long middle = (max - min) / 2 + min;
		printf_s("%lld\n", middle);
		if (middle - min >= max - middle) {
			max = middle - 1;
		}
		else {
			min = middle + 1;
		}
	}
	printf_s("Максимальное число шагов: %d\n", steps);
}