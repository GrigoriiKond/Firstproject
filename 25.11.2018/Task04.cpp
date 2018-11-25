/* Напишите программу находящую первые n составных чисел.
Программа должна работать не более чем за O(n*log log n) шагов. */

#include <iostream>
#include <cmath>

using namespace std;
int main() {
		
		unsigned int A, g;
		
		cout << "First n:";
		cin >> A;
		cout << endl;
	   g = A;
	
	if (A <= 5) {
		A += A + A + 1;
		}
	else {
		A += A;
		}

	   bool * sot = new bool[A + 1];

		sot[0] = sot[1] = false;
		for (unsigned int i = 2; i <= A; i++)
		{
				sot[i] = true;
		}

		for (unsigned int i = 2; i*i <= A; i++)
		{
				if (sot[i] && i <= (unsigned int)sqrt(A))
				for (unsigned int j = i*i; j <= A; j += i)
				sot[j] = false;
		}
	
	unsigned int i = 2;
	while (g > 0)
	{
		if(!sot[i])
		{
			cout << i << " ";
			g--;
		}
		i++;
	}
		cout << endl;
		
		return 0;
}
