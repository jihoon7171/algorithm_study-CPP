#include<iostream>
using namespace std;

int main() {
	int a, b,c,d=0,e=0;
	cin >> a >> b;
	cin >> c;
	
	d = b + c;
	while (d >= 60) {
		d = d - 60;
		a++;
}

	if (a >= 24) {
		a = a - 24;
	}

	cout << a<<" "<< d;

}