/* Дан массив, содержащий N неотрицательных целых чисел. Напишите на одном из языков программирования программу, которая находит в этом массиве количество
элементов, значение которых менее чем в два раза превосходит значение предшествующего элемента. */

#include <iostream>
using namespace std;
int main() {
	int Net;
	int k = 0;
	cin >> Net;
	int *arr = new int[Net];
	for (int i = 0; i < Net; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < Net; i++) {
		if (arr[i] < 2 * arr[i-1]) {
			k++;
		}
	}
	cout << k;
	return 0;
}
