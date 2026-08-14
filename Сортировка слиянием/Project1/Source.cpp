#include <iostream>
#include <cstdlib>
#include <ctime>

int* Merge(int* arr_l, int* arr_r, int size_l, int size_r) {

	int i = 0;
	int j = 0;
	int head_i = 0;
	int* arr = new int[size_l + size_r];
	while (i < size_l && j < size_r) {

		if (arr_l[i] < arr_r[j]) {
			arr[head_i] = arr_l[i];
			i++;
			head_i++;
			continue;
		}
		else {
			arr[head_i] = arr_r[j];
			j++;
			head_i++;
			continue;
		}
	}

	while (i < size_l) {
		arr[head_i] = arr_l[i];
		i++;
		head_i++;
	}
	while (j < size_r) {
		arr[head_i] = arr_r[j];
		j++;
		head_i++;
	}

	return arr;
}

int* MergeSort(int* arr, int size) {

	if (size == 1) {
		int* single = new int[1];
		single[0] = arr[0];
		return single;
	}
	int size_l = size / 2;
	int size_r = size - size_l;

	int* arr_l = new int[size_l];
	int* arr_r = new int[size_r];

	for (int i = 0, j = 0; i < size; i++) {

		if (i < size_l) {
			arr_l[i] = arr[i];
		}
		else {
			arr_r[j] = arr[i];
			j++;
		}
	}

	int* sorted_l = MergeSort(arr_l, size_l);
	int* sorted_r = MergeSort(arr_r, size_r);
	
	int* result = Merge(sorted_l, sorted_r, size_l, size_r);

	delete[] arr_l;
	delete[] arr_r;
	delete[] sorted_l;
	delete[] sorted_r;

	return result;
}

void main() {

	setlocale(LC_CTYPE, "rus");
	srand(time(0));

	int size;
	bool is_correct = false;
	do {
		printf_s("Введите число:\n");
		if (scanf_s("%d", &size) != 1) {
			printf_s("ОШИБКА ВВОДА.Повторите ввод!\n");
			while (getchar() != '\n') {
				continue;
			}
		}
		else {
			is_correct = true;
		}
	} while (!is_correct);
	
	int* arr = new int[size];

	printf_s("Исходный массив:\n");
	for (int i = 0; i < size; i++) {
		arr[i] = 0 + rand() % (100 + 1 - 0);
		printf_s("%d ", arr[i]);
	}

    int* sorted_arr = MergeSort(arr, size);
	printf_s("\nОтсортированный массив:\n");
	for (int i = 0; i < size; i++) {
		printf_s("%d ", sorted_arr[i]);
	}

	delete[] sorted_arr;
	delete[] arr;
}