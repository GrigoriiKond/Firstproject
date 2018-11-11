
/* Напишите логическую функцию, проверяющую, является строка палиндромом.
Можно считать, что строка состоит только из букв латиницы.*/

#include <iostream>
using namespace std;

bool str (char* A, int b)
{
	b--;
	int k = 0;
	for (int i = 0; i <= ((b - 1)/2); i++)
	{
		if (A[i] != A[b - i]) k++;
	}
	return (k == 0);
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

int main()
{
	int n;

	char* pl= new char [256];
	cin.getline(pl, 256, '\n');
	n = size(pl);

	cout << '\n';

	if (str(pl, n) == 1)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}
	return 0;
}
