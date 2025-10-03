#include <iostream>
#include<queue>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
#include<set>
using namespace std;
vector<vector<int>>v;
int n;
vector<int>ans;
vector<int>visited;
void dfs(int now){
    visited[now] = true;
    for(int i=0;i<v[now].size();i++){
        if(!visited[v[now][i]]){
            ans[v[now][i]] = now;
            dfs(v[now][i]);
        }
    }
}
int main() {
    cin>>n;
    visited.resize(n+1);
    ans.resize(n+1);
    v.resize(n+1);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    for(int i=2;i<=n;i++){
        cout<<ans[i]<<"\n";
    }




}
