/* Напишите программу, вычисляющую биномиальный коэффициент из n по к. 
В программе нельзя использовать числа, превышающие итоговое значение. */

#include <iostream>
using namespace std;

unsigned int Cww(unsigned int a, unsigned int b) {
    
    if (b == 0 || a == b) return 1;

    else {
    return Cww(a-1,b-1)+ Cww(a-1,b);
    }
    
    }

int main() {

unsigned int n, k;

cout << "The calculation of the binomial coefficient (C)from(n)to(k):" << endl << endl;

cout << "Enter (n): \n";
cin >> n;

cout << "Enter (k): \n";
cin >> k;

if (k>n) cout << "(C)from(n)to(k): \n "<< "0";

if (k<0 || n<0) cout << "(C)from(n)to(k): \n "<< "0";

if (n>=k) {

cout << "(C)from(n)to(k): \n";

cout << Cww(n,k);
  
}

  return 0;
}


 
