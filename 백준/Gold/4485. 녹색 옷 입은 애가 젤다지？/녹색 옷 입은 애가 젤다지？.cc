#include <iostream>
#include <vector>
#include <climits>
#include<queue>
#include <string>
#include <algorithm>
#include<stack>
#include<limits.h>
using namespace std;
int n;
int result;
vector<vector<int>>visited;
vector<vector<int>>map;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
void bfs(){
    queue<pair<int, int>>q;
    q.push({0,0});
    while(!q.empty()){
        int nowx = q.front().first;
        int nowy = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int newx = nowx+dx[i];
            int newy = nowy+dy[i];
            if(newx>=0&&newx<n&&newy>=0&&newy<n){
                if(visited[newy][newx]>visited[nowy][nowx]+map[newy][newx]){
                    visited[newy][newx] = visited[nowy][nowx]+map[newy][newx];
                    q.push({newx, newy});
                }
            }
        }
    }
    result = visited[n-1][n-1];
    
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int count=1;
    while(1){
        cin>>n;
        if(n == 0){
            break;
        }
        visited.clear();
        visited.resize(n, vector<int>(n,INT_MAX));
        map.clear();
        map.resize(n, vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>map[i][j];
            }
        }
        result = INT_MAX;
        visited[0][0] = map[0][0];
        bfs();
        cout<<"Problem "<<count<<": "<<result<<"\n";
        count++;
    }
}