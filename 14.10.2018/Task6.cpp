/*
Напишите функцию sort упорядывающую массив целых чисел и программу с
примером её использования. В коде запрещается использовать обращения к
массиву по индексу( Arr[i] ), т.е. нужно использовать указательную арифметику.
Эффективность в данной программе не приоритетна. Количество аргументов
функции не должно превышать 2.
*/
#include <iostream>

using namespace std;

void swap(int& a, int& b)
{
    int t = a;
    a = b;
    b = t;
}

void sort(int *array, int arraySize)
{
    int *end = array + arraySize;
    for (int *i = array; i != end; i++)
    {
        for (int *j = i; j != end; j++)
        {
            if (*i > *j)
            {
                swap(*i, *j);
            };
        };
    };
};
int main() {
    int arraySize;
    cin >> arraySize;
    int *array = new int[arraySize];
    for (int i = 0; i < arraySize; i++)
    {
        cin >> *(array + i);
    };
    sort(array, arraySize);
    for (int i = 0; i < arraySize; i++)
    {
        cout << *(array + i) << " ";
    };
    return 0;
}
