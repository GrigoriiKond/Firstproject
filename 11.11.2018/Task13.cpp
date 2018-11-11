/* Напишите процедуру, проводящую сжатие символьного динамически выделенного массива. 
Несколько подряд идущих одинаковых букв должны заменяться на их количество и саму букву. 
Например, строка “aaabcccccdd” должна перейти в “3a1b5c2d”.
Можно считать, что не бывает более девяти одинаковых букв, идущих подряд. */

#include <iostream>
using namespace std;

int jjj (char* a, int b)
{
	int k = 1;
	for (int i = 0; i < (b-1); i++)
	{
		if ((*(a+i)) != (*(a+i+1))) k++;
	}
	return k;
}

int size(char* a)
{
	int b = 0;
	while(*a++)
	{
		b++;
	}
	return b;
}

void czhat (char* &a, int b)
{
	int r = jjj(a, b);
	r += r;
	int z = 0;
	char* mko = new char [r];
	int i = 0;
	while (i < b)
	{
		int v = 0;
		int j = i;
		while ((*(a+i)) == (*(a+j)))
		{
			v++;
			j++;
		}

		*(mko + z + 1) = *(a+i);
		*(mko + z) = v + '0';
		i = j;
		z += 2;
	}

	a = mko;
}


int main()
{
   int n;

   char* vuv= new char [256];
   cin.getline(vuv, 256, '\n');
   n = size(vuv);

   int f = jjj(vuv,n);
   f += f;
   czhat(vuv, n);

   for (int i = 0; i < f; i++)
   {
	   cout << *(vuv + i);
   }
   return 0;
}
