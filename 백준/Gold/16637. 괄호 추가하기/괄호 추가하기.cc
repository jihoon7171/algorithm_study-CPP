#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>
using namespace std;

int a;
int cal(int a, int b, char c) {
    if (c == '+') return a + b;
    if (c == '*') return a * b;
    if (c == '-') return a - b;
    return 0;
}

vector<char> fom;
int answer;

void dfs(int index, int result) {
    if (index >= a ) {
        answer = max(answer, result);
        return;
    }

    // 괄호를 추가하는 경우
    if (index + 2 < a) {
        int circle = cal(fom[index] - '0', fom[index + 2] - '0', fom[index + 1]);
        dfs(index + 4, cal(result, circle, fom[index - 1]));
    }
    dfs(index + 2, cal(result, fom[index] - '0', fom[index - 1]));
}

int main() {
    cin >> a;
    fom.resize(a);
    string temp;
    cin >> temp;
    for (int i = 0; i < a; i++) {
        fom[i] = temp[i];
    }

    answer = INT_MIN;
    dfs(2, fom[0]-'0');
    cout << answer;

    return 0;
}