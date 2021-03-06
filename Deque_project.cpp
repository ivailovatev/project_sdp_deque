// Deque_project.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include<iostream>
using namespace std;
template<typename T>
struct DequeElement {
	T data;
	DequeElement<T>* next;
};
template<typename T>
class Deque {
	DequeElement<T>* front;
	DequeElement<T>* back;
	void copyDeque(const Deque<T>&);
	void eraseDeque();
public:
	Deque();
	Deque(const Deque<T>&);
	Deque<T>& operator=(const Deque<T>&);
	~Deque();
	void pushFront(const T&);
	void pushBack(const T&);
	void popFront();
	void popBack();
	bool isEmpty()const;
	T Front()const;
	T Back()const;
};
void printWhenPushFrontAndPopFront(Deque<int>& q, int n) {
	for (int i = 0; i < n; i++) {
		q.pushFront(i);
	}
	cout << "Printing numbers from 0 to " << n - 1 << " when pushFront and popFront!" << endl;
	while (!q.isEmpty()) {
		cout << q.Front() << " ";
		q.popFront();
	}
	cout << endl << endl;
}
void printWhenPushBackAndPopBack(Deque<int>& q, int n) {
	for (int i = 0; i < n; i++) {
		q.pushBack(i);
	}
	cout << "Printing numbers from 0 to " << n - 1 << " when pushBack and popBack!" << endl;
	while (!q.isEmpty()) {
		cout << q.Back() << " ";
		q.popBack();
	}
	cout << endl << endl;
}
void printWhenPushFrontAndPopBack(Deque<char>& q, int n) {
	for (int i = 0; i <= n; i++) {
		q.pushFront(i + 'a');
	}
	cout << "Printing symbols from 'a' to '" << char(n + 'a') << "' when pushFront and popBack!" << endl;
	while (!q.isEmpty()) {
		cout << q.Back() << " ";
		q.popBack();
	}
	cout << endl << endl;
}
void printWhenPushBackAndPopFront(Deque<char>& q, int n) {
	for (char i = 0; i <= n; i++) {
		q.pushBack(i + 'a');
	}
	cout << "Printing symbols from 'a' to '" << char(n + 'a') << "' when pushBack and popFront!" << endl;
	while (!q.isEmpty()) {
		cout << q.Front() << " ";
		q.popFront();
	}
	cout << endl << endl;
}
void manyElements(Deque<int>& q, int n) {
	for (int i = 0; i < n; i++) {
		q.pushFront(i);
	}
	while (!q.isEmpty()) {
		if (q.Front() % 900 == 0)cout << q.Front() << " ";
		q.popFront();
	}
	cout << endl << endl;
}
int main()
{
	Deque<int> q1, q2, q5; Deque<char> q3, q4;
	printWhenPushFrontAndPopFront(q1, 10);
	printWhenPushBackAndPopBack(q2, 10);
	printWhenPushFrontAndPopBack(q3, 10);
	printWhenPushBackAndPopFront(q4, 10);
	manyElements(q5, 10001);
	return 0;
}

template<typename T>
void Deque<T>::copyDeque(const Deque<T>& other) {
	front = back = nullptr;
	if (other.isEmpty())return;
	DequeElement<T>* temp = other.front;
	while (temp) {
		push(temp->data);
		temp = temp->next;
	}
}
template<typename T>
void Deque<T>::eraseDeque() {
	while (!isEmpty()) popFront();
}
template<typename T>
Deque<T>::Deque() :front(nullptr), back(nullptr) {}
template<typename T>
Deque<T>::Deque(const Deque<T>& other) {
	copyDeque(other);
}
template<typename T>
Deque<T>& Deque<T>::operator=(const Deque<T>& other) {
	if (this != &other) {
		eraseDeque();
		copyDeque(other);
	}
	return *this;
}
template<typename T>
Deque<T>::~Deque() {
	eraseDeque();
}
template<typename T>
bool Deque<T>::isEmpty()const {
	return back == nullptr;
}
template<typename T>
void Deque<T>::pushBack(const T& _x) {
	DequeElement<T>* temp = new DequeElement<T>;
	temp->data = _x;
	temp->next = nullptr;
	if (!isEmpty()) back->next = temp;
	else front = temp;
	back = temp;
}
template<typename T>
void Deque<T>::pushFront(const T& _x) {
	DequeElement<T>* temp = new DequeElement<T>;
	temp->data = _x;
	temp->next = nullptr;
	if (!isEmpty()) temp->next = front;
	else back = temp;
	front = temp;
}
template<typename T>
T Deque<T>::Front()const {
	if (isEmpty()) return T();
	return front->data;
}
template<typename T>
T Deque<T>::Back()const {
	if (isEmpty())return T();
	return back->data;
}
template<typename T>
void Deque<T>::popFront() {
	if (isEmpty())return;
	DequeElement<T>* temp = front;
	front = front->next;
	if (front == nullptr)back = nullptr;
	delete temp;
}
template<typename T>
void Deque<T>::popBack() {
	if (isEmpty())return;
	DequeElement<T>* temp = back;
	if (front->next == nullptr)back = nullptr;
	else {
		DequeElement<T>* temp2 = front;
		while (temp2->next != temp) {
			temp2 = temp2->next;
		}
		back = temp2;
		back->next = nullptr;
	}
	delete temp;
}
