/* Напишите программу, находящую для заданной последовательности длины N целых чисел необходимо: минимальное произведение двух её элементов, номера которых различаются не менее чем на 5. Программа должна быть эффективной по времени и памяти. */

#include <iostream>
using namespace std;
int main() {
	int micro = 2147483647;
	int mxer = 2147483647;
	int x;
	int d = 5;
	int N;
	cin >> N;
	int *arr = new int[d - 1];
	for (int i = 0; i < d; i++)
	{
		cin >> x;
		arr[i % d] = x;
	}
	for (int i = d; i < N; i++)
	{
		cin >> x;
		if (arr[i % d] < mxer) {
			mxer = arr[i % d];
		}
		if (x * mxer < micro) {
			micro = x * mxer;
			arr[i % d] = x;
		}
	}
	cout << micro;
	return 0;
}
