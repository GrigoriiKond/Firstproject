/*Напишите программу проверяющую является ли число составным. В программе гарантируется, что число - натуральное.*/



#include <iostream>

using namespace std;



int main() {

	

	unsigned int a,b,c;

	cin >> a;

	

	if (a==1) {

	cout<<"Unit"<<endl;

	return 0;

		}else{

	  

	for (c=2; c<a; c++) {

	if (a%c==0){

	cout<<"Composite";

	return 0;}

	  

	  }
    }

		

		cout<< "Prime";

	return 0;

	



}
