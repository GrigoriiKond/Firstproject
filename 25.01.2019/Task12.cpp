/* Напишите переборную программу, находящую для заданной последовательности длины N неотрицательных целых чисел необходимо: минимальную сумму двух её элементов, номера которых различаются не менее чем на 5. Программа может быть неэффективной. */

#include <iostream>
using namespace std;
int min(int a, int b)
{
	if (a > b) {
		return b;
	}
	return a;
}
int minS(int *arr, int arrS) {
	int res = 2147483647;
	for (int i = 0; i < arrS - 5; i++) {
		for (int j = i + 5; j < arrS; j++) {
			res = min(res, arr[i] + arr[j]);
		}
	}
	return res;
}
int main() {
	int arrS;
	cin >> arrS;
	int *arr = new int[arrS];
	for (int i = 0; i < arrS; i++)
	{
		cin >> arr[i];
	}
	cout << minS(arr, arrS);
	return 0;
}
