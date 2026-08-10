#include <iostream>
#include <climits>
#include <cmath>

double const SORT_NUM = (sqrt(5) - 1) / 2;

struct Node {

	int data;
	Node* next;

	Node(int num, Node* ptr = nullptr) : data(num), next(ptr) {};
};

int HeshFunc(int num, int size) {

	return int(size * std::fmod(num * SORT_NUM, 1));
}

void Add(int num, int size, Node** arr) {

	int i = HeshFunc(num, size);

	if (!arr[i]) {
		arr[i] = new Node(num);
	}	
	else {
		Node* ptr = arr[i];
		while (ptr->next) {
			ptr = ptr->next;
		}
		ptr->next = new Node(num);
	}
}

void Print(int size, Node** arr) {

	printf_s("\nХеш-таблица:\n");

	for (int i = 0; i < size; i++) {
		Node* ptr = arr[i];
		std::cout << std::endl;
		while (ptr) {
			printf_s("%d -> ", ptr->data);
			ptr = ptr->next;
		}
		printf_s("nullptr\n");
	}
}

void PopByKey(int size, int key, Node** arr) {

	int i = HeshFunc(key, size);

		if (!arr[i]) {
			return;
		}

		if (arr[i]->data == key) {
			Node* del_ptr = arr[i];
			arr[i] = arr[i]->next;
			delete del_ptr;
			return;
		}
		else {
			Node* ptr = arr[i];
			
			while(ptr->next) {

				if (ptr->next->data == key) {
					Node* del_ptr = ptr->next;
					ptr->next = del_ptr->next;
					delete del_ptr;
					return;
				}
				ptr = ptr->next;
			} 
		}
}

void Clear(Node**& arr, int size) {

	for (int i = 0; i < size; i++) {
		Node* ptr = arr[i];
		while (ptr) {
			Node* del_ptr = ptr;
			ptr = ptr->next;
			delete del_ptr;
		}
		arr[i] = nullptr;
	}
	delete[] arr;
	arr = nullptr;
}

void Resize(int& size, Node**& arr) {

	int buf = size;
	size = INT_MIN;

	while (size <= 0) {
		printf_s("Введите число:\n");
		scanf_s("%d", &size);
	}

	Node** buf_arr = new Node* [size]();
	for (int i = 0; i < buf; i++) {
		Node* ptr = arr[i];
		while (ptr) {
			Add(ptr->data, size, buf_arr);
			ptr = ptr -> next;
		}
	}
	Clear(arr, buf);
	arr = buf_arr;
}

float Fullness(int size, Node** arr) {
	
	int counter_engaged = 0;

	for (int i = 0; i < size; i++) {
		if (arr[i]) {
			counter_engaged++;
		}
	}
	return (float)counter_engaged / size;
}


void main() {

	setlocale(LC_CTYPE, "rus");

	int size = INT_MIN;

	while (size <= 0) {
		printf_s("Введите число:\n");
		scanf_s("%d", &size);
	}

	Node** arr = new Node * [size]();

	bool flag = true;

	do {

		Print(size, arr);

		printf_s("\n1. Добавить данные;\n");
		printf_s("2. Удалить данные;\n");
		printf_s("3. Изменить размер;\n");
		printf_s("4. Коэффициент заполненности;\n");
		printf_s("0. Выйти из программы;\n");

		int choice;
		printf_s("Выберите действие: ");
		if (scanf_s("%d", &choice) != 1) {
			printf_s("Ошибка ввода! Введите число.\n");
			while (getchar() != '\n'); 
			continue;
		}

		switch (choice) {

		case 1:
			choice = INT_MIN;
			while (choice < 0) {
				printf_s("Введите число:\n");
				scanf_s("%d", &choice);
			}
			Add(choice, size, arr);
			break;
		case 2: 
			choice = INT_MIN;
			while (choice < 0) {
				printf_s("Введите число:\n");
				scanf_s("%d", &choice);
			}
			PopByKey(size, choice, arr);
			break;
		case 3:
			choice = INT_MIN;
			while (choice < 0) {
				printf_s("Введите число:\n");
				scanf_s("%d", &choice);
			}
			Resize(size, arr);
			break;
		case 4:
			printf_s("Заполненность: %f%%\n", Fullness(size, arr) * 100);
			break;
		case 0:
			flag = false;
			break;
		default:
			printf_s("ОШИБКА ВВОДА!\n");
			break;
		}
	} while (flag);

	Clear(arr, size);
}