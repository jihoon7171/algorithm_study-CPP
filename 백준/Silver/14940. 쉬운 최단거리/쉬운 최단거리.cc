#include <iostream>
#include <vector>
#include<algorithm>
#include<unordered_set>
#include<queue>
#include<cstring>
using namespace std;
int n,m;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
pair<int, int>start;
void bfs(vector<vector<int>>&maze){
    vector<vector<int>>dist(n, vector<int>(m,-1));
    queue<pair<int, int>>q;
    dist[start.first][start.second]=0;
    q.push(start);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(maze[i][j] == 0){
                dist[i][j] =0;
            }
        }
    }
    while(!q.empty()){
        int nowx = q.front().second;
        int nowy = q.front().first;
        q.pop();
        for(int i=0;i<4;i++){
            int newx = nowx+dx[i];
            int newy = nowy+dy[i];
            if(newx>=0&&newx<m&&newy>=0&&newy<n&&maze[newy][newx]==1&&dist[newy][newx]==-1){
                dist[newy][newx]= dist[nowy][nowx]+1;
                q.push({newy,newx});
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(maze[i][j] == 1 && dist[i][j] == -1){
                dist[i][j] =-1;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<"\n";
    }

}

int main() {
    cin>>n>>m;
    vector<vector<int>>maze(n,vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>maze[i][j];
            if(maze[i][j] == 2){
                start = {i,j};
            }
        }
    }
    bfs(maze);

} 
