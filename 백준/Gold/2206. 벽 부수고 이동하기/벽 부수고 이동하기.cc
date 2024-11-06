#include <iostream>
#include <vector>
#include <climits>
#include<queue>
#include <string>
#include <algorithm>
using namespace std;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int map[1000][1000];
int visited[1000][1000][2];
int n,m;

int bfs(){
    queue<pair<pair<int, int>, int>>q;
    q.push({{0,0},0});
    visited[0][0][0] = 1;
    while(!q.empty()){
        int nowx = q.front().first.first;
        int nowy = q.front().first.second;
        int broke = q.front().second;   
        if(nowx == m-1 && nowy == n-1){
            return visited[nowy][nowx][broke];
        }

        q.pop();
        for(int i=0;i<4;i++){
            int newx = nowx+dx[i];
            int newy = nowy+dy[i];
            if(newx>=0&&newx<m&&newy>=0&&newy<n){
                if(map[newy][newx] == 0 && visited[newy][newx][broke] == 0){
                    visited[newy][newx][broke] = visited[nowy][nowx][broke]+1;
                    q.push({{newx, newy}, broke});
                }
                if(map[newy][newx] == 1 && broke == 0){
                    visited[newy][newx][broke+1] = visited[nowy][nowx][broke]+1;
                    q.push({{newx, newy}, broke+1});
                }

            }
        }
    }
    return -1;

}


int main() {
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string temp;
        cin>>temp;
        for(int j=0;j<m;j++){
            map[i][j] = temp[j]-'0';
        }
    }
    cout<<bfs();
    


}