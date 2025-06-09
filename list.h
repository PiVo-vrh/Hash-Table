#pragma once
#include <iostream>
using namespace std;

template<class T>
class list {
public:
	list();
	void pop_front();
	void pop_back();
	void removeAt(int index);
	void clear();
	void push_back(T data);
	void push_front(T data);
	void insert(T data, int index);
	void print();
	int Get_size();
	T& operator [](const int index);
	bool contains(T data);
	void remove_value(T data);
	~list();

private:
	template<class T>
	struct Node {
		Node* ptr_next;
		T data;
		Node(T data = T(), Node* ptr_next = nullptr) {
			this->data = data;
			this->ptr_next = ptr_next;
		}
	};
	int Size;
	Node<T>* head;
};
