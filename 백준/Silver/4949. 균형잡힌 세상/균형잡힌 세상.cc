#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    while (true) {
        string a;
        getline(cin, a);
        
        if (a == ".") {
            break;
        }

        stack<char> right;
        bool okay = true;

        for (int i = 0; i < a.size(); i++) {
            if (a[i] == '(' || a[i] == '[') {
                right.push(a[i]);
            } else if (a[i] == ')') {
                if (!right.empty() && right.top() == '(') {
                    right.pop();
                } else {
                    okay = false;
                    break;
                }
            } else if (a[i] == ']') {
                if (!right.empty() && right.top() == '[') {
                    right.pop();
                } else {
                    okay = false;
                    break;
                }
            }
        }

        if (okay && right.empty()) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return 0;
}
