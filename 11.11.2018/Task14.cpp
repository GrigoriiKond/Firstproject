/* Напишите процедуру, проводящую “разжатие” символьного динамически выделенного массива, сделанное в прошлой задаче. 
Например строка “3a1b5c2d“ должна перейти в “aaabcccccdd”. 
Можно считать, что не бывает более девяти одинаковых букв, идущих подряд. */

#include <iostream>
using namespace std;

int fs(char* a, int b)
{
	int l = 0, k;
	for (int i = 0; i < b; i++)
	{
		if ((i % 2) == 0)
		{
			k = (*(a + i) - '0');
			l += k;
		}
	}
	return l;
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

void aczhat (char* &a, int b)
{
	int t = fs(a, b);
	char* sec = new char [t];
	int q, w = 0;

	for (int i = 0; i < b; i += 2)
	{
		q = (*(a + i) - '0');
		while (q != 0)
		{
			*(sec + w) = *(a + i + 1);
			q--, w++;
		}
	}

	a = sec;
}

int main()
{
   int n;
   char* th = new char [256];
   cin.getline(th, 256, '\n');
   n = size(th);

   int w = fs(th, n);
   aczhat(th, n);

   for (int i = 0; i < w; i++)
   {
	   cout << *(th + i);
   }
   return 0;
}
