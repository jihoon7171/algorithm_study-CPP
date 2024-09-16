#include <iostream>
#include <vector>
#include<algorithm>
#include<unordered_set>
#include<queue>
using namespace std;
int n,m;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
void bfs(int x, int y, vector<vector<int>>&maze){
    vector<vector<int>>dist(n,vector<int>(m,-1));
    dist[y][x] = 1;
    queue<pair<int, int>>q;
    q.push({y,x});
    while(!q.empty()){
        int nowy = q.front().first;
        int nowx = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int newx = nowx+dx[i];
            int newy = nowy+dy[i];
            if(newx>=0&&newx<m&&newy>=0&&newy<n&&dist[newy][newx]==-1&&maze[newy][newx]==1){
                dist[newy][newx] = dist[nowy][nowx]+1;
                q.push({newy, newx});
            }
        }
    }
    cout<<dist[n-1][m-1];


}
 

int main() {
    int count=0;
    cin>>n>>m;
    vector<vector<int>>maze(n,vector<int>(m));
    for(int i=0;i<n;i++){
        string temp;
        cin>>temp;
        for(int j=0;j<temp.size();j++){
            maze[i][j] = temp[j]-'0';
        }
    }
    bfs(0,0,maze);
}
