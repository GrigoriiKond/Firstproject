/* Имеется набор данных, состоящий из пар положительных целых чисел. Необходимо выбрать из каждой пары ровно одно число так, чтобы сумма всех выбранных чисел не делилась на 3 и при этом была максимально возможной. Если получить требуемую сумму невозможно, в качестве ответа нужно выдать 0. Напишите программу для решения этой задачи. */

#include <iostream> 
using namespace std;
int main() {
	int res = 2147483646;
	int N, A, B, max, min, summa = 0, maxxmin;
	maxxmin = res + 1;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A >> B;
		if (A > B) {
			max = A;
			min = B;
		}
		else {
			max = B;
			min = A;
		}
		summa += max;
		if (((max - min) % 3 != 0) && (max - min < maxxmin)) {
		maxxmin = max - min;
		}
	}
	if (summa % 3 == 0) {
		if (maxxmin > res) {
			summa = 0;
		}
		else {
			summa -= maxxmin;
		}
	}
	cout << summa;
	return 0;
}
