#include "list.h"

template<class T>
list<T>::list() {
	Size = 0;
	head = nullptr;
}

template<class T>
void list<T>::pop_front() {
	if (!head) return;
	Node<T>* current = head->ptr_next;
	delete head;
	head = current;
	Size--;
}

template<class T>
void list<T>::clear() {
	while (Size) pop_front();
}

template<class T>
void list<T>::push_back(T data) {
	if (!head) {
		head = new Node<T>(data);
	}
	else {
		Node<T>* current = head;
		while (current->ptr_next) {
			current = current->ptr_next;
		}
		current->ptr_next = new Node<T>(data);
	}
	Size++;
}

template<class T>
void list<T>::push_front(T data) {
	Node<T>* current = new Node<T>(data);
	current->ptr_next = head;
	head = current;
	Size++;
}

template<class T>
void list<T>::insert(T data, int index) {
	if (index == 0) {
		push_front(data);
	}
	else {
		Node<T>* current = head;
		for (int i = 0; i < index - 1; i++) {
			current = current->ptr_next;
		}
		Node<T>* newNode = new Node<T>(data, current->ptr_next);
		current->ptr_next = newNode;
	}
	Size++;
}

template<class T>
void list<T>::print() {
	Node<T>* current = head;
	while (current) {
		cout << current->data << " ";
		current = current->ptr_next;
	}
}

template<class T>
void list<T>::pop_back() {
	if (!head) return;
	if (!head->ptr_next) {
		delete head;
		head = nullptr;
	}
	else {
		Node<T>* current = head;
		while (current->ptr_next->ptr_next) {
			current = current->ptr_next;
		}
		delete current->ptr_next;
		current->ptr_next = nullptr;
	}
	Size--;
}

template<class T>
void list<T>::removeAt(int index) {
	if (index == 0) {
		pop_front();
	}
	else {
		Node<T>* current = head;
		for (int i = 0; i < index - 1; i++) {
			current = current->ptr_next;
		}
		Node<T>* to_delete = current->ptr_next;
		current->ptr_next = to_delete->ptr_next;
		delete to_delete;
	}
	Size--;
}

template<class T>
int list<T>::Get_size() { return Size; }

template<class T>
T& list<T>::operator[](const int index) {
	Node<T>* current = head;
	for (int i = 0; i < index; i++) {
		current = current->ptr_next;
	}
	return current->data;
}

template<class T>
bool list<T>::contains(T data) {
	Node<T>* current = head;
	while (current) {
		if (current->data == data) return true;
		current = current->ptr_next;
	}
	return false;
}

template<class T>
void list<T>::remove_value(T data) {
	if (!head) return;
	if (head->data == data) {
		pop_front();
		return;
	}
	Node<T>* current = head;
	while (current->ptr_next && current->ptr_next->data != data) {
		current = current->ptr_next;
	}
	if (current->ptr_next) {
		Node<T>* to_delete = current->ptr_next;
		current->ptr_next = to_delete->ptr_next;
		delete to_delete;
		Size--;
	}
}

template<class T>
list<T>::~list() {
	clear();
}

template class list<int>; // явно укказал шабллон класса во избежании ошибки LNK2019
