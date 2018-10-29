// Напишите программу, вычисляющую сумму нечетных цифр целого числа.

#include <iostream>
#include <cmath>

using namespace std;

int main() {

int f,d;

cout << "Enter number: \n";
cin >> f;
if (f<0) f = -f;
d = f;
int i = 0;
int sum = 0;

  for (;;) { 
	
	i++; 
	
	f = f/10;
	
	if (f == 0) break;
	
  }

f = d;

  for (int n = 1; n <= i; n++) {

	int z;
	z = pow(10,n);

	int w; 
	w = f % z;
	
	int j;
	int y;
	y = pow(10,n-1);
	j = w / y;
	
	if ((i % 2 == 0) && (n % 2 == 0)) sum = sum + j;
	
	if ((i % 2 != 0) && (n % 2 != 0)) sum = sum + j;
	
	}
  
cout << "Sum of odd digits of a number: " << sum; 
	
return 0;
	
}
