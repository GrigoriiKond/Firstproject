/* В цивилизованных странах на железнодорожном вокзале работают k касс, однако очередь в них всего одна. Обслуживание происходит следующим образом. Изначально, когда все кассы свободны, первые k человек из очереди подходят к кассам. Остальные ждут своей очереди. Как только кто-нибудь будет обслужен и соответствующая касса освободится, следующий человек из очереди подходит к этой кассе. Так продолжается до тех пор, пока не будут обслужены все клиенты. */
 
#include <iostream>
#include<cmath>
using namespace std;

int work(int k, int people) {
	int* A = new int[k];
	cout << "Type time of each cashbox:" << endl;
	for (int i = 0; i < k; i++) // время обслуживания каждой кассы
		cin >> A[i];

	int Sum = 0, j = 0;
	for (int i = 0; i < k; i++) {
		Sum += A[i];
		j++;
	}
	double TIME = Sum / j;
	double sum_people = 0;
	for (int i = 0; i < k; i++) {
		sum_people += TIME / A[i];
	}
	double people_per_time = sum_people / TIME;

	return ceil(people / people_per_time);

}

int main()
{
	int people, k;
	double time;
	cout << "Type the count of cashboxes and people:" << endl;
	cin >> k >> people;

	time = work(k, people);
	cout << time;
	return 0;
}
