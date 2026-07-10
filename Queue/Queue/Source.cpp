#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int num, Node* ptr = nullptr) : data(num), next(ptr) {}
};

struct Queue {
    Node* head;
    Node* tail;


    Queue() : head(nullptr), tail(nullptr) {}

    
    ~Queue() {
        Clear();
    }

    bool is_empty() {
        return head == nullptr;
    }

    
    void AddEl() {
        int num;
        printf_s("Введите число:\n");
        scanf_s("%d", &num);

        Node* ptr = new Node(num, nullptr);

        if (is_empty()) {
            head = ptr;
            tail = ptr;
        }
        else {
            tail->next = ptr; 
            tail = ptr;    
        }
    }


    void Top() {
        if (is_empty()) {
            std::cout << "ОЧЕРЕДЬ ПУСТА!\n";
            return;
        }
        printf_s("%d\n", head->data);
    }

   
    void Pop() {
        if (is_empty()) {
            std::cout << "ОЧЕРЕДЬ ПУСТА!\n";
            return;
        }

        Node* del_ptr = head; 
        head = head->next;    

        delete del_ptr;      

        if (head == nullptr) { 
            tail = nullptr;
        }
    }

    void Clear() {
        while (!is_empty()) {
            Pop();
        }
    }
};

void main() {
    setlocale(LC_CTYPE, "rus");

    Queue obj;
    bool flag = true;
    do {
        int choice;
        printf_s("\n1. Добавить элемент;\n");
        printf_s("2. Показать первый элемент;\n");
        printf_s("3. Изъять (удалить) элемент;\n");
        printf_s("4. Очистить очередь;\n");
        printf_s("0. Выйти из программы;\n");
        printf_s("Введите число: ");

        if (scanf_s("%d", &choice) != 1) {
            std::cout << "ОШИБКА ВВОДА!\n";
            break;
        }

        switch (choice) {
        case 1: obj.AddEl(); break;
        case 2: obj.Top(); break;
        case 3: obj.Pop(); break;
        case 4: obj.Clear(); std::cout << "Очередь очищена.\n"; break;
        case 0: flag = false; break;
        default: std::cout << "ОШИБКА ВВОДА!\n"; break;
        }
    } while (flag);

    std::cout << "УСПЕХ!\n";
}
