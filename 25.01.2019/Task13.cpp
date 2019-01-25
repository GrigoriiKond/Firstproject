/* Напишите переборную программу, находящую для заданной последовательности длины N целых чисел необходимо: максимальное произведение двух её элементов, номера которых различаются не менее чем на 5. Программа может быть неэффективной */

#include <iostream>
using namespace std;
int max(int a, int b)
{
	if (a < b) {
		return b;
	}
	return a;
}
int maxM(int *arr, int arrS) {
	int res = 0;
	for (int i = 0; i < arrS - 5; i++) {
		for (int j = i + 5; j < arrS; j++) {
			res = max(res, arr[i] * arr[j]);
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
	cout << maxM(arr, arrS);
	return 0;
}
