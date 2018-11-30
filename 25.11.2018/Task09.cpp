/* Напишите программу, находящую все простые числа Софи Жермен не превосходящие n. 
Программа должна работать не более чем за O(n*log log n) шагов. */

#include <iostream>
#include <cmath>

using namespace std;

int main() {
		
		unsigned int A;
		cin >> A;
		A +=  A + 1;

		bool *cof = new bool[A + 1];

		cof[0] = cof[1] = false;
		for (unsigned int i = 2; i <= A; i++)
				cof[i] = true;

		for (unsigned int  i = 2; i <= A; i++)
				if (cof[i] && i <= (unsigned int)sqrt(A))
				for (unsigned int j = i+i; j <= A; j += i) cof[j] = false;

     A = (A - 1) / 2;
	
	  for (unsigned int i = 2; i <= A; i++) 
		if (cof[i] && cof[2*i + 1]) cout << i << " ";
	
		return 0;
}
