/* Напишите программу переводящую число в систему счисления с основанием k, где k не превышает 30. */

#include <iostream>
using namespace std;

int main() {

	int n, k;
	cin >> n >> k;
	int *Az= new int[10];
	char B[26];
	int *Sx= new int[10];

	for (int i = 0; i < 10; i++) {
		Az[i] = -1;
	}

	for (char i = 'a';i <= 'z';++i) {
		Sx[i - 'a'] = i;
	}


	if (k > 10) {
		for (int i = 9;n > k; i--) {
			if (n % k >= 10) {
				Az[i] = -2;
				Sx[i] = n;
			}
			else
				Az[i] = n % k;
			n /= k;
		}

		Az[0] = n;
		for (int i = 0; i < 10; i++) {
			if (Az[i] != -1)
				if (Az[i] == -2) {
					cout << Az[Sx[i] % k - 10];
				}
				else
					cout << Az[i];
		}
	}

	else {
		for (int i = 9; n >= k; i--) {
			Az[i] = n % k;
			n /= k;
		}
	Az[0] = n;
	for (int i = 0; i < 10; i++) {
		if (Az[i] != -1)
			cout << Az[i];
	}
  }
	
	return 0;
}
