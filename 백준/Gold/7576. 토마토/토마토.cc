#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
int a,b;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
    
void bfs(vector<vector<int>>&tmt){
    vector<vector<int>>dist(b,vector<int>(a,-1));
    queue<pair<int, int>>q;
    for(int i=0;i<b;i++){
        for(int j=0;j<a;j++){
            if(tmt[i][j] == 1){
                q.push({i,j});
                dist[i][j] = 0;
            }
            if(tmt[i][j] == -1){
                dist[i][j] = -10;
            }
        }
    }

    while(!q.empty()){
        int ty = q.front().first;
        int tx = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int ny = ty+dy[i];
            int nx = tx+dx[i];
            if(ny>=0&&ny<b&&nx>=0&&nx<a&&dist[ny][nx]==-1&&dist[ny][nx] != -10){
                dist[ny][nx] = dist[ty][tx]+1;
                q.push({ny,nx});
            }
        }
    } 
    bool checking = true;
    int maxcount = -100;
        for(int i=0;i<b;i++){
            for(int j=0;j<a;j++){
            maxcount = max(maxcount, dist[i][j]);
            if(dist[i][j] == -1){
                checking = false;
            }
        }
    }

    if(checking){
        cout<<maxcount;
    }else{
        cout<<"-1";
    }

}

int main(){
    cin>>a>>b;
    vector<vector<int>>tmt(b,vector<int>(a));
    for(int i=0;i<b;i++){
        for(int j=0;j<a;j++){
            cin>>tmt[i][j];
        }
    }
    bfs(tmt);
}