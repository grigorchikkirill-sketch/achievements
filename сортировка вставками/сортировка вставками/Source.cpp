#include <iostream>
#include <cstdarg>
#include <ctime>
#include <cstdlib>

void InsertionSort(int* arr, int size) {

	//	int left = 1;
	//
	//	while (left < size) {
	//		int left_i = left - 1;
	//		int right_i = left;
	//
	//		while (arr[left_i] > arr[right_i] && left_i > -1) {
	//
	//			int buf = arr[left_i];
	//			arr[left_i] = arr[right_i];
	//			arr[right_i] = buf;
	//			left_i--;
	//			right_i--;
	//		}
	//		left++;
	//	}
	//}                                                 

	for (int i = 1; i < size; i++) {
		for (int j = i - 1; j > -1 && arr[j] > arr[j + 1]; j--) {
			int buf = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = buf;
		}
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

	InsertionSort(arr, size);

	printf_s("\nОтсортированный массив:\n");
	for (int i = 0; i < size; i++) {

		printf_s("%d ", arr[i]);
	}

	free(arr);
}