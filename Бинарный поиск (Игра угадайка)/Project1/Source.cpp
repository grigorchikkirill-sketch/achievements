#include <iostream>
#include <climits>
#include <cmath> 

 void  main() { 

	setlocale(LC_CTYPE, "rus");

	int max_limit = INT_MIN;
	while (max_limit <= 0) {
		printf_s("Введите число (верхнюю границу диапазона): \n");
		
		scanf_s("%d", &max_limit);
	}

	bool flag = true;
	int min = 1;
	int max = max_limit;

	do {
		
		int mid = min + (max - min) / 2;

		printf_s("Предполагаемое число: %d\n", mid);

		printf_s("\n1. Да;\n");
		printf_s("2. Нет;\n");

		int choice;
		printf_s("Введите число: \n");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:
			flag = false;
			printf_s("Компьютер угадал число.\n");
			break;
		case 2:
			printf_s("\n1. Больше; ");
			printf_s("2. Меньше;\n");
			printf_s("Введите число: \n");
			scanf_s("%d", &choice);

			switch (choice) {
			case 1:
				min = mid + 1;
				break;
			case 2:
				max = mid - 1;
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
			printf_s("\nОшибка: вы где-то ввели неверные подсказки! Игра окончена.\n");
			break;
		}

	} while (flag);

	
	min = 1;
	max = max_limit;

	
	printf_s("\n Максимальное число шагов: %lld\n", (long long)ceil(log2(max_limit)));

	printf_s("Демонстрация худшего пути (всегда 'Меньше'):\n");

	
	while (min <= max) {
		int mid = min + (max - min) / 2;
		printf_s("%d\n", mid);
		max = mid - 1; 
	}

}



