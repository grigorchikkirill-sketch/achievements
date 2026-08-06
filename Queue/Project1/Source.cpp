#include <iostream>
#include <climits>

struct Node {

	Node* next;
	Node* prev;
	int data;

	Node(int num, Node* ptr_n = nullptr, Node* ptr_p = nullptr) : data(num), next(ptr_n), prev(ptr_p) {};
};

struct Queue {

	Node* head;
	Node* tail;

	int size;
	int counter;

	Queue() {

		size = INT_MIN;
		while (size <= 0) {
			printf_s("Введите размер:\n");
			scanf_s("%d", &size);
			if (size <= 0) {
				printf_s("РАЗМЕР ВВЕДН НЕВЕРНО. ПОВТОРИТЕ ВВОД!\n");
			}
		}
		head = new Node(INT_MAX);
		tail = new Node(INT_MAX);
		head->next = tail;
		tail->prev = head;
		counter = 0;
	}

	~Queue() {

		Node* ptr = head;
		while (ptr) {
			Node* del_ptr = ptr;
			ptr = ptr->next;
			delete del_ptr;
		}
	}

	bool is_empty() {
		return head->next == tail;
	}

	void Correcting() {

		while (counter > size) {
			Pop();
		}
	}

	void Resize() {

		size = INT_MIN;
		while (size <= 0) {
			printf_s("Введите размер:\n");
			scanf_s("%d", &size);
			if (size <= 0) {
				printf_s("РАЗМЕР ВВЕДН НЕВЕРНО. ПОВТОРИТЕ ВВОД!\n");
			}
		}
		if (counter > size) {
			Correcting();
		}
	}

	void Add() {

		if (counter >= size) {
			printf_s("ОЧЕРЕДЬ ЗАПОЛНЕНА!\n");
			return;
		}

		int num;
		printf_s("Введите число:\n");
		scanf_s("%d", &num);
		tail->prev = new Node(num, tail, tail->prev);
		tail->prev->prev->next = tail->prev;
		counter++;
	}

	void Pop() {

		if (is_empty()) {
			printf_s("ОЧЕРЕДЬ ПУСТА!\n");
			return;
		}

		Node* del_ptr = head->next;
		head->next = del_ptr->next;
		del_ptr->next->prev = head;
		delete del_ptr;
		counter--;
	}

	void Clear() {

		if (is_empty()) {
			printf_s("ОЧЕРЕДЬ ПУСТА!\n");
			return;
		}
		Node* ptr = head->next;
		while (ptr != tail) {
			Node* del_ptr = ptr;
			ptr = ptr->next;
			delete del_ptr;
		}
		head->next = tail;
		tail->prev = head;
		counter = 0;
	}

	void Structure() {

		if (is_empty()) {
			printf_s("ОЧЕРЕДЬ ПУСТА!\n");
			return;
		}
		Node* ptr = head->next;
		while (ptr != tail) {
			printf_s("%d|\n", ptr->data);
			ptr = ptr->next;
		}
	}

	void Top() {

		if (is_empty()) {
			printf_s("ОЧЕРЕДЬ ПУСТА!\n");
			return;
		}
		printf_s("Данные в вершине: %d\n", head->next->data);
	}
};

void main() {

	setlocale(LC_CTYPE, "rus");

	bool flag = true;

	Queue obj;

	do {

		printf_s("\n1. Добавить элемент;\n");
		printf_s("2. Удалить элемент;\n");
		printf_s("3. Очистить;\n");
		printf_s("4. Структура;\n");
		printf_s("5. Изъять элемент на вершине;\n");
		printf_s("6. Изменить размер;\n");
		printf_s("0. Выйти из программы;\n");

		int choice;
		printf_s("Введите число:\n");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1: 
			obj.Add();
			break;
		case 2:
			obj.Pop();
			break;
		case 3:
			obj.Clear();
			break;
		case 4:
			obj.Structure();
			break;
		case 5:
			obj.Top();
			break;
		case 6:
			obj.Resize();
			break;
		case 0:
			flag = false;
			break;
		default:
			printf_s("ОШИБКА ВВОДА!\n");
			break;
		}

	} while (flag);

	printf_s("УСПЕХ!");
}
