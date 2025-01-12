#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<limits.h>
#include<queue>
using namespace std;
int n,m,v,e;

void checking(vector<int>visited, vector<vector<int>>gp){
    for(int i=1;i<=v;i++){
        for(int j=0;j<gp[i].size();j++){
            if(visited[i] == visited[gp[i][j]]){
                cout<<"NO\n";
                return ;
            }
        }
    }
    cout<<"YES\n";
    return ;
}

void bfs(vector<vector<int>>&gp, int start, vector<int>&visited){
    queue<int>q;
    visited[start] = 1;
    q.push(start);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i=0;i<gp[now].size();i++){
            if(visited[gp[now][i]] == 0){
                if(visited[now] == 1) visited[gp[now][i]] = 2;
                else if(visited[now] == 2) visited[gp[now][i]] = 1;
                q.push(gp[now][i]);
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin>>n;
    while(n--){
        cin>>v>>e;
        vector<vector<int>>gp(v+1);
        vector<int>visited(v+1,0);
        for(int i=0;i<e;i++){
            int q,w;
            cin>>q>>w;
            gp[q].push_back(w);
            gp[w].push_back(q);
        }
        for(int i=1;i<=v;i++){
            if(visited[i]==0){
                bfs(gp, i, visited);
            }
        }
        checking(visited, gp);
    }
}
