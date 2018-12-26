/* Напишите программу позволяющую эффективно проверять принадлежность пары значений массиву. 
Например, пара (2,3) принадлежит массиву [1,2,3,5,7,11,13,17], а пара (3,4) - нет. 
Можно считать, что количество запросов многократно превышает размер массива */

#include <iostream>
#include <vector>
using namespace  std; 

int main() 
{ 
  int z, s = 0; 
  cin >> z; 
  vector <int> it(z); 
  int p, q; 



  for(int i = 0; i < z; i++) 
  cin >> it[i]; 

  cin >> p >> q; 

  for(int j = 0; j < z; j++) 
  { 
    if(it[j] == p) 
    { 
      s++; 
      break; 
    } 
  } 

  for(int m = 0; m < z; m++) 
  { 
    if(it[m] == p) 
    { 
      s++; 
      break; 
    } 
  } 

  if(s == 2) 
    cout << "yes!"; 

  else 
    cout << "no!"; 

  return 0; 
}
