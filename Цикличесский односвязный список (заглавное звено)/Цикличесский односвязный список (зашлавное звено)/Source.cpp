#include <iostream>
#include <stdio.h>

struct Node {

	int data;
	Node* next;

	Node(int num, Node* ptr = nullptr) : data(num), next(ptr) {};

};

struct HeadNode {

	Node* next;

	HeadNode(int trash = -1000, Node* ptr = nullptr) : next(new Node(trash, ptr)) {};

	bool is_empty() {

		return !(next->next);

	}

	~HeadNode() {

		if (is_empty()) {
			delete next;
		}
		else {
			Node* ptr = next->next;
			while (ptr != next) {
				Node* del_ptr = ptr;
				ptr = ptr->next;
				delete del_ptr;
			}
			delete next;
		}

	}

	void AddNode() {

		int num;
		printf_s("Введите число:\n");
		scanf_s("%d", &num);

		Node* ptr = new Node(num, next);

		if (!is_empty()) {
			Node* f_ptr = next;
			while (f_ptr->next != next) {
				f_ptr = f_ptr->next;
			}
			f_ptr->next = ptr;
		}
		if (is_empty()) {
			next->next = ptr;
		}
	}

	void Print() {

		if (is_empty()) {

			printf_s("СПИСОК ПУСТ! \n");

		}
		else {

			Node* ptr = next->next;
			printf_s("HEADNODE ->");
			while (ptr != next) {

				printf_s(" %d ->", ptr->data);
				ptr = ptr->next;

			}
			printf_s(" HEADNODE\n");

		}
	}

	void DelByKey() {

		bool flag = false;
		int num;
		printf_s("Введите число:\n");
		scanf_s("%d", &num);

		if (is_empty()) {

			printf_s("СПИСОК ПУСТ! \n");

		}
		else {

			if (next->next->next == next && next->next->data == num) {
				delete next->next;
				next->next = nullptr;
			}
			else {
				Node* lptr = next;
				Node* ptr = next->next;
				Node* rptr = next->next->next;
				while (true) {

					if (ptr->data == num) {
						flag = true;
						break;
					}
					if (rptr == next) {
						break;
					}
					lptr = lptr->next;
					ptr = ptr->next;
					rptr = rptr->next;

				}

				if (flag) {
					lptr->next = rptr;
					delete ptr;
				}
				else {
					printf_s("УЗЕЛ НЕ БЫЛ НАЙДЕН!\n");
				}
			}

		}
	}


};

void main() {
	setlocale(LC_CTYPE, "rus");

	HeadNode Head;
	bool flag = true;

	do {
		int choice;
		printf_s("1. Добавление узла;\n");
		printf_s("2. Вывод списка;\n");
		printf_s("3. Удаление узла;\n");
		printf_s("0. Выход из программы;\n");
		std::cout << "Введите число:\n";
		std::cin >> choice;

		switch (choice) {

		case 1: {
			Head.AddNode();
			break;
		}
		case 2: {
			Head.Print();
			break;
		}
		case 3: {
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