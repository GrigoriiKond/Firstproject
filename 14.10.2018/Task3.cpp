/*Напишите программу вычисляющую среднее арифметическое последовательности чисел. Длина последовательности неизвестна, однако последовательность оканчивается нулем и других нулевых значений не встречается. */

#include <iostream>
#include <numeric>

using namespace std;

int main() {
float a,b,sum;
unsigned int size;

sum=0;

size=0;

do {

    cin>>a;
    sum+=a;
    size++;

}

while(a!=0);
b = sum/size;
cout<<b;

	return 0;

}
