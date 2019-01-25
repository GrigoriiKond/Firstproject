/* Напишите программу, находящую для заданной последовательности длины N неотрицательных целых чисел необходимо: максимальную сумму двух её элементов, номера которых различаются не менее чем на 5. Программа должна быть эффективной по времени и памяти */

#include <iostream>
using namespace std;
int main() {
	int ret = 0;
	int mxi = 0;
	int nano;
	int d = 5;
	int po;
	cin >> po;
	int *arr = new int[d - 1];
	for (int i = 0; i < d; i++)
	{
		cin >> nano;
		arr[i % d] = nano;
	}
	for (int i = d; i < po; i++)
	{
		cin >> nano;
		if (arr[i % d] > mxi) {
			mxi = arr[i % d];
		}
		if (nano + mxi > ret) {
			ret = nano + mxi;
			arr[i % d] = nano;
		}
	}
	cout << ret;
	return 0;
}
