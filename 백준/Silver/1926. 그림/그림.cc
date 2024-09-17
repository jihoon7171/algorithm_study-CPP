#include <iostream>
#include <vector>
#include<algorithm>
#include<unordered_set>
#include<queue>
using namespace std;
int n,m;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
queue<pair<int, int>>q;

int bfs(int y,int x, vector<vector<int>>&art, vector<vector<int>>&visited){
    int temp=1;
    queue<pair<int, int>>tq;
    visited[y][x] = 1;
    tq.push({y,x});
    while(!tq.empty()){
        int nowx = tq.front().second;
        int nowy = tq.front().first;
        tq.pop();
        for(int i=0;i<4;i++){
            int newx = nowx+dx[i];
            int newy = nowy+dy[i];
            if(newx>=0&&newx<m&&newy>=0&&newy<n&&visited[newy][newx]==0&&art[newy][newx]==1){
                visited[newy][newx]=1;
                temp++;
                tq.push({newy, newx});
            }
        }
    }
    return temp;
}

int main() {
    cin>>n>>m;
    int picture=0;
    vector<vector<int>>art(n, vector<int>(m));
vector<vector<int>>visited(n, vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>art[i][j];
            if(art[i][j] == 1){
                q.push({i,j});
            }
        }
    }
    int count=0;
    while(!q.empty()){
        int x = q.front().second;
        int y = q.front().first;
        q.pop();
        if(visited[y][x] == 0 && art[y][x] == 1){
            count++;
            int tp =  bfs(y,x,art, visited);
            picture = max(picture,tp);

        }
    }
    cout<<count<<"\n"<<picture;

}
