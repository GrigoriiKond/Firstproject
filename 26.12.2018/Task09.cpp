/* Дана таблица размера MxN, заполненная числами. Напишите программу, находящую путь с наибольшей суммой из верхней левой клетки в правую нижнюю, использующий только ход вправо и вниз на одну клетку. в ответе нужно выписать сумму значений из клеток на этом пути. */

#include <iostream>
using namespace std;

int Mx(int a, int b) {
	if (a >= b)
		return a;
	else
		return b;
}
int main()
{
	int N, M;
	cin >> N >> M;
	int **Vvv = new int *[N];
	
	for (int i = 0; i < M; i++) Vvv[i] = new int[M];
	
	
	for (int i = 0;i < M; i++) {
		for (int j = 0; j < N; j++) cin >> Vvv[j][i];
	}
	
	for (int i = 0;i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (i == 0) {
				if (j == 0)
					Vvv[j][i] = Vvv[j][i];
				if (j != 0)
					Vvv[j][i] += Vvv[j-1][i];
			}
			else if (j == 0)
			Vvv[j][i] += Vvv[j][i - 1];
				else 
					Vvv[j][i] += Mx(Vvv[j-1][i], Vvv[j][i - 1]);
		}
	}


	cout << Vvv[N - 1][M - 1];

	return 0;
}
