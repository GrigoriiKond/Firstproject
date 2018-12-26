/* Напишите программу, находящую в массиве такой элемент, что равные ему составляют в массиве - большинство. Если такого элемента нет - выведите “NO” */

#include <iostream>
using namespace std;
int main() {
	
	int hu;
	cin >> hu;
	int * Qwe = new int[hu];
	bool * Asd = new bool[hu];
	int * Zxc = new int[hu];
	for (int i = 0; i < hu; i++) {
		cin >> Qwe[i];
		Asd[i] = 1;
		Zxc[i] = 0;
	}
	for (int j = 0; j < hu; j++) {
		if (Asd[j] != 0) {
			Zxc[j]++;
			for (int i = j + 1; i < hu; i++) {
				if(Asd[i] != 0)
				if (Qwe[j] == Qwe[i])  {
				Asd[i] = 0;
			  Zxc[j]++;
				}
			}
		}
	}
	
	int t = 0, q, p = 1;
	for (int i = 0; i < hu; i++) {
		if (Asd[i] != 0)  {
			if (t < Zxc[i]) {
				t = Zxc[i];
				q = Qwe[i];
			  }
		    }
		if (Qwe[i] == 0) p++;
	}
	if(p == hu)
		cout << "NO ";
	else
		cout << q;

 return 0;
}
