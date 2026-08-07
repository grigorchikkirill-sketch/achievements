#include <iostream>

struct Node {

	Node* left;
	Node* right;

	int data;

	Node(int num, Node* l = nullptr, Node* r = nullptr) : data(num), left(l), right(r) {};
};

struct Tree {

	Node* root;

	Tree() : root(nullptr) {};

	~Tree() {
		Clear(root);
	}

	bool is_empty() {

		return root;
	}

	void Clear(Node*& ptr) {

		if (!ptr) {
			return;
		}

		if (ptr->left) {
			Clear(ptr->left);
		}
		if (ptr->right) {
			Clear(ptr->right);
		}
		delete ptr;
		ptr = nullptr;
		return;
	}


	void Add(int num, Node*& ptr) {

		if (!ptr) {

			ptr = new Node(num);
			return;
		}

		if (ptr->data > num) {
			Add(num, ptr->left);
			return;
		}

		if (ptr->data < num) {
			Add(num, ptr->right);
			return;
		}

		if (ptr->data == num) {
			printf_s("ЗНАЧЕНИЕ УЖЕ СУЩЕСТВОВАЛО!\n");
			return;
		}
	}

	Node* FindElForPopping(Node* ptr) {

		if (!ptr->right) {
			return ptr;
		}
		else {
			return FindElForPopping(ptr->right);
		}
	}

	void PopByKey(int num, Node*& ptr) {

		if (!root) {
			
			printf_s("ДЕРЕВО ПУСТОЕ!\n");
			return;
		}

		if (!ptr) {
			return;
		}

		if (ptr->data > num) {
			PopByKey(num, ptr->left);
			return;
		}
		if (ptr->data < num) {
			PopByKey(num, ptr->right);
			return;
		}

		if (ptr->data == num && !ptr->left && !ptr->right) {
			delete ptr;
			ptr = nullptr;
			return;
		}

		if (ptr->data == num && ptr->left && !ptr->right) {
			Node* buf = ptr;
			ptr = ptr->left;
			delete buf;
			return;
		}
		if (ptr->data == num && 
			ptr->right && !ptr->left) {
			Node* buf = ptr;
			ptr = ptr->right;
			delete buf;
			return;
		}
		if (ptr->data == num && ptr->right && ptr->left) {

			Node* buf = FindElForPopping(ptr->left);
			int buf_num = buf->data;
			PopByKey(buf_num, ptr->left);
			ptr->data = buf_num;
			return;
		}
	}

	void Print(Node* ptr, int level = 0) {

		if (!root) {

			printf_s("ДЕРЕВО ПУСТОЕ!\n");
			return;
		}

		if (!ptr) {
			return;
		}

		if (ptr->left) {
			Print(ptr->left, level + 1);
		}

		for (int i = 0; i < level; i++) {
			printf_s("|");
		}
		printf_s("%d\n", ptr->data);

		if (ptr->right) {
			Print(ptr->right, level + 1);
		}
	}
};

void main() {

	setlocale(LC_CTYPE, "rus");

	bool flag = true;

	Tree obj;
	
	do {

		printf_s("\n1. Добавить узел;\n");
		printf_s("2. Структура;\n");
		printf_s("3. Удалить узел по ключу;\n");
		printf_s("4. Очистить;\n");
		printf_s("0. Выйти из программы;\n");

		int choice;
		scanf_s("%d", &choice);
		switch (choice) {
		case 1:
			int num;
			printf_s("Введите число:\n");
			scanf_s("%d", &num);
			obj.Add(num, obj.root);
			break;
		case 2:
			obj.Print(obj.root);
			break;
		case 3:
			int buf_num;
			printf_s("Введите число:\n");
			scanf_s("%d", &buf_num);
			obj.PopByKey(buf_num, obj.root);
			break;
		case 4:
			obj.Clear(obj.root);
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