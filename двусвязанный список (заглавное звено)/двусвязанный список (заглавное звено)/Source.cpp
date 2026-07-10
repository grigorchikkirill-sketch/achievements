#include <iostream>
#include <cstdio>

struct Node {

	Node* prev;
	Node* next;
	int data;

	Node(int num, Node* ptr_p = nullptr, Node* ptr_n = nullptr) : data(num), next(ptr_n), prev(ptr_p) {};

};

struct HeadNode {

	Node* next;

	HeadNode(int trash = -1000, Node* ptr = nullptr) : next(new Node(trash, ptr)) {};

	~HeadNode() {

		Node* ptr = next;
		while (ptr) {

			Node* del_ptr = ptr;
			ptr = ptr->next;
			delete del_ptr;

		}

	}

	bool is_empty() {

		return !(next->next);

	}

	void AddNode_end() {

		int num;
		printf_s("Введите число: \n");
		scanf_s("%d", &num);
		Node* ptr = next;
		while (ptr->next) {
			ptr = ptr->next;
		}
		ptr->next = new Node(num, ptr);

	}
	
	void AddNode_start() {

		int num;
		printf_s("Введите число: \n");
		scanf_s("%d", &num);
		Node* ptr = new Node(num, next, next->next);
		next->next = ptr;
		if (next->next->next) {
			next->next->next->prev = next->next; 
		}
	}

	void Print() {

		if (is_empty()) {
			std::cout << "СПИСОК ПУСТ!\n";
			return;
		}

		Node* ptr = next->next;
		printf_s("nullptr <- HEADNODE <=>");
		while (ptr) {
			printf_s(" %d <=>", ptr->data);
			ptr = ptr->next;
		}
		printf_s(" nullptr\n");
	}

	void DelNode_start() {

		if (is_empty()) {
			std::cout << "СПИСОК ПУСТ!\n";
			return;
		}

		Node* ptr = next->next;

		next->next = ptr->next;
		if (ptr->next) {
			ptr->next->prev = next;
		}
		delete ptr;
	}

	void DelNode_end() {

		if (is_empty()) {
			std::cout << "СПИСОК ПУСТ!\n";
			return;
		}

		Node* ptr = next->next;

		while (ptr->next) {
			ptr = ptr->next;
		}
		ptr->prev->next = nullptr;
		delete ptr;

	}

	void DelByKey() {

		bool flag = false;

		if (is_empty()) {
			std::cout << "СПИСОК ПУСТ!\n";
			return;
		}

		int num;
		printf_s("Введите число:\n");
		scanf_s("%d", &num);

		Node* lptr = next;
		Node* ptr = next->next;
		Node* rptr = next->next->next;

		while (true) {

			if (ptr->data == num) {
				flag = true;
				break;
			}

			if (!rptr) {
				break;
			}

			lptr = lptr->next;
			ptr = ptr->next;
			rptr = rptr->next;

		}

		if (flag) {

			lptr->next = rptr;
			rptr->prev = lptr;
			delete ptr;

		}
		else {
			
			std::cout << "Элемент не был найден! \n";

		}

	}
};

void main() {
	setlocale(LC_CTYPE, "rus");

	bool flag = true;
	HeadNode Head;

	do {

		int choice;
		printf_s("1. Добавление узла в конец;\n");
		printf_s("2. Добавление узла в начало;\n");
		printf_s("3. Вывод списка;\n");
		printf_s("4. Удаление узла в начале;\n"); 
		printf_s("5. Удаление узла в конце;\n");
		printf_s("6. Удаление узла по ключу;\n");
		printf_s("0. Выйти из программы;\n");
		std::cout << "Введите число:\n";
		std::cin >> choice;
		switch (choice) {

		case 1: {

			Head.AddNode_end();
			break;
		}
		case 2: {

			Head.AddNode_start();
			break;
		}
		case 3: {

			Head.Print();
			break;
		}
		case 4: {

			Head.DelNode_start();
			break;
		}
		case 5: {

			Head.DelNode_end();
			break;
		}
		case 6: {

			Head.DelByKey();
			break;
		}
		case 0: {
			flag = false; 
			break;
		}
		default: {

			std::cout << "ОШИБКА ВВОДА!\n";
			break;
		}
		}
	} while (flag);

	std::cout << "УСПЕХ!";
}