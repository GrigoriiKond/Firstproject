/* Реализуйте вычисление значения полинома в точке посредством схемы Горнера */

#include <iostream>
using namespace std;

int main()
{
    int z, o;
    cin >> z;
int n;
cin >> n;
int* was = new int[n + 1];
for(int i=0; i<=n; i++){
cin >> was[i];
}
o = was[0];
for(int i = 1; i<=n; i++){
    o = o*z + was[i];
}
cout << o;
return 0;
}
