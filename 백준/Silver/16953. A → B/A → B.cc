#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    int count = 0;

    while (b != a) {
        if (b.empty()) {
            cout << "-1" << endl;
            return 0;
        }

        if (b.back() == '1') {
            b.pop_back();
            count++;
        } else {
            try {
                long long temp = stoll(b);
                if (temp % 2 != 0) {
                    cout << "-1" << endl;
                    return 0;
                }
                temp /= 2;
                b = to_string(temp);
                count++;
            } catch (...) {
                cout << "-1" << endl;
                return 0;
            } 
        }
    }

    cout << count + 1 << endl;
    return 0;
}
