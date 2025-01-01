#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int a, b;
vector<char> pass;
set<string> answer;

void dfs(int count, vector<char>& ans, int index) {
    if (count == a) {
        int mcount = 0; // 모음 개수
        int jcount = 0; // 자음 개수

        for (int i = 0; i < a; i++) {
            if (ans[i] == 'i' || ans[i] == 'o' || ans[i] == 'a' || ans[i] == 'u' || ans[i] == 'e') {
                mcount++;
            } else {
                jcount++;
            }
        }

        bool checking = true;
        for (int i = 0; i < a - 1; i++) {
            if (ans[i] > ans[i + 1]) {
                checking = false;
                break;
            }
        }

        if (mcount >= 1 && jcount >= 2 && checking) {
            string temp(ans.begin(), ans.end());
            answer.insert(temp);
        }
        return;
    }

    for (int i = index; i < b; i++) {
        ans[count] = pass[i];
        dfs(count + 1, ans, i + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a >> b;
    pass.resize(b);
    for (int i = 0; i < b; i++) {
        cin >> pass[i];
    }

    vector<char> ans(a);
    sort(pass.begin(), pass.end());
    dfs(0, ans, 0);

    for (const string& temp : answer) {
        cout << temp << "\n";
    }

    return 0;
}