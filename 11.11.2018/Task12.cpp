/* Напишите процедуру, дописывающую к каждому элементу динамически выделенного массива справа его квадрат.
({1,2,3,4}->{1,1,2,4,3,9,4,16}). По окончании работы процедуры количество выделенной памяти должно увеличиться. */

#include <iostream>
using namespace std;

int sqrt (int i)
{
    return i*i;
}

void first (int* &a, int b)
{
    int* second = new int [b];
    for (int i = 0; i < b; i++)
    {
        *(second+ i) = sqrt(*(a + i));
    }

    int c = 2*b;
    int* third = new int[c];
    for (int i = 0; i < c; i++)
    {
        if ((i % 2) == 0)
        {
            *(third + i) = *(a + (i/2));
        }
        else
        {
            *(third + i) = *(second + ((i-1)/2));
        }
    }

    delete[]second;

    a = third;
}

int main()
{
    int p;
    cin >> p;
    int* fourth= new int [n];
    for (int i = 0; i < p; i++)
    {
        cin >> *(fourth + i);
    }

    first(fourth, p);
    p += p;

    for (int i = 0; i < p; i++)
    {
        cout << *(fourth + i) << " ";
    }
}
