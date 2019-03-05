/* Реализуйте класс int_list - односвязный список.  Класс должен содержать конструктор, конструктор копий,  деструктор, оператор присвоения, оператор [ ] - обращение по индексу, вставку по индексу, удаление по индексу. */

#include <iostream>
using namespace std;

struct Node {
int data;
Node* next = NULL;
};

class int_list{
private:
	Node* head;
	Node* tail;
	int nm = 0;
public:
	int_list(): head(NULL),tail(NULL){}
	void push_bck(int x){
		Node* temp = new Node;
	temp ->next = NULL;
	   temp ->data = x;
		if(head != NULL){
			tail ->next = temp;
			tail = temp;
		}
		else{
			tail = temp;
			head = tail;
		}
		nm++;
	}
	  void push_frt(int x){
		Node* temp = new Node;
		  temp ->data = x;
		if(head != NULL){
			temp ->next = head;
			head = temp;
		}
		else{
			temp ->next = NULL;
			tail = temp;
			head = tail;
		}
		nm++;
	  }
void desinsertex(int n){
		  if(head == NULL){
			cout<<"*********";
		  }
		  else{
				if(n == 1){
					cout<<"****";
					nm--;
					head = head ->next;
				}
				else{
	  int_list a;
	   Node* temp = new Node;
		temp = head;
		a.push_bck(temp ->data);
		 for(int i = 1; i < n - 1; i++){
				temp = temp ->next;
			 a.push_bck(temp ->data);
		 }
	   temp = temp ->next;
		 for(int i = 0; i < nm - n ; i++){
			 temp = temp ->next;
				 a.push_bck(temp ->data);
		 }
		 *this = a;
		  }
		  }
	  }
	void insertex(int x, int n){
		int_list a;
		Node* temp = new Node;
		temp = head;
		if(head == NULL){
			push_frt(x);
		}
		else{
				if(n == 1){
					push_frt(x);
				}
				else{
				a.push_bck(temp ->data);
		 for(int i = 1; i < n - 1; i++){
			 a.push_bck(temp ->data);
			temp = temp ->next;
		 }
		a.push_bck(x);
		 for(int i = 0; i <= nm - n ; i++){
				temp = temp ->next;
			 a.push_bck(temp ->data);
		 }
		 *this = a;
		}
		}
	}
	 int_list(const int_list& a){
		 head = a.head;
		 nm = a.nm;
		 Node* temp = a.head ->next;
		 while(temp ->next){
			push_bck(temp ->data);
			temp = temp ->next;
		 }
	cout << " Copying Constructor is working... ;";
	}
	int operator[](int a){
		int b;
		Node* temp = head;
	for(int i = 1; i < a; i++){
		temp = temp -> next;
	}
	b = temp ->data;
	return b;
	}
	const int_list& operator=(const int_list& a){
		Node* temp = new Node;
		temp ->next = NULL;
		nm = 1;
		temp ->data = a.head ->data;
		Node* tempp = a.head;
		tail = temp;
		head = tail;
		while(tempp ->next){
			tempp = tempp ->next;
			push_bck(tempp ->data);
		}
	cout << " operator = is working ;";
	return *this;
	}
	int num(){
		int x = nm;
	return x;
	}
	~int_list(){
	while(head != NULL){
		Node* temp = head;
		head = head ->next;
		delete temp;
	}
	}
};
int main(){
int_list e;
int_list m;
e.push_bck(1);
e.push_bck(2);
e.push_bck(3);
m = e;
e.insertex(5,2);
e.desinsertex(1);
cout<<" "<<m[2]<<" "<<m.num()<<" "<<e[1]<<" "<<e.num();
return 0;
}
