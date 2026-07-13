#include <cstdarg>
#include <iostream>

struct Node {

	int data;
	Node* right;
	Node* left;

	Node(int num, Node* l_ptr = nullptr, Node* r_ptr = nullptr) : data(num), left(l_ptr), right(r_ptr) {};
};

struct BinaryTree {

	Node* root;

	BinaryTree() {

		int num;
		printf_s("Введите число:\n");
		scanf_s("%d", &num);

		root = new Node(num);
	}

	void Clear(Node*& ptr) {

		if (!ptr) {
			return;
		}

			Clear(ptr->left);
			Clear(ptr->right);
		
			delete ptr;
			ptr = nullptr;
	}

	~BinaryTree() {

		Clear(root);
		root = nullptr;
	}

	void AddEl(Node*& ptr, int num) {

		if (!root) {
			root = new Node(num);
			return;
		}

		if (!ptr) {
			ptr = new Node(num);
			return;
		}

		if (ptr->data == num) {

			printf_s("ЧИСЛО НАХОДИЛОСЬ В ДЕРЕВЕ!\n");
			return;
		}

		if (ptr->data > num) {

			AddEl(ptr->left, num);
			return;
		}

		if (ptr->data < num) {

			AddEl(ptr->right, num);
			return;
		}
	}

	void Print(Node* ptr, int level) {

		if (!ptr) {
			return;
		}

		Print(ptr->left, level + 1);

		for (int i = 0; i < level; i++) {
			printf_s("  ");
		}

		printf_s("{%d}-%d", level, ptr->data);

		Print(ptr->right, level + 1);
	}

	Node* FindMaxEl(Node* ptr) {

		if (ptr->right) {
			return FindMaxEl(ptr->right);
		}
		else {
			return ptr;
		}
	}

	void PopByKey(Node*& ptr, int key) {

		if (!ptr) {
			return;
		}

		

		if (ptr->data > key) {
			
			PopByKey(ptr->left, key);
			return;
		}

		if (ptr->data < key) {

			PopByKey(ptr->right, key);
			return;
		}
		
		if (ptr->data == key && !ptr->left && !ptr->right) {

			delete ptr;
			ptr = nullptr;
			return;
		}

		if (ptr->data == key && !ptr->left && ptr->right) {

			Node* temp = ptr;
			ptr = ptr->right;
			delete temp;
			return;
		}

		if (ptr->data == key && !ptr->right && ptr->left) {

			Node* temp = ptr;
			ptr = ptr->left;
			delete temp;
			return;
		}

		if (ptr->data == key && ptr->right && ptr->left) {

			Node* temp = FindMaxEl(ptr->left);
			int num = temp->data;
			PopByKey(ptr->left, num);
			ptr->data = num;
			return;
		}
	}
};

void main() {
	setlocale(LC_CTYPE, "rus");
	BinaryTree obj;
	bool flag = true;

	do {
		int choice;

		printf_s("\n1. Добавить узел;\n");
		printf_s("2. Вывести дерево на экран;\n");
		printf_s("3. Удалить узел по ключу;\n");
		printf_s("4. Очистить дерево;\n");
		printf_s("0. Выйти из программы;\n");
		
		printf_s("Введите число:\n");
		scanf_s("%d", &choice);

		switch (choice) {

		case 1: {

			int num;
			printf_s("Введите число:\n");
			scanf_s("%d", &num);
			obj.AddEl(obj.root, num);
			break;
		}
		case 2: {
			obj.Print(obj.root, 0);
			break;
		}
		case 3: {

			int key;
			printf_s("Введите число:\n");
			scanf_s("%d", &key);
			obj.PopByKey(obj.root, key);
			break;
		}
		case 4: {

			obj.Clear(obj.root);
			printf_s("\nДеверо очищено!\n");
			break;
		}
		case 0: {

			flag = false;
			break;
		}
		}
	} while (flag);

	printf_s("УСПЕХ!");
}