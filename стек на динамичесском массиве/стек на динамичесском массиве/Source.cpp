#include <iostream>
#include <cstdio>



void AddEl(int size, int*& ptr, int& counter) {
	if (counter >= size) {

		std::cout << "ÐÀÇÌÅÐ ÏÐÅÂÛØÅÍ!\n";
		return;
	}
	int num;
	printf_s("Ââåäèòå ÷èñëî:");
	scanf_s("%d", &num);
	
	if (counter == 0) {
		*ptr = num;

	}
	else {
		ptr++;
		*ptr = num;
		
	}
	counter++;


};

void PopEl(int size, int*& ptr, int& counter) {

	if (counter <= 0) {
		std::cout << "ÑÒÅÊ ÏÓÑÒ!\n";
		return;
	}
	else {
		if (counter == 1) {
			counter--;
		}
		else {
			counter--;
			ptr--;
		}
		
	}

}

void Top(int size, int*& ptr, int& counter){

	if (counter <= 0) {
		std::cout << "ÑÒÅÊ ÏÓÑÒ!\n";
		return;
	}
	else {

		printf_s("%d\n", *ptr);

	}


}


void main() {
	setlocale(LC_CTYPE, "rus");

	bool flag = true;
	int counter = 0;
	int size;

	printf_s("Ââåäèòå ðàçìåð ñòåêà:\n");
	scanf_s("%d", &size);

	int* mptr = new int[size];

	int* ptr = mptr;

	do {

		int choice;
		printf_s("1. Äîáàâèòü ýëåìåíò;\n");
		printf_s("2. Óäàëèòü ýëåìåíò;\n");
		printf_s("3. Èçâëå÷ü ýëåìåíò;\n");
		printf_s("0. Âûéòè èç ïðîãðàììû;\n");
		std::cout << "Ââåäèòå ÷èñëî: ";
		std::cin >> choice;

		switch (choice) {
		case 1: {
			
			AddEl(size, ptr, counter);
			break;
		}
		case 2: {

			PopEl(size, ptr, counter);
			break;
		}
		case 3: {

			Top(size, ptr, counter);
			break;
		}
		case 0: {

			flag = false;
			break;
		}
		default: {
			std::cout << "ÎØÈÁÊÀ ÂÂÎÄÀ!\n"; 
			break;
		}
		}
	} while (flag);

	delete[] mptr;

	std::cout << "ÓÑÏÅÕ!";
}