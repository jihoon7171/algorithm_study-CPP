#include <iostream>
#include <list>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string as;
    cin >> as;
    list<char> qw(as.begin(), as.end());
    
    int a;
    cin >> a;
    auto cursor = qw.end();
    
    while (a--) {
        char btn;
        cin >> btn;
        if (btn == 'L') {
            if (cursor != qw.begin()) {
                cursor--;
            }
        } else if (btn == 'D') {
            if (cursor != qw.end()) {
                cursor++;
            }
        } else if (btn == 'B') {
            if (cursor != qw.begin()) {
                cursor--;
                cursor = qw.erase(cursor);
            }
        } else if (btn == 'P') {
            char temp;
            cin >> temp;
            qw.insert(cursor, temp);
        }
    }
    
    for (char c : qw) {
        cout << c;
    }
    cout << '\n';

    return 0;
}
