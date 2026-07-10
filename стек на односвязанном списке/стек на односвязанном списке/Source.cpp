#include <iostream>
#include <cstdarg>

struct Node {

	Node* prev;
	int data;

	Node(int num, Node* ptr = nullptr) : data(num), prev(ptr) {};
};

struct HeadNode {

	Node* top;
	int counter;

	HeadNode() : counter(0), top(nullptr) {};


	~HeadNode() {

		Node* ptr = top;
		while (ptr) {

			Node* del_ptr = ptr;
			ptr = ptr->prev;
			delete del_ptr;
		}

	}


	bool is_empty() {

		return !(top);
	}

	void Push() {

		int num;
		printf_s("Введите число:\n");
		scanf_s("%d", &num);

		Node* ptr = new Node(num, top);
		top = ptr;
		counter++;
	}

	void Top() {

		if (is_empty()) {

			std::cout << "СТЕК ПУСТ!\n";
			return;
		}
		else {

			printf_s("Элемент на вершине стека: %d\n", top->data);
		}

	}

	void Pop() {

		if (is_empty()) {

			std::cout << "СТЕК ПУСТ!\n";
			return;
		}
		else {

			Node* ptr = top->prev;
			delete top;
			top = ptr;
			counter--;
		}

	}

	void Clear() {

		Node* ptr = top;
		while (ptr) {

			Node* del_ptr = ptr;
			ptr = ptr->prev;
			delete del_ptr;
		}
		counter = 0;
		top = nullptr;
	}

	void Count() {

		printf_s("Кол-во элементов в стеке: %d\n", counter);
	}
};

void main() {

	setlocale(LC_CTYPE, "rus");

	bool flag = true;
	HeadNode head;

	do {

		int choice;
		printf_s("1. Добавить элемент;\n");
		printf_s("2. Изъять элемент;\n");
		printf_s("3. Удалить элемент;\n");
		printf_s("4. Очистить;\n");
		printf_s("5. Кол-во элементов;\n");
		printf_s("0. Выйти из программы;\n");
		scanf_s("%d", &choice);

		switch (choice) {

		case 1: {

			head.Push();
			break;
		}
		case 2: {

			head.Top();
			break;
		}
		case 3: {

			head.Pop();
			break;
		}
		case 4: {

			head.Clear();
			break;
		}
		case 5: {

			head.Count();
			break;
		}
		case 0: {

			flag = false;
			break;
		}
		}
	} while (flag);

	std::cout << "УСПЕХ!";

}