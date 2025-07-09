#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<vector<char>> space;
int r, c;
int answer = INT_MIN;

void run(int x, int y, int counting, vector<bool>& check) {
    answer = max(answer, counting);

    for (int i = 0; i < 4; i++) {
        int newx = x + dx[i];
        int newy = y + dy[i];
        if (newx >= 0 && newx < c && newy >= 0 && newy < r) {
            int idx = space[newy][newx] - 'A';
            if (!check[idx]) {
                check[idx] = true;
                run(newx, newy, counting + 1, check);
                check[idx] = false;
            }
        }
    }
}

int main() {
    cin >> r >> c;
    space.resize(r, vector<char>(c));
    for (int i = 0; i < r; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < c; j++) {
            space[i][j] = temp[j];
        }
    }

    vector<bool> check(26);
    check[space[0][0] - 'A'] = true;
    run(0, 0, 1, check);
    cout << answer << '\n';
}