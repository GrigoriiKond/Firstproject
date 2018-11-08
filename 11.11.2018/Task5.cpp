/* Напишите программу, заменяющую составные числа на их самые большие простые делители. */

#include <iostream>
using namespace std;

bool sopro(int a)
{
	int w = 0;
	if (a == 1)
	{
		return 0;
	}
	else
	{
		for (int i = 2; i <= (a / 2); i++)
		{
			if ((a % i) == 0)
			{
				return 0;
				break;
				w++;
			}
		}
		if (w == 0)	return 1;
	  }
}

int main()
{
	long long y;
	cin >> y;


	for (int i = y; i >= 2; i--)
	{
		if (((y % i) == 0) && (sopro(i) == 1))
		{
			y = i;
			break;
		}
	}
	cout << y;

}
