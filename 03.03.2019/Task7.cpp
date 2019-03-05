/* Реализуйте класс int_stack_with_max - стек умеющий за O(1) выдавать максимальный хранимый элемент. */

#include <iostream>
using namespace std;

struct Node {
int data;
Node* next = NULL;
int maxim;
};
class int_stack_with_max {
private:
	Node* head;
	int n;
public:
	int_stack_with_max(): head(NULL),n(0){}
	void push_frt(int x){
		Node* temp = new Node;
		if(n == 0){
			temp ->maxim = x;
		}
		else{
			if(x > head ->maxim){
				temp ->maxim = x;
			}
			else{
				 temp ->maxim = head ->maxim;
			}
		}
	temp ->data = x;
	temp ->next = head;
	head = temp;
	n+=1;
	}
	int pop_frt(){
	if(head == NULL){
		cout<<"int_stack_with_max is empty...";
		return 0;
	}
	int x = head ->data;
	head = head ->next;
	n-=1;
	return x;
	}
	int mxm(){
	int a = head ->maxim;
	return a;
	}
	int num(){
	return n;
	}
	~int_stack_with_max(){
	while(head != NULL){
		Node* temp = head;
		head = head ->next;
		delete temp;
	}
	cout << "Destructor is working...";
	}
};
int main(){
	int_stack_with_max a;
	a.push_frt(1);
	 cout<<a.num()<<" "<<" "<<a.mxm()<<" ";
	a.push_frt(2);
	 cout<<a.num()<<" "<<" "<<a.mxm()<<" ";
	a.push_frt(3);
	 cout<<a.num()<<" "<<" "<<a.mxm()<<" ";
	a.push_frt(4);
	 cout<<a.num()<<" "<<" "<<a.mxm()<<" ";
	a.push_frt(5);
	cout<<a.num()<<" "<<" "<<a.mxm()<<" ";
	a.push_frt(6);
	cout<<a.num()<<" "<<" "<<a.mxm()<<" ";
	a.push_frt(7);
	cout<<a.num()<<" "<<a.mxm();
	cout<<a.pop_frt();
	cout<<a.mxm();
return 0;
}
