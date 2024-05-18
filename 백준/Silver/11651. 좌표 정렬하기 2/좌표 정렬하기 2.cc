#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int main() {
	int n,x,y;
	cin >> n;
	vector<pair<int, int>>a;

	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		a.push_back({ y,x });
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		cout << a[i].second << " " << a[i].first<<"\n";
	}



}