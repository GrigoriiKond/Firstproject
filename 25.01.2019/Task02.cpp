/* У исполнителя четыре команды, которым присвоены номера:
1. прибавь 1
2. сделай чётное
3. сделай нечётное
4. умножь на 10
Первая из них увеличивает на 1 исходное число x, вторая умножает это число на 2, третья переводит число x в число 2x + 1, четвёртая умножает его на 10.
Программа для исполнителя — это последовательность команд. Напишите программу вычисляющую, сколько существует программ, 
которые число X преобразуют в число Y, таких, что в промежуточных действиях не встречается число Z. */

#include <iostream> 
using namespace std;
int main() {
	int X, Y, Z;
	cin >> X >> Y >> Z;
	long long *ser = new long long[Y + 1];
	for (long long i = 0; i <= Y; i++) {
		if (i == X) {
			ser[i] = 1;
		}
		else if (i <= X) {
			ser[i] = 0;
		}
		else if (i == Z) {
			ser[i] = 0;
		}
		else if ((i % 2 != 0) && (i % 10 == 0)) {
			ser[i] = ser[i - 1] + ser[(i - 1) / 2] + ser[i / 10];
		}
		else if ((i % 2 != 0) && (i % 10 != 0)) {
			ser[i] = ser[i - 1] + ser[(i - 1) / 2];
		}
		else if ((i % 2 == 0) && (i % 10 == 0)) {
			ser[i] = ser[i - 1] + ser[i / 2] + ser[i / 10];
		}
		else if ((i % 2 == 0) && (i % 10 != 0)) {
			ser[i] = ser[i - 1] + ser[i / 2];
		}
	}
	cout << ser[Y];
	return 0;
}
