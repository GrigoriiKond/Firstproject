/* Напишите переборную программу программу, вычисляющую значение функции Эйлера для числа n. 
Программа должна работать не более чем за O(n* log n) шагов. */

#include <iostream>
using namespace std;

int gcd(int x, int y)
{
    while (y)
    {
        x %= y;
        swap(x,y);
    }
    return x;
}

int main()
{
    int A;
    cin >> A;
    int eler = 1;
    for(int i = 2; i < A; i++)
    
        if (gcd(i, A) == 1) eler++;

    cout << eler;
    
    return 0;
}
