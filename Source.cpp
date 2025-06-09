#include <iostream>
using namespace std;
#include "Hash_Table.h"



int main() {
	setlocale(LC_ALL, "Russian");

	Hash_Table ht;
	int choice, value;

	do {
		cout << "\nМеню:\n";
		cout << "1. Вставить\n2. Удалить\n3. Поиск\n4. Печать\n0. Выход\n";
		cout << "Выбор: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Введите значение: ";
			cin >> value;
			ht.insert(value);
			break;
		case 2:
			cout << "Введите значение: ";
			cin >> value;
			ht.remove(value);
			break;
		case 3:
			cout << "Введите значение: ";
			cin >> value;
			ht.search(value);
			break;
		case 4:
			ht.display();
			break;
		case 0:
			cout << "Выход.\n";
			break;
		default:
			cout << "Неверный выбор!\n";
		}
	} while (choice != 0);

	return 0;
}
