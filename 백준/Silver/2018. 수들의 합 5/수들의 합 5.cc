#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int sumplus(int n) {
	int result = 0;
	for (int i = 0; i <= n; i++) {
		result += i;
	}
	return result;
}



int main() {
	int a, cnt = 0, box = 1,qw=0;
	cin >> a;
	while (qw <= a) {
		qw = sumplus(box);
		if (((a - qw) % box == 0)||a==qw) {
			cnt++;
		}

		box++;
		qw = sumplus(box);
	}

	cout << cnt;


}