
/*Напишите программу находящую обратный по модулю элемент. Иначе говоря по числам X и N нужно найти такое число Y, что остаток от деления X*Y на N равняется единице. В программе гарантируется, что все числа - натуральные*/

#include <iostream>
#include <numeric>

using namespace std;

int main() {

unsigned int N,X,Y;

Y=1;

cin>>X>>endl;

cin>>N;

if (gcd(X,N)!=1) {

    cout<<"None"<<endl;

}

	else { 

	for(;X*(++Y)%N !=1;);

	cout << Y;

    

}

return 0;

}
