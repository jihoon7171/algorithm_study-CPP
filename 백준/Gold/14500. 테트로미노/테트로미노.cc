#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n, m;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int maxans = INT_MIN;

void dfs(int x, int y, int cnt, int sum, vector<vector<int>>& paper, vector<vector<bool>>& checked) {
    if (cnt == 4) {
        maxans = max(maxans, sum); // max 함수 사용
        return;
    }
    for (int i = 0; i < 4; i++) {
        int newx = x + dx[i];
        int newy = y + dy[i];
        if (newx < 0 || newx >= m || newy < 0 || newy >= n) continue;
        if (checked[newy][newx]) continue;

        checked[newy][newx] = true;
        dfs(newx, newy, cnt + 1, sum + paper[newy][newx], paper, checked);
        checked[newy][newx] = false; // 상태 복구
    }
}

void checkShape(int x, int y, vector<vector<int>>& paper) {
    int temp;

    // 각 모양 조합을 체크
    if (x + 1 < m && x - 1 >= 0 && y - 1 >= 0) {
        temp = paper[y][x] + paper[y][x + 1] + paper[y][x - 1] + paper[y - 1][x];
        maxans = max(maxans, temp);
    }
    if (x + 1 < m && x - 1 >= 0 && y + 1 < n) {
        temp = paper[y][x] + paper[y][x + 1] + paper[y][x - 1] + paper[y + 1][x];
        maxans = max(maxans, temp);
    }
    if (x + 1 < m && y + 1 < n && y - 1 >= 0) {
        temp = paper[y][x] + paper[y][x + 1] + paper[y + 1][x] + paper[y - 1][x];
        maxans = max(maxans, temp);
    }
    if (x - 1 >= 0 && y + 1 < n && y - 1 >= 0) {
        temp = paper[y][x] + paper[y][x - 1] + paper[y + 1][x] + paper[y - 1][x];
        maxans = max(maxans, temp);
    }
}

int main() {
    cin >> n >> m;
    vector<vector<int>> paper(n, vector<int>(m));
    vector<vector<bool>> checked(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> paper[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            checked[i][j] = true; // 현재 위치 체크
            dfs(j, i, 1, paper[i][j], paper, checked);
            checkShape(j, i, paper);
            checked[i][j] = false; // 체크 해제
        }
    }

    cout << maxans;
    return 0;
}
