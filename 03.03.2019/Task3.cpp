/* Реализуйте класс char_deque -  дек символов чисел переменного размера. Класс должен содержать конструктор, деструктор, методы push_front, push_back,pop_front, pop_back */

#include <iostream>
#include <string>
using namespace std;

struct Node {
	char data;
	Node* next = NULL;
	Node* prev = NULL;
};
class char_deque {
	Node* head;
	Node* tail;
public:
	char_deque(): head(NULL){}
	void push_front(char x) {
		if (head == NULL) {
			head = new Node;
			tail = head;
			head->data = x;
		}
		head->prev = new Node;
		head->prev->next = head;
		head = head->prev;
		head->data = x;
	}
	void push_back(char x) {
		if (head == NULL) {
			head = new Node;
			tail = head;
			head->data = x;
		}
		tail->next = new Node;
		tail->next->prev = tail;
		tail = tail->next;
		tail->data = x;
	}
	char pop_front() {
		if (head == NULL) {
			cout << "Deque is empty...";
			return 0;
		}
		Node* temp = head;
		head = head->next;
		char x = temp->data;
		delete temp;
		return x;
	}
	char pop_back() {
		if (head == NULL) {
			cout << "Deque is empty...";
			return 0;
		}
		Node* temp = tail;
		tail = tail->prev;
		char x = temp->data;
		delete temp;
		return x;
	}
	~char_deque() {
		while (head != NULL) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}
};
int main() {
	char_deque A;
	A.push_front('a');
	A.push_front('b');
	cout << A.pop_front() << "\n";
	cout << A.pop_front() << "\n";
	A.push_back('c');
	A.push_back('d');
	A.push_back('f');
	cout << A.pop_back() << "\n";
	cout << A.pop_back() << "\n";
	return 0;
}
