#include <iostream>
#include <vector>
#include<climits>
#include <algorithm>
using namespace std;

int n, m, k;
vector<vector<int>> arr;
struct src {
    int s;
    int r;
    int c;
};

int result = INT_MAX;
vector<src> input_src;

// 시계 방향 회전
vector<vector<int>> rotate(int depth, int sx, int sy, int ex, int ey, vector<vector<int>> now_temp) {
    vector<vector<int>> temp = now_temp;

    for (int layer = 0; layer < depth; layer++) {
        int csx = sx + layer, csy = sy + layer;
        int cex = ex - layer, cey = ey - layer;

        // 위쪽
        for (int j = csy; j < cey; j++)
            temp[csx][j + 1] = now_temp[csx][j];

        // 오른쪽
        for (int i = csx; i < cex; i++)
            temp[i + 1][cey] = now_temp[i][cey];

        // 아래쪽
        for (int j = cey; j > csy; j--)
            temp[cex][j - 1] = now_temp[cex][j];

        // 왼쪽
        for (int i = cex; i > csx; i--)
            temp[i - 1][csy] = now_temp[i][csy];
    }

    return temp;
}

void cal(vector<vector<int>>& now_arr) {
    for (int i = 0; i < n; i++) {
        int temp = 0;
        for (int j = 0; j < m; j++) {
            temp += now_arr[i][j];
        }
        result = min(result, temp);
    }
}

void run(vector<bool> checking, int count, vector<vector<int>> now_arr) {
    if (count == k) {
        cal(now_arr);
        return;
    }

    for (int i = 0; i < checking.size(); i++) {
        if (!checking[i]) {
            checking[i] = true;

            int s = input_src[i].s;
            int r = input_src[i].r - 1;
            int c = input_src[i].c - 1;
            int sr = r - s;
            int sc = c - s;
            int er = r + s;
            int ec = c + s;

            run(checking, count + 1, rotate(s, sr, sc, er, ec, now_arr));
            checking[i] = false;
        }
    }
}

int main() {
    cin >> n >> m >> k;
    arr.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    input_src.resize(k);
    for (int i = 0; i < k; i++) {
        int r, c, s;
        cin >> r >> c >> s;
        input_src[i] = {s, r, c};
    }

    vector<bool> checking(k);
    run(checking, 0, arr);
    cout << result << '\n';
}