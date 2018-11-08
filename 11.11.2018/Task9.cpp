/* Напишите программу, находящую корень функции f, если известно, что f – монотонна. Функцию f считаем не известной (т.е. она просто возвращает значение по аргументу). Для отладки разумно использовать кубическую функцию. */

#include <iostream>
using namespace std;

bool fun(double a)
{
	return (a >= 0);
}

double fff(double a)
{
	return (a * a * a);
}

int main()
{
	double t, x = 0, c = 100, a = (x - c), b = (x + c);
	cin >> t;

	while (fun(fff(a)) == fun(fff(b)))
	{
		a -= c;
		b += c;
	}

	double d = (b - a);

	while ((fff(x) != 0) && (fun(fff(x - t)) == fun(fff(x + t))))
	{
		d /= 2;
		if (fun(fff(a)) != fun(fff(x)))
		{
			b -= d;
			x -= (d / 2);
		}
		else
		{
			a += d;
			x += (d / 2);
		}
	}

	cout << x;
}
