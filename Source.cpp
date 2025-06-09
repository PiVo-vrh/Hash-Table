#include <iostream>
using namespace std;
#include "Hash_Table.h"



int main() {
	setlocale(LC_ALL, "Russian");

	Hash_Table ht;
	int choice, value;

	do {
		cout << "\n����:\n";
		cout << "1. ��������\n2. �������\n3. �����\n4. ������\n0. �����\n";
		cout << "�����: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "������� ��������: ";
			cin >> value;
			ht.insert(value);
			break;
		case 2:
			cout << "������� ��������: ";
			cin >> value;
			ht.remove(value);
			break;
		case 3:
			cout << "������� ��������: ";
			cin >> value;
			ht.search(value);
			break;
		case 4:
			ht.display();
			break;
		case 0:
			cout << "�����.\n";
			break;
		default:
			cout << "�������� �����!\n";
		}
	} while (choice != 0);

	return 0;
}
