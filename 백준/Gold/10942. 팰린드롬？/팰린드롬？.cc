#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<queue>
#include<climits>
#include<string>
using namespace std;
vector<vector<int>>dp;
vector<int>num;
int n,m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    num.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    dp.resize(n+1, vector<int>(n+1));
    for (int i = 1; i <= n; i++) dp[i][i] = 1;
    for (int i = 1; i < n; i++) if (num[i] == num[i+1]) dp[i][i+1] = 1;
    for (int len = 3; len <= n; len++) {
        for (int s = 1; s + len - 1 <= n; s++) {
            int e = s + len - 1;
            if (num[s] == num[e] && dp[s+1][e-1]) dp[s][e] = 1;
        }
    }
    cin>>m;
    for(int i=0;i<m;i++){
        int s,e;
        cin>>s>>e;
        cout<<dp[s][e]<<"\n";
    }


}


