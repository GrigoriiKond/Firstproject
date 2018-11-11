/* Напишите две функции, находящие приближенное значение квадратного и кубического корня. В программе не должны использоваться математические библиотеки. */

#include <iostream>
using namespace std;

double sqrt(double a)
{
	double d;
	double c = 0.000001;
	for (double i = 0;; i += c)
	{
		if (((i * i) <= a) && (((i + c) * (i + c)) >= a))
		{
			d = i;
			break;
		}
	}
	d *= (1 / c);
	long long s = (long long)d + 1;
	int f = (s % 10);
	if (f >= 5)
	{
		s -= f;
		s += 10;
	}
	else
	{
		s -= f;
	};
	d = (s / 10);
	d *= (c * 10);
	return d;
}

double cubsqrt(double a)
{
	double d;
	double c = 0.000001;
	for (double i = 0;; i += c)
	{
		if ((i * i * i <= a) && ((i + c) * (i + c) * (i + c) >= a))
		{
			d = i;
			break;
		}
	}
	d *= (1 / c);
	long long s = (long long) d + 1;
	int f = (s % 10);
	if (f >= 5)
	{
		s -= f;
		s += 10;
	}
	else
	{
		s -= f;
	};
	d = (s / 10);
	d *= (c * 10);
	return d;
}

int main()
{
	long long y;
	cout << "Enter your number: \n";
	cin >> y;
	cout << "sqrt(number): " << sqrt(y) << '\n';
	cout << "cubsqrt(number): " << cubsqrt(y) << '\n';
	return 0;
}
