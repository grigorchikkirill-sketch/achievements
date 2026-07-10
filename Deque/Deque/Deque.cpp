#include <iostream>
#include <cstdarg>

struct Node {

	Node* next;
	int data;

	Node(int num, Node* ptr = nullptr) : next(ptr), data(num) {};
};

struct Deque {

	Node* head;
	Node* tail;

	Deque() : head(nullptr), tail(nullptr) {};
	~Deque() {

		while (head) {

			Node* ptr = head;
			head = head->next;
			delete ptr;
		}
	}

	bool is_empty() {

		return !head;
	}

	void Push_front() {

		int num;
		printf_s("Введите число:\n");
		scanf_s("%d", &num);

		if (is_empty()) {

			head = new Node(num);
			tail = head;
		}
		else {

			Node* ptr = new Node(num, head);
			head = ptr;	
		}
	}

	void Push_back() {

		int num;
		printf_s("Введите число:\n");
		scanf_s("%d", &num);

		if (is_empty()) {

			head = new Node(num);
			tail = head;
		}
		else {

			Node* ptr = new Node(num);
			tail->next = ptr;
			tail = ptr;
		}
	}

	void Pop_front() {

		if (is_empty()) {

			printf_s("ДЕК ПУСТ!\n");
			return;
		}
		
		if (head == tail) {

			delete head;
			head = nullptr;
			tail = nullptr;
		}
		else {

			Node* del_ptr = head;
			head = head->next;
			delete del_ptr;
		}
	}

	void Pop_back() {

		if (is_empty()) {

			printf_s("ДЕК ПУСТ!\n");
			return;
		}

		if (head == tail) {

			delete head;
			head = nullptr;
			tail = nullptr;
		}
		else {

			Node* ptr = head;
			while (ptr->next->next) {
				ptr = ptr->next;
			}
			delete tail;
			tail = ptr;
			tail->next = nullptr;
		}
	}

	void Front() {


		if (is_empty()) {

			printf_s("ДЕК ПУСТ!\n");
			return;
		}
		else {
			printf_s("%d\n", head->data);
		}
	}

	void Back() {


		if (is_empty()) {

			printf_s("ДЕК ПУСТ!\n");
			return;
		}
		else {
			printf_s("%d\n", tail->data);
		}
	}

	void Clear() {

		while (!is_empty()) {
			if (head == tail) {

				delete head;
				head = nullptr;
				tail = nullptr;
			}
			else {

				Node* ptr = head;
				while (ptr->next->next) {
					ptr = ptr->next;
				}
				delete tail;
				tail = ptr;
				tail->next = nullptr;
			}
		}
	}
};

void main() {
	setlocale(LC_CTYPE, "rus");

	Deque obj;
	bool flag = true;
	do {
		int choice;
		printf_s("\n1. Добавить элемент в начало;\n");
		printf_s("2. Добавить элемен в конец;\n");
		printf_s("3. Вывести элемент в начале;\n");
		printf_s("4. Вывести элемен в конце;\n");
		printf_s("5. Удалить элемента в начале;\n");
		printf_s("6. Удалить элемента в конце;\n");
		printf_s("7. Очистить дек;\n");
		printf_s("0. Выйти из программы;\n");
		printf_s("Введите число: ");

		if (scanf_s("%d", &choice) != 1) {
			std::cout << "ОШИБКА ВВОДА!\n";
			break;
		}

		switch (choice) {
		case 1: obj.Push_front(); break;
		case 2: obj.Push_back(); break;
		case 3: obj.Front(); break;
		case 4: obj.Back(); break;
		case 5: obj.Pop_front(); break;
		case 6: obj.Pop_back(); break;
		case 7: obj.Clear(); break;
		case 0: flag = false; break;
		default: std::cout << "ОШИБКА ВВОДА!\n"; break;
		}
	} while (flag);

	std::cout << "УСПЕХ!\n";
}
