#include <iostream>
#include <cstdarg>
#include <ctime>
#include <cstdlib>

void ShaikerSort(int* arr, int size) {

	bool is_swaped = false;
	int left = 0;
	int right = 0;
	int* lptr = arr;
	int* rptr = arr + 1;
	
	if (size <= 1) {

		return;
	}

	else {
		do {
			is_swaped = false;

			while (rptr != arr + size - right - 1) {
				if (*lptr > *rptr) {
					is_swaped = true;
					int buf = *rptr;
					*rptr = *lptr;
					*lptr = buf;
				}
				lptr++;
				rptr++;
			}
			right++;

			if (!is_swaped) {
				break;
			}

			while (lptr != arr + left) {
				if (*lptr > *rptr) {
					is_swaped = true;
					int buf = *rptr;
					*rptr = *lptr;
					*lptr = buf;
				}
				lptr--;
				rptr--;
			}
			left++;

		} while (is_swaped);
	}
}


void main() {

	setlocale(LC_CTYPE, "rus");
	srand(time(0));

	int size;
	printf_s("Введите число:\n");
	scanf_s("%d", &size);
	
	int* arr = (int*)malloc(sizeof(int) * size);

	printf_s("Исходний массив:\n");
	for (int i = 0; i < size; i++) {

		arr[i] = 1 + rand() % 100;
		printf_s("%d ", arr[i]);
	}

	ShaikerSort(arr, size);

	printf_s("\nОтсортированный массив:\n");
	for (int i = 0; i < size; i++) {

		printf_s("%d ", arr[i]);
	}

	free(arr);
}