/* У исполнителя Удвоитель-Утроитель три команды, которым присвоены номера:
1. прибавь 1
2. умножь на 2
3. умножь на 3.
Первая из них увеличивает на 1 число на экране, вторая увеличивает это число в 2 раза, третья – в 3 раза. Программа для Удвоителя-Утроителя — это последовательность команд. Напишите программу вычисляющую, сколько существует программ, которые число X преобразуют в число Y. */

#include <iostream>
using namespace std;
int main() {
	int X, Y;
	cin >> X >> Y;
	long long *ser = new long long[Y+1];
	for (long long i = 0; i <= Y; i++) {
		if (i == X) {
			ser[i] = 1;
		}
		else if (i <= X) {
			ser[i] = 0;
		}
		else if ((i % 2 == 0) && (i % 3 == 0)) {
			ser[i] = ser[i - 1] + ser[i / 2] + ser[i / 3];
		}
		else if ((i % 2 == 0) && (i % 3 != 0)) {
			ser[i] = ser[i-1] + ser[i/2];
		}
		else if ((i % 2 != 0) && (i % 3 == 0)) {
			ser[i] = ser[i - 1] + ser[i / 3];
		}
		else if ((i % 2 != 0) && (i % 3 != 0)) {
			ser[i] = ser[i - 1];
		}
	}
	cout << ser[Y];
	return 0;
}
