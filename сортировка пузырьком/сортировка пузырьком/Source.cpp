#include <iostream>
#include <cstdarg>
#include <time.h>
#include <cstdlib>

void BubbleSort(int* arr, int size) {

	if (size <= 1) {

		return;
	}
	else {

		int i = 0;
		bool is_sorted = false;
		do {

			is_sorted = false;
			int* lptr = arr;
			int* rptr = arr + 1;
			while (rptr != arr + size - i) {

				if (*lptr > *rptr) {

					is_sorted = true;

					int buf = *rptr;
					*rptr = *lptr;
					*lptr = buf;
				}
				rptr++;
				lptr++;
			}
			i++;
		} while (is_sorted);
	}
}

void main() {
	setlocale(LC_CTYPE, "rus");

	srand(time(0));

	int size;
	printf_s("Введите размер массива:\n");
	scanf_s("%d", &size);

	int* arr = (int*)calloc(size, sizeof(int));

	for (int i = 0; i < size; i++) {

		arr[i] = 1 + rand() % 100;
	}

	printf_s("Исходный массив: \n");
	for (int i = 0; i < size; i++) {

		printf_s("%d ", arr[i]);
	}
	std::cout << std::endl;


	BubbleSort(arr, size);
	printf_s("Отсортированыый массив:\n");

	for (int i = 0; i < size; i++) {

		printf_s("%d ", arr[i]);
	}

	free(arr);
}
