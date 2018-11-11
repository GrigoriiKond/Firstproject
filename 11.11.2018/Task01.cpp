// Напишите программу, вычисляющую сумму нечетных цифр целого числа.

#include <iostream>
using namespace std;

int main()
{
    unsigned int a, b, q = 0;
    
    cout << "Enter your number: " << endl;
    cin >> a;
    b = (a % 10);

    while (a >= 1)
    {
        if ((b % 2) == 1)
        {
            q += b;
        }
        a /= 10;
        b = (a % 10);
    }

    cout << "Sum of odd digits of a number: " << q;
    
    return 0;
}
