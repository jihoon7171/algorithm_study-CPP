#include <iostream>
#include <vector>
#include <algorithm>
#include<climits>
#include<queue>
#include<tuple>
#include<string>
using namespace std;
int n,m;
vector<vector<int>>f;
vector<bool>visited;
bool flag = false;
void dfs(int count,int now){
    if(flag) return;
    if(count == 4){
        flag = true;
        return ;
    }
    visited[now] = true;
    for(int next : f[now]){
        if(!visited[next]){
            dfs(count+1, next);
        }
    }
    visited[now]=false;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    f.resize(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        f[a].push_back(b);
        f[b].push_back(a);
    }
    //vector<vector<bool>>visited(n, vector<bool>(n));
    visited.resize(n);
    for(int i=0;i<n;i++){
        dfs(0,i);
    }
    if(flag){
        cout<<1;
    }else{
        cout<<0;
    }



}
