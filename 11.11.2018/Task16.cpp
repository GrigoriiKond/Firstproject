/* Напишите процедуру, заполняющую квадратный двумерный массив пирамидой. */

#include <cstdio>
using namespace std;

void mass(int **&a, int b) {
	b--;

	int c = b, d = 0, k = 1;
	while (c >= d)
	{
		int x = d, y = d;

		while (x < c)
		{
			a[y][x] = k;
			x++;
		}

		while (y < c)
		{
			a[y][x] = k;
			y++;
		}

		while (x > d)
		{
			a[y][x] = k;
			x--;
		}

		while (y > d)
		{
			a[y][x] = k;
			y--;
		}

		d++;
		c--;
		k++;
	}

	if ((b % 2) == 0) a[(b / 2)][(b / 2)] = ((b / 2) + 1);
}

int main() {
	int n;
	scanf("%d", &n);
	int ** one = new int *[n];
	for (int two = 0; two < n; two++)
	{
		*(one + two) = new int[n];
	}

	int w = 2;
	if ((n/2) >= 10) w++;
	mass(one, n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j == 0) {
			printf("%d", one[i][j]);
			}
			 else {
			 printf("%*d", w, one[i][j]);
			 }
		}
		printf("\n");
	}
	return 0;
}
