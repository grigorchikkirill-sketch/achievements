#include <iostream>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <algorithm>

int* CountingSort(int*& arr, int size) {

	int max_el = arr[0];

	for (int i = 0; i < size; i++) {
		if (max_el < arr[i]) {
			max_el = arr[i];
		}
	}

	int* counter_arr = new int[max_el + 1];
	std::fill_n(counter_arr, max_el + 1, 0);

	for (int i = 0; i < size; i++) {
		counter_arr[arr[i]]++;
	}
	delete[] arr;

	arr = new int[size];
	for (int i = 0, j = 0; i < max_el + 1; i++) {
		while (counter_arr[i] > 0) {
			arr[j++] = i;
			counter_arr[i]--;
		}
	}

	delete[] counter_arr;
	return arr;
}

void main() { 
	setlocale(LC_CTYPE, "rus");
	srand((time(NULL)));

	int size = INT_MIN;
	while (size <= 0) {
		printf_s("Введите кол-ство данных:\n");
		scanf_s("%d", &size);
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(LLONG_MAX, '\n');
		}
	}

	int* arr = new int[size];
	printf_s("Исходный массив:\n");
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 101;
		printf_s("%d ", arr[i]);
	}

	arr = CountingSort(arr, size);

	printf_s("\nОтсортированный массив:\n");
	for (int i = 0; i < size; i++) {
		printf_s("%d ", arr[i]);
	}

	delete[] arr;        
}
