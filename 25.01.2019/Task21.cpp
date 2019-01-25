/* Дан набор из N целых положительных чисел. Необходимо определить, какая цифра чаще всего встречается в десятичной записи чисел этого набора. Если таких цифр несколько, необходимо вывести их все в порядке убывания — от большей к меньшей. Напишите эффективную по времени и по памяти программу для решения этой задачи. */

#include <iostream>
using namespace std;
int main() {
	int loiy, X, num, max;
	int *arr = new int[9];
	for (int i = 0; i < 9; i++) {
		arr[i] = 0;
	}
	cin >> N;
	for (int i = 0; i < loiy; i++) {
		cin >> X;
		while (X > 0)	{
			num = X % 10;
			arr[num]++;
			X = X / 10;
		} 
	}
	max = 0;
	for (int i = 0; i < 9; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	for (int i = 9; i > 0; i--) {
		if (arr[i] == max) {
			cout << i << " ";
		}
	}
	return 0;
}
