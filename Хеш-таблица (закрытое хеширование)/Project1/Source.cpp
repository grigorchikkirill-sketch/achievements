#include <iostream>
#include <climits>

float const GOLD_NUM = (sqrt(5) - 1) / 2;

struct Node {

	int data;
	bool is_deleted;

	Node(int num) : data(num), is_deleted(false) {};
};

int HeshFunc(int size, int num) {

	return int(size * fmodf(GOLD_NUM * num, 1));
}

void Add(Node** arr, int num, int size) {

	int i = HeshFunc(size, num);
	int buf_i = i;
	bool is_added = false;
	do {
	
		if (!arr[i]) {
			arr[i] = new Node(num);
			is_added = true;
			break;
		}
		if (arr[i]->is_deleted) {
			arr[i]->data = num;
			is_added = true;
			arr[i]->is_deleted = false;
			break;
		}
		
		i = (i + 1) % size;

	} while (i != buf_i);

	if (!is_added) {
		printf_s("ВСТАВКА НЕУСПЕШНА!\n");
	}
}

void Print(Node** arr,int size) {

	printf_s("\nХеш-таблица:\n");

	for (int i = 0; i < size; i++) {

		if (!arr[i]) {
			printf_s("nullptr\n");
			continue;
		}
		if (arr[i] && arr[i]->is_deleted) {
			printf_s("Deleted\n");
			continue;
		}

		printf_s("%d\n", arr[i]->data);
	} 
 }

void Pop(Node** arr, int size, int num) {

	int i = HeshFunc(size, num);
	int buf_i = i;
	bool is_deleted = false;
	bool is_already_del = false;

	do {

		if (!arr[i]) {
			break;
		}
		if (arr[i]->data == num && arr[i]->is_deleted) {
			is_already_del = true;
			break;
		}
		if (arr[i]->data == num && !arr[i]->is_deleted) {
			arr[i]->is_deleted = true;
			is_deleted = true;
			break;
		}

		i = (i + 1) % size;
	} while (i != buf_i);

	if (is_already_del) {
		printf_s("УЖЕ БЫЛО УДАЛЕНО!\n");
		return;
	}
	if (!is_deleted) {
		printf_s("ДАННЫЙ НЕ БЫЛИ НАЙДЕНЫ!\n");
	}
}

int Engaged(Node** arr, int size) {

	float counter_eng = 0;

	for (int i = 0; i < size; i++) {
		if (arr[i]) {
			counter_eng++;
		}
	}
	return int(counter_eng / size * 100);
}

int Enter() {

	bool is_correct = false;
	int choice;

	do {

		printf_s("Введите число:\n");
		scanf_s("%d", &choice);

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(LLONG_MAX, '\n');
			printf_s("НЕКОРРЕКТНЫЙ ВВОД. Повторите ввод!\n");
		}
		else {
			is_correct = true;
		}
	} while (!is_correct);

	return choice;
}

void Clear(Node**& arr, int size) {

	for (int i = 0; i < size; i++) {
		if (arr[i]) {
			delete arr[i];
		}
	}
	delete[] arr;
    arr = nullptr;
}

void Resize(Node**& arr, int& size) {

	int buf_size = size;

	size = Enter();

	Node** buf_arr = new Node * [size]();

	for (int i = 0; i < buf_size; i++) {
		if (arr[i] && !arr[i]->is_deleted) {
			Add(buf_arr, arr[i]->data, size);
		}
	}

	Clear(arr, buf_size);
	arr = buf_arr;
}

void main() {

	setlocale(LC_CTYPE, "rus");

	int size = INT_MIN;
	while (size <= 0) {

		printf_s("Введите размер:\n");
		scanf_s("%d", &size);
		if (size <= 0) {
			printf_s("НЕКОРРЕКТНЫЙ ВВОД. Повторите ввод!\n");
		}
	}
	Node** arr = new Node*[size]();
	
	
	bool flag = true;
	do {

		Print(arr, size);

		printf_s("\n1. Добавить данные;\n");
		printf_s("2. Удалить данные;\n");
		printf_s("3. Заполненность;\n");
		printf_s("4. Изменить размер;\n");
		printf_s("0. Выйти из программы;\n");

		int choice = Enter();

		switch (choice) {

		case 1:
			choice = Enter();
			Add(arr, choice, size);
			break;
		case 2:
			choice = Enter();
			Pop(arr, size, choice);
			break;
		case 3:
			printf_s("%d%%\n", Engaged(arr, size));
			break;
		case 4:
			Resize(arr, size);
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