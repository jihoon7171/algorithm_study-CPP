#include<vector>
#include<iostream>
#include<queue>
#include<set>
#include<string>
#include<algorithm>
using namespace std;
vector<vector<int>>sns(1000001);
vector<vector<int>>dp;
int n;
vector<bool>visited;

void dfs(int now){
    visited[now] = true;
    dp[now][0] = 1;
    dp[now][1] = 0;
    for(int i=0;i<sns[now].size();i++){
        if(visited[sns[now][i]]){
            continue;
        }
        int next = sns[now][i];
        dfs(next);
        dp[now][0] += min(dp[next][0], dp[next][1]);
        dp[now][1] += dp[next][0];
    }
}

int main(){
    cin >> n;
    dp.resize(n+1,vector<int>(2,-1));
    visited.resize(n+1, false);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        sns[u].push_back(v);
        sns[v].push_back(u);
    }
    dfs(1);
    cout<<min(dp[1][0], dp[1][1]);
} 