/* Напишите программу, выписывающую все элементы последовательности, имеющие не менее пяти делителей */

#include <iostream>
using namespace std;

int main()
{
 int n;
 cin >> n;
 int *qwa = new int[n];

 for (int i = 0; i < n; i++)
 {
  int k = 0;
  cin >> *(qwa + i);

  int q = *(qwa + i);
  for (int j = 1; j <= *(qwa + i); j++)
  {
   if  ((q % j) == 0) k += 1;
  }
  if (k >= 5) cout << *(qwa + i) << " ";
 }
 return 0;
}
