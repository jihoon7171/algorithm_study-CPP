#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a;
    cin >> a; 
    vector<int> num(a);
    int maxN = 0;
    for (int i = 0; i < a; i++) {
        cin >> num[i];
        maxN = max(maxN, num[i]); 
    }

    vector<vector<int>> dp(maxN + 1, vector<int>(4, 0));
    dp[1][1] = 1;
    dp[2][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;

    for (int i = 4; i <= maxN; i++) {
        dp[i][1] = dp[i - 1][1]; 
        dp[i][2] = dp[i - 2][1] + dp[i - 2][2]; 
        dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3]; 
    }

    for (int i = 0; i < a; i++) {
        int sum = dp[num[i]][1] + dp[num[i]][2] + dp[num[i]][3];
        cout << sum << "\n";
    }

    return 0;
}