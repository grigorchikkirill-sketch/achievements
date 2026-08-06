#include <iostream>
#include <climits>
struct Node {

	Node* next;
	Node* prev;
	int data;

	Node(int num, Node* ptr_n = nullptr, Node* ptr_p = nullptr) : data(num), next(ptr_n), prev(ptr_p) {};
};

struct Deque {

	Node* head;
	Node* tail;

	int size;
	int counter;

	Deque() {
		size = INT_MIN;
		while (size <= 0) {
			printf_s("Введите размер:\n");
			scanf_s("%d", &size);
			if (size <= 0) {
				printf_s("РАЗМЕР ВВЕДЕН НЕВЕРНО. ПОВТОРИТЕ ВВОД:\n");
			}
		}
		counter = 0;
		head = new Node(INT_MAX);
		tail = new Node(INT_MAX);
		head->next = tail;
		tail->prev = head;
	}

	~Deque() {

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
			PopHead();
		}
	}

	void Resize() {

		size = INT_MIN;
		while (size <= 0) {
			printf_s("Введите размер:\n");
			scanf_s("%d", &size);
			if (size <= 0) {
				printf_s("РАЗМЕР ВВЕДЕН НЕВЕРНО. ПОВТОРИТЕ ВВОД:\n");
			}
		}

		Correcting();
	}

	void AddTail() {

		if (counter >= size) {
			printf_s("ДЕК ЗАПОЛНЕН!\n");
			return;
		}
		int num;
		printf_s("Введите число:\n");
		scanf_s("%d", &num);

		tail->prev = new Node(num, tail, tail->prev);
		tail->prev->prev->next = tail->prev;
		counter++;
	}

	void AddHead() {

		if (counter >= size) {
			printf_s("ДЕК ЗАПОЛНЕН!\n");
			return;
		}
		int num;
		printf_s("Введите число:\n");
		scanf_s("%d", &num);

		head->next = new Node(num, head->next, head);
		head->next->next->prev = head->next;
		counter++;
	}

	void GetHead() {

		if (is_empty()) {
			printf_s("ДЕК ПУСТ!\n");
			return;
		}
		printf_s("Данные на вершине: %d\n", head->next->data);
	}

	void GetTail() {

		if (is_empty()) {
			printf_s("ДЕК ПУСТ!\n");
			return;
		}
		printf_s("Данные в конце дека: %d\n", tail->prev->data);
	}

	void PopHead() {

		if (is_empty()) {
			printf_s("ДЕК ПУСТ!\n");
			return;
		}
		
		Node* del_ptr = head->next;
		head->next = del_ptr->next;
		del_ptr->next->prev = head;
		delete del_ptr;
		counter--;
	}
	
	void PopTail() {

		if (is_empty()) {
			printf_s("ДЕК ПУСТ!\n");
			return;
		}

		Node* del_ptr = tail->prev;
		tail->prev = del_ptr->prev;
		del_ptr->prev->next = tail;
		delete del_ptr;
		counter--;
	}

	void Clear() {

		if (is_empty()) {
			printf_s("ДЕК ПУСТ!\n");
			return;
		}

		Node* ptr = head->next;
		while (ptr != tail) {

			Node* del_ptr = ptr;
			ptr = ptr->next;
			delete del_ptr;
		}
		tail->prev = head;
		head->next = tail;
		counter = 0;
	}

	void Structure() {

		if (is_empty()) {
			printf_s("ДЕК ПУСТ!\n");
			return;
		}

		Node* ptr = head->next;

		while (ptr != tail) {
			printf_s("%d|\n", ptr->data);
			ptr = ptr->next;
		}
	}
};

void main() {

	setlocale(LC_CTYPE, "rus");

	bool flag = true;

	Deque obj;

	do {

		printf_s("\n1. Добавить элемент в вершину;\n");
		printf_s("2. Добавить элемент в конец;\n");
		printf_s("3. Изъять вершину;\n");
		printf_s("4. Изъять конец;\n");
		printf_s("5. Удалить вершину;\n");
		printf_s("6. Удалить конец;\n");
		printf_s("7. Очистить;\n");
		printf_s("8. Изменить размер \n");
		printf_s("9. Структура;\n");
	/*(ОПИСАНИЕ: Если изменяя размер изначальное кол-во эл-ов было больше, чем новый размер, то произойдет выравнивание размеров путем удаления эл-ов вершины)*/
		printf_s("0. Выйти из программы;\n");

		int choice;
		printf_s("Введите число:\n");
		scanf_s("%d", &choice);
		switch (choice) {
		case 1: 
			obj.AddHead();
			break;
		case 2:
			obj.AddTail();
			break;
		case 3:
			obj.GetHead();
			break;
		case 4: 
			obj.GetTail();
			break;
		case 5:
			obj.PopHead();
			break;
		case 6:
			obj.PopTail();
			break;
		case 7:
			obj.Clear();
			break;
		case 8:
			obj.Resize();
			break;
		case 9:
			obj.Structure();
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