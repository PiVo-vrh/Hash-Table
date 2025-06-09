#include "Hash_Table.h"
void Hash_Table::insert(int key) {
	int index = hash(key);
	if (!table[index].contains(key)) {
		table[index].push_front(key);
		cout << "Ёлемент " << key << " добавлен.\n";
	}
	else {
		cout << "Ёлемент уже существует.\n";
	}
}

void Hash_Table::remove(int key) {
	int index = hash(key);
	if (table[index].contains(key)) {
		table[index].remove_value(key);
		cout << "Ёлемент " << key << " удалЄн.\n";
	}
	else {
		cout << "Ёлемент не найден.\n";
	}
}

void Hash_Table::search(int key) {
	int index = hash(key);
	if (table[index].contains(key)) {
		cout << "Ёлемент найден в бакете " << index << ".\n";
	}
	else {
		cout << "Ёлемент не найден.\n";
	}
}

void Hash_Table::display() {
	for (int i = 0; i < SIZE; i++) {
		cout << "[" << i << "]: ";
		table[i].print();
		cout << endl;
	}
}

