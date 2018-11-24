/* Напишите процедуру, удаляющую из динамически выделенной строки лишние пробелы.
Не лишними считаются одиночные пробелы, разделяющие пару слов.
По окончании работы процедуры количество выделенной памяти должно увеличиться. */

#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int fg (char* a, int b)
{
	int p = 0;

	for (int i = 0; i < b; i++)
	{
		if (*(a + i) == ' ')
		{
			if (i == 0)
			{
				p++;
			}
			else
			{
				if (i == (b - 1))
				{
					p++;
				}
				else
				{
					if (*(a + i + 1) == ' ') p++;
				}
			}
		}
	}
	return p;
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

 void pus (char* &a, int b)
{
	int r = fg(a, b);
	int k = (b - r);
	char* rgt = new char [k];

	int i = 0, j = 0;;
	while (j < b)
	{
		if (i == k) break;
		if ((*(a + j)) != ' ')
		{
			*(rgt + i) = *(a + j);
			i++;
		}
		else
		{
			if (j != 0)
			{
				if (*(a + j - 1) != ' ')
				{
					*(rgt + i) = *(a + j);
					i++;
				}
			}
		}
		j++;
	}

	a = rgt;
}

int main()
{
	int n;

	char* der = new char [256];
	gets(der);
	n = size(der);
	int y = fg(der, n);

	pus(der, n);

	int i = 0;
	while (i < (n - y))
	{
		if (*(der + i) != ' ') cout << *(der + i);
		if (*(der + i) == ' ') cout << " ";
		i++;
	}
return 0;
}
