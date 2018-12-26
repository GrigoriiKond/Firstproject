/* Напишите программу, находящую k-ую порядковую статистику. Программа должна работать за время O(n) в среднем. */

#include <iostream>
using namespace std;

int poil(int *A, int l, int r, int k)
{
	int x;
	int i = l;
	int j = r;
	int midle;
	while (true)
	{
		midle = ((l + r) - (l + r) % 2) / 2;
		while (midle >= A[i])
			i++;
		while (midle <= A[j])
			j++;
		if (A[i] < A[j])
		{
			x = A[i];
			A[i] = A[j];
			A[j] = x;
		}
		if (i > j)
			break;
	}

	if (k == midle)
		return A[midle];
	if (r - l < 4)
		return(A[k]);
	else
		{
	if (k < midle)
		poil(A, l, midle, k);

	if (k > midle)
		poil(A, midle, r, k);
		}
}
int main()
{
	int n;
	cin >> n;
	cout << endl;
	int *Array = new int[n];
	for (int q = 0; q < n; q++)
		cin >> Array[q];
		cout << endl;
		int K;
		cin >> K;
		
	cout << poil(Array, 0, n-1, K);

		return 0;
}
