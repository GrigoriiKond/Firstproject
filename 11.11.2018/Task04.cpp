/* Напишите программу, находящую сумму простых элементов массива. */

#include <iostream>
using namespace std;

int main() {

int sum = 0;
bool Z;
unsigned int N;


cout << "Amount of elements in the array: ";

cin >> N;

int A[N];

  for (int a = 0; a < N; a++) {
      
 /* if (a == 0) cout << "1-st element:" << endl;
    if (a == 1) cout <<  "2-nd element:" << endl;
    if (a == 2) cout << "3-rd element:" << endl;
    if (a > 2) cout << a+1<< "-th element:" << endl; */
                
                cout << "A["<< a << "] = ";
                cin >> A[a]; cout << endl;
                
 }
   
   for (int b = 0; b < N; b++) {
       
        if (A[b] > 1) {
        
        for (int c = 2; c < A[b]; c++) {

	      if (A[b] % c == 0) Z = 1;
       
         }

        if (Z != 1) sum += A[b];
        
        Z = 0;  
        
        }
        
        }
            

cout << "Sum of simple elements in the array: " << sum;

return 0;

}
