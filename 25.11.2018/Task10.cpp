/* Напишите функцию вычисляющую праймориал числа. Программа должна работать не более чем за O(n*log log n) шагов.*/

#include <iostream>
using namespace std;

void praim(bool B[], int N) {

int i, P;
int a = 1;

for (P = 2; P <= N; P++) B[P]=true;

P = 2;

while (P * P <= N) {

 i = P * P;

 if (B[P])
 while (i <= N) {
 B[i] = false;
 i += P;
 }

 P++;
}

for (P = 2; P <= N; P++) {

 if (B[P]== true) a *= P;

}

cout << a;

}

int main() {
 
 int N;
 
 cin >> N;

 cout << N << "#_"; 

 bool *B = new bool[N];

 praim (B, N);

return 0;

}

