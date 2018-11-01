
#include <iostream>
using namespace std;

int main()
{
 int n;
 cin >> n;
 int *yk = new int[n];

 for (int i = 0; i < n; i++)
 {
  int k = 0;
  cin >> *(yk + i);

  int q = *(yk + i);
  for (int j = 1; j <= *(yk + i); j++) if  ((q % j) == 0) k += 1;
 
  if (k == 7) cout << *(yk + i) << " ";
 
  }
 return 0;
}
