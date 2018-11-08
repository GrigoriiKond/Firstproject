/* Напишите процедуру, удаляющую из динамически выделенного массива максимальный и минимальный элементы
(если таковых несколько – удалить нужно все). По окончании работы процедуры количество выделенной памяти должно уменьшиться. */

#include <iostream>
using namespace std;

int Max (int* a, int b)
{
    int q = *a;
    for (int i = 0; i < b; i++)
    {
        if ((*(a + i)) > q) q = *(a+i);
    }
    return q;
}

int Min (int* a, int b)
{
    int q = *a;
    for (int i = 0; i < b; i++)
    {
        if ((*(a + i)) < q) q = *(a+i);
    }
    return q;
}

int qaz (int* a, int b)
{
    int m = 0;
    for (int i = 0; i < b; i++)
    {
        if (((*(a + i)) == (Max(a,b))) || ((*(a+i)) == (Min(a,b)))) m++;
    }
    return m;
}

void wsx(int* &a, int b)
{
    int r = qaz(a, b);
    int* edc = new int [b - r];
    int k = 0;

    for (int i = 0; i < b; i++)
    {
        if (((*(a + i)) != Max(a,b)) && ((*(a + i)) != Min(a,b)))
        {
            *(edc + k) = *(a + i);
            k++;
        }
    }

    a = edc;
}

int main()
{
    int n;
    cin >> n;
    int* rfv = new int [n];
    for (int i = 0; i < n; i++)
    {
        cin >> *(rfv + i);
    }

    int f = qaz(rfv, n);
    wsx(rfv, n);
    cout << endl;

    for (int i = 0; i < (n - f); i++)
    {
        cout << *(rfv+i) << " ";
    }

    delete[]rfv;
}
