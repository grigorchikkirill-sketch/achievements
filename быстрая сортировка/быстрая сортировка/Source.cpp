#include <iostream>
#include <cstdarg>
#include <ctime>
#include <cstdlib>

void QuickSort(int* arr, int start, int end) {

	int l = start;
	int r = end;
	int key_num = arr[(r + l) / 2];
	do {

		while (arr[l] < key_num) {
			l++;
		}
		while (arr[r] > key_num) {
			r--;
		}
		if (l <= r) {
			int buf = arr[l];
			arr[l] = arr[r];
			arr[r] = buf;
			l++;
			r--;
		}
	} while (l <= r);

	if (r > start) {
		QuickSort(arr, start, r);
	}
	if (l < end) {
		QuickSort(arr, l, end);
	}
}

void main() {

	setlocale(LC_CTYPE, "rus");
	srand(time(0));

	int size;
	printf_s("Введите число:\n");
	scanf_s("%d", &size);

	int* arr = (int*)malloc(sizeof(int) * size);

	printf_s("Исходный массив:\n");
	for (int i = 0; i < size; i++) {

		arr[i] = 1 + rand() % 100;
		printf_s("%d ", arr[i]);
	}

	QuickSort(arr, 0, size - 1);

	printf_s("\nОтсортированный массив:\n");
	for (int i = 0; i < size; i++) {

		printf_s("%d ", arr[i]);
	}

	free(arr);
}