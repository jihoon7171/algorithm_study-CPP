#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
int a,b;
int dx[4] = {0,0,1,-1};
int dy[4]={1,-1,0,0};
int maze[100][100];
int visited[100][100];
int dist[100][100];


void bfs(int startx, int starty){
    queue<pair<int, int>>q;
    visited[startx][starty] = 1;
    dist[startx][starty] = 1;
    q.push(make_pair(startx,starty));
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int dxx = x+dx[i];
            int dyy = y+dy[i];
            if((0<=dxx && dxx<a) &&(0<=dyy && dyy<b) && maze[dxx][dyy] == 1 && visited[dxx][dyy] == 0 ){
                visited[dxx][dyy] = 1;
                q.push(make_pair(dxx,dyy));
                dist[dxx][dyy] = dist[x][y]+1;


            }

        }
    }

}


int main(){
    cin>>a>>b;
    for(int i=0;i<a;i++){
        string as;
        cin>>as;
        for(int j=0;j<b;j++){
            maze[i][j] = as[j] - '0';
        }
    }
    bfs(0,0);
    cout<<dist[a-1][b-1];

    
}
