/* Напишите логическую функцию, проверяющую, является ли одна строка анаграммой другой строки 
(т.е. может быть получена перестановкой букв). Можно считать, что строка состоит только из букв латиницы. */

#include <iostream>
using namespace std;

int size(char* a)
{
	int p = 0;
	while(*a++)
	{
		p++;
	}
	return p;
}

bool agr(char* a, int b, char* c, int d)
{
	if (b != d) {
		
		return false;
	  
		} else {
		
		for (int i = 0; i < b; i++) {
			int u = 0;
			for (int j = 0; j < d; j++) {
				if (*(a + i) == *(c + j)) {
					int k = j, h = 0;
					char* nwm= new char [d - 1];
					while (h < (d - 1))
					{
					 for (j = 0; j < d; j++) {
					  if (j != k) {
					  *(nwm+ h) = *(c + j);
					  h++;
					  }
					  }
					}
					c = nwm;
					u++;
				}
			}
			if (u == 0)
			{
				return false;
				break;
			}
		}
		return true;
	}

}

int main()
{
	int a, b;

	char* vn = new char [256];
	cin.getline(vn, 256, '\n');
	a = size(vn);

	char* kn = new char [256];
	cin.getline(kn, 256, '\n');
	b = size(kn);

	cout << '\n';

	if (agr(vn, a, kn, b) == 1)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}
  return 0;
}
