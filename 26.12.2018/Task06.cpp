/* Реализуйте метод секущих вычисления корня уравнения. */

#include <iostream>
using namespace std;

float fun(float x){
    return (x + 2)*(x + 2)*(x + 2) - 5;
}
int main()
{
float a,b,c,e;
cin>>e;
if(fun(0) < 0){
        int i = 20;
    while(fun(i) < 0){
        i+=20;
    }
   a = i;
}
if(fun(0) > 0){
        int i = -20;
    while(fun(i) > 0){
        i-=20;
    }
   a = i;
}
if(fun(0) < 0){
    b = 0;
}
if(fun(0) > 0){
    b = a;
    a = 0;
}
c = (a - ((b - a)*fun(a)/(fun(b) - fun(a))));
while( (b - a)*(b - a) > e*e){
        a = b;
b = c;
    c = a - ((b - a)*fun(a)/(fun(b) - fun(a)));
}
cout << b << " " << a;

return 0;
}
