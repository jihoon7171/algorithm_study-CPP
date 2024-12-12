#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<long long>> board;
pair<int, int> go[2] = {{1, 0}, {0, 1}}; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    board.resize(n, vector<long long>(n));
    vector<vector<long long>> dp(n, vector<long long>(n, 0)); // DP 테이블 초기화 (0으로)


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }


    dp[n - 1][n - 1] = 1;


    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (board[i][j] == 0) continue; 

            for (int k = 0; k < 2; k++) {
                int newx = j + board[i][j] * go[k].first;
                int newy = i + board[i][j] * go[k].second;
                if (newx >= 0 && newx < n && newy >= 0 && newy < n) {
                    dp[i][j] += dp[newy][newx];
                }
            }
        }
    }



    cout << dp[0][0] << "\n";

    return 0;
}