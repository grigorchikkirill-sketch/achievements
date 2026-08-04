#include <iostream>
#include <cstdarg>
#include <climits>

int TRASH = INT_MAX;

struct Node {

	int data;
	Node* next;
	Node* prev;

	Node(int num, Node* ptr_n = nullptr, Node* ptr_p = nullptr) : data(num), next(ptr_n), prev(ptr_p) {};
};

struct HeadNodes {

	Node* start;
	Node* end;

	HeadNodes(int num = TRASH) {

		start = new Node(num);
		end = new Node(num);
		start->next = end;
		end->prev = start;
	}

	~HeadNodes() {

		Node* ptr = start;
		while (ptr) {
			Node* del_ptr = ptr;
			ptr = ptr->next;
			delete del_ptr;
		}
	}

	bool is_empty() {

		return start->next == end;
	}

	void AddNodeStart() {

		int num;
		printf_s("Введите число:\n");
		scanf_s("%d", &num);

		start->next = new Node(num, start->next, start);
		start->next->next->prev = start->next;
	}

	void AddNodeEnd() {

		int num;
		printf_s("Введите число:\n");
		scanf_s("%d", &num);

		end->prev = new Node(num, end, end->prev);
		end->prev->prev->next = end->prev;
	}

	void PrintList() {

		if (is_empty()) {
			printf_s("СПИСОК ПУСТ!\n");
			return;
		}

		Node* ptr = start->next;
		printf_s("nullptr <=> StartNode <=> ");
		while (ptr != end) {

			printf_s("%d <=> ", ptr->data);
			ptr = ptr->next;
		}
		printf_s("EndNode <=> nullptr\n");
	}

	void PopNodeStart() {

		if (is_empty()) {
			printf_s("СПИСОК ПУСТ!\n");
			return;
		}

		Node* ptr = start->next;
		start->next = ptr->next;
		ptr->next->prev = start;
		delete ptr;
	}

	void PopNodeEnd() {

		if (is_empty()) {
			printf_s("СПИСОК ПУСТ!\n");
			return;
		}

		Node* ptr = end->prev;

		end->prev = ptr->prev;
		ptr->prev->next = end;
		delete ptr;
	}

	void PopNodeByKey() {

		if (is_empty()) {
			printf_s("СПИСОК ПУСТ!\n");
			return;
		}

		int key;
		printf_s("Введите число:\n");
		scanf_s("%d", &key);

		Node* ptr = start->next;
		while (ptr != end) {

			if (ptr->data == key) {

				ptr->prev->next = ptr->next;
				ptr->next->prev = ptr->prev;
				delete ptr;
				return;
			}
			ptr = ptr->next;
		}

		printf_s("УЗЕЛ НЕ НАЙДЕН!\n");
	}

	void Clear() {

		if (is_empty()) {
			printf_s("СПИСОК ПУСТ!\n");
			return;
		}

		Node* ptr = start->next;
		while (ptr != end) {
			Node* del_ptr = ptr;
			ptr = ptr->next;
			delete del_ptr;
		}

		end->prev = start;
		start->next = end;
	}
}; 

void main() {

	setlocale(LC_CTYPE, "rus");

	bool flag = true;
	HeadNodes obj;

	do {
		int num;

		printf_s("\n1. Добавить узел в начало;\n");
		printf_s("2. Добавить узел в конец;\n");
		printf_s("3. Вывести список;\n");
		printf_s("4. Удалить первый узел;\n");
		printf_s("5. Удалить последний узел;\n");
		printf_s("6. Удалить по ключу;\n");
		printf_s("7. Очистить список;\n");
		printf_s("0. Выйти из программы;\n");

		printf_s("Введите число:\n");
		scanf_s("%d", &num);

		switch (num) {
		default:
			printf_s("НЕВЕРНЫЙ ВВОД!\n");
			break;
		case 1: 
			obj.AddNodeStart();
			break;
		case 2:
			obj.AddNodeEnd();
			break;
		case 3:
			obj.PrintList();
			break;
		case 4: obj.PopNodeStart();
			break;
		case 5:
			obj.PopNodeEnd();
			break;
		case 6:
			obj.PopNodeByKey();
			break;
		case 7:
			obj.Clear();
			break;
		case 0:
			flag = false;
			break;
		}
	} while (flag);

	printf_s("УСПЕХ!");
}
