/* Напишите эффективную процедуру, выписывающую из массива длины n все элементы,
у которых произведение ненулевых цифр больше k. */

#include <iostream>
using namespace std;

void pr (int* a, int b, int c)
{
    for (int i = 0; i < b; i++)
    {
        int we = a[i], j = 1;

        while (a[i] >= 1)
        {
           if ((a[i] % 10) != 0) j *= (a[i] % 10);
           if (j > c)
           {
                cout << we << " ";
                break;
           }
            *(a + i) /= 10;
        }
    }
}

int main()
{
    int A, B;
    
    cout << "Enter n(size of array): " << endl;
    cin >> A;
    cout << "Enter numbers of array: " << endl;

    int* sd = new int [A];
    
    for(int i = 0; i < A; i++)
    {
        cin >> *(sd + i);
    }

    cout << "Enter k:" << endl;
    cin >> B;
    
    cout << "Result elements:" << endl;
    pr(sd, A, B);
    
    return 0;
}
