#include <iostream>
#include <vector>
#include<algorithm>
#include<unordered_set>
#include<queue>
#include<cstring>
using namespace std;

int minimum(int a, int b, int c, vector<int>&ranking){
ranking[0] = min({a, b, c});  
ranking[1] = a + b + c - ranking[0] - max({a, b, c});
ranking[2] = max({a, b, c});
return ranking[0];

}

int main() {
    int a;
    cin>>a;
    vector<vector<int>>color(a+1, vector<int>(3));

    vector<vector<int>>dp(a+1, vector<int>(3));
    for(int i=1;i<=a;i++){
        for(int j=0;j<3;j++){
            cin>>color[i][j];
        }
    } 
    for(int i=0;i<3;i++){
        dp[1][i] = color[1][i];
    }

    for(int i=2;i<=a;i++){
        dp[i][0] = color[i][0]+ min(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = color[i][1]+min(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = color[i][2]+min(dp[i-1][0], dp[i-1][1]);
    }
    cout<<min({dp[a][0], dp[a][1], dp[a][2]});
}

