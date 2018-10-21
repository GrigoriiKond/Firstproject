#include "pch.h" 
#include <iostream> 
#include <cmath>

using namespace std; 

int gcd(int a, int b) { 
if (a%b == 0) return b; 
return gcd(b, a % b); 
} 

struct rational { 
int ch; 
unsigned int zn; 
rational (int a = 0,int b = 1) { 
if (b < 0) { 
a = -a; 
b = -b; 
} 
ch = a / gcd(abs(a),b); 
zn = b / gcd (abs(a),b); 
} 

rational & operator += (rational &a) { 
ch = ch * a.zn + a.ch * zn; 
zn = a.zn * zn; 
int d = gcd(abs(ch), zn); 
ch /= d; 
zn /= d; 
return *this; 
}
rational & operator -= (rational &a) { 
ch = ch * a.zn - a.ch * zn; 
zn = a.zn * zn; 
int d = gcd(abs(ch), zn); 
ch /= d; 
zn /= d; 
return *this; 
} 
rational & operator *= (rational &a) { 
ch *= a.ch; 
zn *= a.zn; 
int d = gcd(abs(ch), zn); 
ch /= d; 
zn /= d; 
return *this; 
} 
rational & operator /= (rational &a) { 
int zncopy = a.zn, chcopy = a.ch; 
if (a.ch < 0) { 
chcopy = - chcopy; 
zncopy = -zncopy; 
} 
ch *= zncopy; 
zn *= chcopy; 
int d = gcd(abs(ch), zn); 
ch /= d; 
zn /= d; 
return *this; 
} 

rational operator = (const rational &b) { 
ch = b.ch; 
zn = b.zn; 
return *this; 
} 


}; 

rational& operator + (rational a,rational &b) { 
return a += b; 
} 
rational& operator - (rational a, rational& b) { 
return a -= b; 
} 
rational& operator * (rational a, rational &b) { 
return a *= b; 
} 
rational& operator / (rational a, rational& b) { 
return a /= b; 
} 

const bool & operator == (const rational& a, const rational& b) { 
return (a.ch * b.zn == a.zn * b.ch); 
} 
const bool & operator > (const rational& a, const rational& b) { 
return (a.ch + 0.0/ a.zn > b.ch +0.0 / b.zn); 
} 
const bool & operator < (const rational& a, const rational& b) { 
return (a.ch + 0.0 / a.zn < b.ch + 0.0/ b.zn); 
} 
const bool & operator >= (const rational& a, const rational& b) { 
return !(a < b); 
} 
const bool & operator <= (const rational& a, const rational& b) { 
return !(a>b); 
} 
const bool & operator != (const rational& a, const rational& b) { 
return !(a==b); 
} 
ostream & operator « (ostream &os,rational &b) { 
os « b.ch « '/' « b.zn; 
return os; 
} 
istream & operator » (istream &os, rational &b) { 
char slash = '0'; 
int znam1; 
os » b.ch; 
cin » slash; 
if (slash != '/') return os; 

os » znam1; 
b.zn = znam1; 

if (znam1 < 0) { 
b.ch = -b.ch; 
b.zn = -znam1; 
} 

int d = b.gcd(abs(b.ch), b.zn); 
b.ch /= d; 
b.zn /= d; 
return os; 
} 


void swap(rational& a, rational& b) { 
rational copy = a; 
a = b; 
b = copy; 
} 

int main() 
{ 
cout « "Enter 2 numbers in the format 'a/b'" « endl; 
rational a, b; 
cin » a » b; 
rational sum = a + b, raz = a - b, pr = a * b, cha = a / b, ARG = arg(a,b); 
cout « "First = " « a « endl; 
cout « "Second= " « b « endl; 
cout « "Amount= " « sum « endl; 
cout « "Difference = " « raz « endl; 
cout « "Work = " « pr « endl; 
cout « "Quotient= " « cha « endl; 
if (a>b) cout « "First more" « endl; 
else if (a < b) cout « "Second more" « endl; 
else if (a==b) cout « "Numbers are equal" « endl; 
swap(a, b); 
cout « "Example of a custom function swap(Changes values in a circle): First number=" « a « " Second number =" « b « endl; 

system("pause"); 
return 0; 
}
