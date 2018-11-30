/* Напишите программу, находящую все простые числа Ченя не превосходящие n. 
Программа должна работать не более чем за O(n*log log n) шагов. */

#include <iostream>
#include <cmath>
using namespace std;

unsigned int chen(unsigned int A, unsigned int B)
{
	unsigned int z = 0;
	while (A % (unsigned int)pow(B, z++) == 0);
	return z - 2;
	
}

int main()
{
        unsigned int C;
        cin >> C;
        C += 2;

        int  * poi = new int[C + 1];
        
        poi[0] = poi[1] = 2;
        for (unsigned int i = 2; i <= C; i++)
                poi[i] = 2;

        for (unsigned int i = 2; i <= C; i++)
                if (poi[i] == 2)
                for (unsigned int j = i+i; j <= C; j += i) poi[j] += chen(j, i);

        C -= 2;
        for (unsigned int i = 2; i <= C; i++)
                if (poi[i] == 2 && (poi[i + 2] == 4 || poi[i + 2] == 2)) cout << i << " ";
       
        return 0;
}
