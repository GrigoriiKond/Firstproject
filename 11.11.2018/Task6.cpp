/* Напишите программу, выписывающую все элементы последовательности, имеющие не менее пяти делителей */

#include <iostream>
using namespace std;

int main()
{
 int n;
 cin >> n;
 int *zxc = new int[n];

 for (int i = 0; i < n; i++)
 {
  int k = 0;
  cin >> *(zxc + i);

  int q = *(zxc + i);
  for (int j = 1; j <= *(zxc + i); j++)
  {
   if  ((q % j) == 0) k += 1;
  }
  if (k >= 5) cout << *(zxc + i) << " ";
 }
 return 0;
}
