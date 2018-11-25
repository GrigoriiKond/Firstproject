/* Напишите эффективную функцию, выписывающую из массива длины n все элементы, 
у которых количество двоек в троичной записи меньше k. 
Функция должна возвращать общее количество двоек в троичной записи всех чисел массива. */

#include <iostream>
using namespace std;

unsigned int dit (unsigned int a)
{
	if (a < 3 && a != 2)
		return 0;
	else if (a % 3 == 2)
		return 1 + dit(a / 3);
	else 
		return dit(a / 3);

}

unsigned int adit (unsigned int* num, unsigned int raz, unsigned int s)
{
	unsigned int t = 0, y = 0;
	for (unsigned int i = 0; i < raz; i++)
	{
		y = t;
		t += dit(num[i]);
		
		if (-y + t < s)
			cout << num[i] << " ";
	}
	return t;
}

int main()
{
	unsigned int A, B;
	cin >> A >> B;
	unsigned int *num = new unsigned int[A];
	for (unsigned int i = 0; i < A; i++)
	{
		cin >> num[i];
	}
	cout << adit(num, A, B) << endl;
	
	return 0;
}
