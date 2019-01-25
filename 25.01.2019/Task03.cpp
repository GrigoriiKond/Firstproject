/* У исполнителя четыре команды, которым присвоены номера:
1. прибавь 9
2. возведи в квадрат
3. умножь на 7
4. припиши 1 в конец
Первая из них увеличивает на 9 исходное число x, третья умножает это число на 7,
вторая переводит число x в число x*x, четвёртая добавляет к числу единицу в конец (например, из числа 30 получается число 301).
Программа для исполнителя — это последовательность команд. Напишите программу, проверяющую, можно ли последовательностью команд исполнителя получить из числа X число Y. Если можно, программа должна выписывать YES, в противном случае – NO. */

#include <iostream>
#include <cmath>
using namespace std;
bool sqr(long long n) {
	long long sqt = (long long)(sqrt((double)n) + 0.5);
	return sqt * sqt == n;
}
int main() {
	int X, Y;
	cin >> X >> Y;
	bool *qaz = new bool[Y + 1];
	for (long long i = 0; i <= Y; i++) {
		if (i == X) {
			qaz[i] = 1;
		}
		else if (i <= X) {
			qaz[i] = 0;
		}
		else if ((sqr(i) == true) && (i % 7 == 0) && (i % 10 == 1)) {
			qaz[i] = qaz[i - 9] || qaz[(int)sqrt(i)] || qaz[i / 7] || qaz[(i - 1) / 10];
		}
		else if ((sqr(i) == true) && (i % 7 == 0) && (i % 10 != 1)) {
			qaz[i] = qaz[i - 9] || qaz[(int)sqrt(i)] || qaz[i / 7];
		}
		else if ((sqr(i) == true) && (i % 7 != 0) && (i % 10 == 1)) {
			qaz[i] = qaz[i - 9] || qaz[(int)sqrt(i)] || qaz[(i - 1) / 10];
		}
		else if ((sqr(i) == true) && (i % 7 != 0) && (i % 10 != 1)) {
			qaz[i] = qaz[i - 9] || qaz[(int)sqrt(i)];
		}
		else if ((sqr(i) == false) && (i % 7 != 0) && (i % 10 != 1)) {
			qaz[i] = qaz[i - 9];
		}
		else if ((sqr(i) == false) && (i % 7 == 0) && (i % 10 == 1)) {
			qaz[i] = qaz[i - 9] || qaz[i / 7] || qaz[(i - 1) / 10];
		}
		else if ((sqr(i) == false) && (i % 7 == 0) && (i % 10 != 1)) {
			qaz[i] = qaz[i - 9] || qaz[i / 7];
		}
		else if ((sqr(i) == false) && (i % 7 != 0) && (i % 10 == 1)) {
			qaz[i] = qaz[i - 9] || qaz[(i - 1) / 10];
		}

	}
	if (qaz[Y] == 1) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
	return 0;
}
