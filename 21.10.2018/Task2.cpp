/* Реализуйте структуру IpAddress для работы с IPv4 адресацией.
Структура должна хранить информацию об IP и маске, а также уметь вычислять адрес подсети, номер компьютера в сети, 
следующий/предыдущий адрес. 
В программе должно присутствовать описание структуры и программа показывающая работоспособность структуры.
Комментарий 1. Структура должна уметь работать с битовой арифметикой и сравнениями.
С помощью структуры должна быть возможность создавать пользовательские функции.
В структуре должна быть возможность выписывания адресов в бинарном, десятичном и шестнадцатеричном виде.
Комментарий 2. Программа должна содержать использование ВСЕХ методов. */

#include "pch.h" 
#include <iostream> 
#include <cmath>

using namespace std; 

struct IpAdress { 
unsigned short int IP[4], MASK[4]{0,0,0,0},mask_prefiks =33; 
IpAdress(unsigned short int mask_prefiks = 33) { 
if (mask_prefiks == 33) cin » mask_prefiks; 
this->mask_prefiks = mask_prefiks; 
for (int i = 1, k = 0; i <= mask_prefiks; i++) { 
MASK[k] += pow(2, 7 - i % 8); 
if (i % 8 == 0) k++; 
} 
for (int i = 0; i < 4; i++) cin » IP[i]; 
} 
IpAdress(IpAdress& a) { 
mask_prefiks = a.mask_prefiks; 
for (int i = 0; i < 4; i++) { 
IP[i] = a.IP[i]; 
MASK[i] = a.MASK[i]; 
} 

} 
void IP_User() { 
cout « "User address: "; 
for (int i = 0; i < 4; i++) { 
cout « IP[i]; 
if (i != 3) cout « '.'; 
} 
cout « endl; 
} 
void IP_network() { 
cout « "Subnet address: "; 
for (int i = 0; i < 4; i++) { 
cout « (IP[i] & MASK[i]); 
if (i != 3) cout « '.'; 
} 
cout « endl; 
} 
void Number() { 
cout « "Computer number: "; 
unsigned int ipcopy = 0, maskcopy = 0; 
for (int i = 0; i < 4; i++) { 
ipcopy += IP[i] « 8 * (3-i); 
maskcopy += MASK[i] « 8 * (3 - i); 
} 
cout « (ipcopy & ~(maskcopy)) « endl; 
} 
void Next() { 
unsigned short IP_NEXT[4], residue = 1; 
cout « "Next network address: "; 
for (int i = 3; i >= 0; i--) { 
if (MASK[i] == 0) { 
IP_NEXT[i] = 0; 
residue = 1; 
} 
else if (IP[i] == 255) { 
IP_NEXT[i] = 0; 
residue = 1; 
} 
else { 
IP_NEXT[i] = IP[i] + residue; 
residue = 0; 
} 

} 
if (mask_prefiks != 0) { 
for (int i = 0; i < 4; i++) { 
cout « IP_NEXT[i]; 
if (i != 3) cout « '.'; 
} 
} 
else cout « '-'; 
cout « endl; 
} 
void Prev() { 
unsigned short IP_PREV[4], residue = 1; 
cout « "Previous network address: "; 
for (int i = 3; i >= 0; i--) { 
if (MASK[i] == 0) { 
IP_PREV[i] = 0; 
residue = 1; 
} 
else if (IP[i] == 0) { 
IP_PREV[i] = 255; 
residue = 1; 
} 
else { 
IP_PREV[i] = IP[i] - residue; 
residue = 0; 
} 

} 
if (mask_prefiks != 0) { 
for (int i = 0; i < 4; i++) { 
cout « IP_PREV[i]; 
if (i != 3) cout « '.'; 
} 
} 
else cout « '-'; 
cout « endl; 
} 
}; 

const bool& operator == (const IpAdress& a, const IpAdress& b) { 
for (int i = 0; i < 4; i++) { 
if (a.IP[i] != b.IP[i]) return false; 
} 
if (b.mask_prefiks == a.mask_prefiks) return true; 
else return false; 
} 

int main() 
{ 
IpAdress a; 
a.IP_User(); 
a.IP_network(); 
a.Number(); 
a.Next(); 
a.Prev(); 
IpAdress b; 
b.IP_User(); 
b.IP_network(); 
b.Number(); 
b.Next(); 
b.Prev(); 
if (a == b) cout « "Address (a) and (b) are equal " « endl; 

system("pause"); 
return 0; 
}
