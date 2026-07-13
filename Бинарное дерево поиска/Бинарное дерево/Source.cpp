#include <iostream>
#include <cstdarg>

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

		if (ptr) {
			Clear(ptr->left);
			Clear(ptr->right);
		}
		else {
			return;
		}

		delete ptr;
	}

	~BinaryTree() {

		Clear(root);
		root = nullptr;
	}

	void AddEl(Node*& ptr, int num){

		if (!root) {
			root = new Node(num);
			return;
		}
		
		if (!ptr) {
			ptr = new Node(num);
			return;
		}

		if (num == ptr->data) {

			std::cout << "ЭЛЕМЕНТ УЖЕ БЫЛ В ДЕРЕВЕ!" << std::endl;
			return;
		}

		if (ptr->data > num) {
			AddEl(ptr->left, num);
		}
		if (ptr->data < num) {
			AddEl(ptr->right, num);
		}
	}

	void Print(Node* ptr, int level = 0) {

		if (ptr) {
			Print(ptr->left, level + 1);
		}
		else {
			return;
		}

		for (int i = 0; i < level; i++) {
			printf_s("  ");
		}
		printf_s("{%d}-%d", level, ptr->data);

		Print(ptr->right, level + 1);
	
	}

	Node* FindPredecessor(Node* ptr) {

		if (ptr->right) {
			return FindPredecessor(ptr->right);
		}
		else {
			return ptr;
		}
	}

	void PopByKey(Node*& ptr, int key) {

		if (!root) {
			
			printf_s("ДЕРЕВО ПУСТОЕ!\n");
			return;
		}

		if (root->left == nullptr && root->right == nullptr && key == root->data) {
			delete root;
			root = nullptr;
			return;
		}

		if (ptr == nullptr) {
			return;
		}

		if(ptr->data < key){
			PopByKey(ptr->right, key);
			return;
		}

		if (ptr->data > key) {
			PopByKey(ptr->left, key);
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

		if (ptr->data == key && !ptr->right && !ptr->left) {

			Node* temp = ptr;
			ptr = nullptr;
			delete temp;
			return;
		}

		if (ptr->data == key && ptr->right && ptr->left) {

			Node* temp = FindPredecessor(ptr->left);
			int num = temp->data;
			PopByKey(ptr->left, num);
			ptr->data = num;
			return;
		}
	}
};

int main() {
	// Устанавливаем корректное отображение русского языка в консоли
	setlocale(LC_ALL, "Russian");

	std::cout << "=== ИНИЦИАЛИЗАЦИЯ ДЕРЕВА ===" << std::endl;
	BinaryTree tree; // Здесь автоматически сработает ваш конструктор и попросит первый элемент

	int choice = 0;
	int value = 0;

	while (true) {
		std::cout << "\n=== МЕНЮ УПРАВЛЕНИЯ ДЕРЕВОМ ===" << std::endl;
		std::cout << "1. Добавить элемент" << std::endl;
		std::cout << "2. Удалить элемент по ключу" << std::endl;
		std::cout << "3. Вывести дерево на экран" << std::endl;
		std::cout << "4. Выйти из программы" << std::endl;
		std::cout << "Выберите действие: ";

		if (!(std::cin >> choice)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Ошибка ввода! Введите число от 1 до 4." << std::endl;
			continue;
		}

		switch (choice) {
		case 1:
			std::cout << "Введите число для добавления: ";
			if (std::cin >> value) {
				tree.AddEl(tree.root, value);
			}
			break;

		case 2:
			std::cout << "Введите ключ для удаления: ";
			if (std::cin >> value) {
				tree.PopByKey(tree.root, value);
			}
			break;

		case 3:
			std::cout << "\n--- ТЕКУЩЕЕ ДЕРЕВО ---" << std::endl;
			if (tree.root == nullptr) {
				std::cout << "[Дерево пустое]" << std::endl;
			}
			else {
				tree.Print(tree.root);
				std::cout << std::endl; // Перенос строки после вывода
			}
			break;

		case 4:
			std::cout << "Завершение работы программы. Память будет очищена деструктором." << std::endl;
			return 0;

		default:
			std::cout << "Некорректный выбор! Пожалуйста, выберите пункт от 1 до 4." << std::endl;
			break;
		}
	}

	return 0;
}
