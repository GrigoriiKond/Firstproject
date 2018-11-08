/* Напишите процедуру, удаляющую из динамически выделенного массива все четные значения 
(функция принимает в качестве аргументов – указатель на массив и его размер).
По окончании работы процедуры количество выделенной памяти должно уменьшиться. */

#include <iostream>
using namespace std;

int dinm(int* a, int b)
{
    int m = 0;
    for (int i = 0; i < b; i++)
    {
    if (((*(a + i)) % 2) == 0) m++;
    }
    return m;
}

void qw(int* &c, int d)
{
    int r = dinm(c, d);

    int* qwe= new int[d - r];
    int k = 0;
    for (int i = 0; i < d; i++)
    {
        if (((*(c + i)) % 2) != 0)
        {
            *(qwe + k) = *(c + i);
            k++;
        }
    }

    c = qwe;
}

int main()
{
    int n;
    cin >> n;
    int* cap = new int[n];
    for (int i = 0; i < n; i++)
    {
       cin >> *(cap + i);
    }

    int f = dinm(cap, n);
    qw(cap, n);
    cout << '\n';

    for (int i = 0; i < (n - f); i++)
    {
        cout << *(cap + i) << " ";
    }
    delete[] cap;
}
