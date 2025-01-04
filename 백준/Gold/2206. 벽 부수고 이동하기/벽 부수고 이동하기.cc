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
    int n,m;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int answer = INT_MAX;
queue<pair<int, int>>wall;
int lab[1001][1001];
int dis[1001][1001][2];

int bfs(){
    queue<pair<pair<int, int>, int>>q;
    dis[1][1][0] = 1;
    q.push({{1,1},0});
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int broke = q.front().second;
        if(x == m && y == n){
            return dis[y][x][broke];
        }
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=1&&nx<=m&&ny>=1&&ny<=n){
                if(lab[ny][nx] == 1 && broke == 0){
                    dis[ny][nx][broke+1] = dis[y][x][broke]+1;
                    q.push({{nx,ny},broke+1});
                }
                if(lab[ny][nx] == 0 && dis[ny][nx][broke] == 0){
                    dis[ny][nx][broke] = dis[y][x][broke]+1;
                    q.push({{nx,ny},broke});
                }
            }
        }
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        string temp;
        cin>>temp;
        for(int j=0;j<temp.size();j++){
            lab[i][j+1] = temp[j] - '0';
        }
    }
    cout<<bfs();



    
}
