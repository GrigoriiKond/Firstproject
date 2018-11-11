/* Напишите процедуру, заполняющую квадратный двумерный массив по диагоналям.
На побочной диагонали должны стоять наибольшие значения, на соседних с ней - на единицу меньшие, 
и так далее - до угла, в котором должны стоять единицы. */

#include <сstdio>
using namespace std;

void mass(int** &a, int b)
{
	b--;

	int c = b, d = 0, k = 1;
	while (c >= d)
	{
		int x = d, y = d;

		while (x < c)
		{
			a[y][x] = k;
			k++, x++;
		}

		while (y < c)
		{
			a[y][x] = k;
			k--, y++;
		}

		while (x > d)
		{
			a[y][x] = k;
			k++, x--;
		}

		while (y > d)
		{
			a[y][x] = k;
			k--, y--;
		}

		d++, c--;
		k += 2;
	}

	if ((b % 2) == 0) a[(b/2)][(b/2)] = (b+1);
}

int main()
{
	int n;
	scanf("%d", &n);
	int** soz = new int* [n];
	for (int dov = 0; dov < n; dov++)
	{
		*(soz + dov) = new int [n];
	}
	int w = 2;
	if ((n / 10) > 0) w += 2;
	mass(soz, n);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
		   if (j == 0) {
		   printf("%2d", soz[i][j]);
		   }
			else {
			printf("%*d", w, soz[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}
