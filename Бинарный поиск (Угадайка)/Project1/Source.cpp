#include <iostream>
#include <climits>
#include <math.h>

void main() {

	setlocale(LC_CTYPE, "rus");

	long long max_limit = LLONG_MIN;
	while (max_limit <= 0) {
		printf_s("Введите максимальное число в диапазоне поиска: \n");
		scanf_s("%lld", &max_limit);
	}

	bool flag = true;
	long long min = 1;
	long long max = max_limit;

	do {
		long long middle = (max - min) / 2 + min;
		printf_s("Предболагаемое число: %lld\n", middle); 
		printf_s("\n1. Да; 2. Нет;\n");
		int choice;
		printf_s("Введите число:\n");
		scanf_s("%d", &choice);
		switch (choice) {
		case 1:
			printf_s("Компьютер успешно отгадал!\n");
			flag = false;
			break;
		case 2:
			printf_s("\n 1. Много; 2. Мало;\n");
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
			printf_s("Пользователь ошибся в процессе выбора Много/Мало\n");
			break;
		}
	} while (flag);

	

	min = 1;
	max = max_limit;

	printf_s("Максимально возможное количество поисков: %lld\n", long long(ceil(log2(max_limit))));
	printf_s("Пример худшего сценария поиска:\n");

	while (max >= min) {
		long long middle = (max - min) / 2 + min;
		printf_s("%lld\n", middle);

		
		if ((middle - min) >= (max - middle)) {
			max = middle - 1; 
		}
		else {
			min = middle + 1;
		}
	}
}
