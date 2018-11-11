/* Напишите программу, вычисляющую произведение цифр целого числа, чётность которых совпадает с чётностью последней цифры. */

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
int pr = 1;

for (;;) { 
    
    i++; 
    
    f = f / 10;
    
    if (f == 0) break;
    
    }

f = d;

int x = f % 10;

for (int n = 1; n <= i; n++) {

    int z;
    z = pow(10,n);

    int w; 
    w = f % z;
    
    int j;
    int y;
    y = pow(10,n-1);
    j = w / y;
    
    if ((x % 2 == 0) && (j % 2 == 0)) pr *= j;
    
    if ((x % 2 != 0) && (j % 2 != 0)) pr *= j;
    
    }
    
cout << "The product of digits whose parity coincides with the parity of the last: " << pr; 
    
return 0;
    
}
