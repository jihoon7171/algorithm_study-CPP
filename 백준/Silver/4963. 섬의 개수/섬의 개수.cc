#include <iostream>
#include <vector>
#include<queue>
using namespace std;
        int w,h;
int dx[8] = {1,-1,0,0,-1,1,-1,1};
int dy[8] = {0,0,1,-1,-1,-1,1,1};
void bfs(int y, int x, vector<vector<bool>>&visited, vector<vector<int>>&map){
    queue<pair<int, int>>q;
    q.push({x,y});
    while(!q.empty()){
        int nowx = q.front().first;
        int nowy = q.front().second;
        q.pop();
        for(int i=0;i<8;i++){
            int newx = nowx+dx[i];
            int newy = nowy+dy[i];
            if(newx>=0&&newx<w&&newy>=0&&newy<h&&!visited[newy][newx]&&map[newy][newx] == 1){
                visited[newy][newx] = true;
                q.push({newx, newy});
            }
        }
    }
}

int main() {
    while(1){

        cin>>w>>h;
        if(w==0&&h==0){
            break;
        }
         vector<vector<int>>map(h, vector<int>(w));
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin>>map[i][j];
            }
        }
        int count=0;
        vector<vector<bool>>visited(h, vector<bool>(w,false));
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(!visited[i][j] && map[i][j] == 1){
                    count++;
                    visited[i][j] = true;
                    bfs(i,j, visited, map);
                }
            }
        }
        cout<<count<<"\n";
    }
}