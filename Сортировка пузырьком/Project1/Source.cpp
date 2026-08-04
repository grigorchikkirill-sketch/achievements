#include <iostream>
#include <ctime>
#include <cstdlib>

void BubbleSort(int* arr, int size) {

	if (size <= 1) {
		return;
	}
	int limit = size;

	bool is_swaped = false;

	do {
		is_swaped = false;

		int i = 1;
		while (i != limit) {

			if (arr[i - 1] > arr[i]) {
				int buf = arr[i - 1];
				arr[i - 1] = arr[i];
				arr[i] = buf;
				is_swaped = true;
			}

			i++;
		}

		limit--;
	} while (is_swaped);
}

void main() {

	setlocale(LC_CTYPE, "rus");
	srand(time(nullptr));

	int size;
	int* arr;

	printf_s("Введите число:\n");
	scanf_s("%d", &size);

	arr = (int*)calloc(size, sizeof(int));

	printf_s("Исходный массив: \n");

	for (int* ptr = arr; ptr != arr + size; ptr++) {

		 *ptr = 0 + rand() % (100 - 0 + 1);
		 printf_s("%d ", *ptr);
	}


	BubbleSort(arr, size);

	printf_s("\nОтсортированный массив: ");

	for (int* ptr = arr; ptr != arr + size; ptr++) {

		printf_s("%d ", *ptr);
	}

	free(arr);
}