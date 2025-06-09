#pragma once
#include "list.h"
#include <iostream>
using namespace std;

class Hash_Table
{
private:
	static const int SIZE = 8;
	list<int> table[SIZE];

	int hash(int key) {
		return key % SIZE;
	}
public:
	void insert(int key);
	void remove(int key);
	void search(int key);
	void display();

};

