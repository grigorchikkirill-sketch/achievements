#include <iostream>
#include <cstdarg>
#include <ctime>
#include <cstdlib>

void ChoiceSort(int* arr, int size) {

	if (size <= 1) {
		return;
	}

	int left = 0;

	while (left + 1 < size) {

		int min_num = arr[left];
		int min_ind = left;

		for (int i = left; i < size; i++) {
			if (min_num > arr[i]) {
				min_num = arr[i];
				min_ind = i;
			}
		}

		int buf = arr[left];
		arr[left] = min_num;
		arr[min_ind] = buf;
		
		left++;
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

	ChoiceSort(arr, size);

	printf_s("\nОтсортированный массив:\n");
	for (int i = 0; i < size; i++) {

		printf_s("%d ", arr[i]);
	}

	free(arr);
}