#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>

void BubbleSort(int* arr, int left, int right){

	int middle = arr[(right - left) / 2 + left];
	int l = left;
	int r = right;

	do {

		while (arr[l] < middle) {
			l++;
		}
		while (arr[r] > middle) {
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

	if (r > left) {
		BubbleSort(arr, left, r);
	}
	if (l < right) {
		BubbleSort(arr, l, right);
	}
}

void main() {

	setlocale(LC_CTYPE, "rus");
	srand(time(0));

	
	int count = INT_MIN;
	while (count < 0) {
		printf_s("Введите колличество товаров:\n");
		scanf_s("%d", &count);
	}
	int* arr = (int*)calloc(count, sizeof(int));

	for (int* ptr = arr; ptr != arr + count; ptr++) {
		*ptr = 1 + rand() % (0 - 100 + 1);
	}

	BubbleSort(arr, 0, count - 1);
	int result = 0;
	for (int i = count - 1, j = 0; i >= j; i--, j++) {
		result += arr[i];
		if (i != j) {
			printf_s(" %d - (free) %d |", arr[i], arr[j]);
		}
		else {
			printf_s("%d\n", arr[i]);
		}
	}
	printf_s("Итоговая стоимость: %d", result);


	free(arr);
}