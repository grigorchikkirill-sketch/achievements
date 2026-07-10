#include <iostream>
#include <stdio.h>

struct Node {
	
	int data;
	Node* next;
	
	Node(int num, Node* ptr = nullptr) : data(num), next(ptr) {};

	
};

struct HeadNode {
	
	Node* next;

	HeadNode(int trash = -100000) : next(new Node(trash, nullptr)) {};

	~HeadNode() {

		Node* ptr = next;
		while (ptr){

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
		printf_s("Введите число \n");
		scanf_s("%d", &num);

		Node* ptr = new Node(num, nullptr);
		
		Node* add_ptr = next;
		while (add_ptr->next) {
			add_ptr = add_ptr->next;
		}
		add_ptr->next = ptr;
		printf_s("УСПЕШНО ДОБАВЛЕНО!\n");
	}

	void PrintList() {

		if (is_empty()) {
			printf_s("СПИСОК ПУСТ!\n");
			return;
		}
		Node* ptr = next->next;
		printf_s("HeadNode ->");
		while (ptr) {
			printf_s(" %d ->", ptr->data);
			ptr = ptr->next;
		}
		printf_s(" nullptr \n УСПЕШНЫЙ ВЫВОД!\n");
	}
	
	void delByKey() {

		if (is_empty()) {
			printf_s("СПИСОК ПУСТ!\n");
			return;
		}

		bool flag = false;
		int num;
		printf_s("Введите число \n");
		scanf_s("%d", &num);
		Node* lptr = next;
		Node* ptr = next->next;
		Node* rptr = next->next->next;
		while (true) {
			if (ptr->data == num) {
				flag = true;
				break;
			}
			if (rptr) {
				lptr = lptr->next;
				ptr = ptr->next;
				rptr = rptr->next;
			}
			else {
				break;
			}
		}
		if (flag) {
			lptr->next = rptr;
			delete ptr;
		}
	}
};

void main() {
	
	setlocale(LC_CTYPE, "rus");

	HeadNode head;
	bool flag = true;

	do {
		int decision;
		printf_s("1. Добавить узел;\n");
		printf_s("2. Вывод списка;\n");
		printf_s("3. Удалить узел; \n");
		printf_s("0. Выйти из программы; \n"); 
		scanf_s("%d", &decision);
		switch (decision) {
		case 1: {
			head.AddNode_end();
			break;
		}
		case 2: {
			head.PrintList();
			break;
		}
		case 3: {
			head.delByKey();
			break;
		}
		case 0: {
			std::cout << "ВЫХОД\n";
			flag = false;
			break;
		}
		default: {
			std::cout << "ОШИБКА ВВОДА!\n";
			break;
		}
		}
	} while (flag);
	std::cout << "УСПЕХ";
}