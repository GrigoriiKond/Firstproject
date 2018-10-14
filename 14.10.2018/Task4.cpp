/*Напишите программу находящую в массиве сумму элементов делящихся либо на 72 либо на 27(не вместе).*/



#include <iostream>

#include <numeric>

using namespace std;



int main() {

unsigned int N,i;

int sum,a;

cin>>N;

sum=0;

for(i=0; i<N; i++) {

	cin>>a;

   if ((a % 72 == 0)^(a % 27 == 0) )

   

   sum+=a;

}



cout<<sum;



	return 0;

}
