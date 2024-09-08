#include <iostream>
#include<queue>
#include <string>
#include<vector>
#include<algorithm>
#include<stack>
#include<cstring>
#include<sstream>
#include<unordered_set>
#include<cctype>
using namespace std;

int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dy[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int n,m;

int bfs(vector<vector<int>> &shark){
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    int maxlength=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(shark[i][j] == 1){
                    q.push({i,j});
                    dist[i][j] =0 ;
                }
            }
        }
    
    while(!q.empty()){
        int fx = q.front().first;
        int fy = q.front().second;
        q.pop();
        for(int i=0;i<8;i++){
            int nx = fx+dx[i];
            int ny = fy+dy[i]; 

            if(nx>=0 && nx<n && ny>=0 && ny<m && dist[nx][ny] == -1){
                dist[nx][ny] = dist[fx][fy]+1;
                q.push({nx, ny});
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            maxlength = max(maxlength, dist[i][j]);
        }
    }
    return maxlength;

 
}

int main() {
    cin>>n>>m;
    vector<vector<int>>shark(n, vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>shark[i][j];
        }
    }
    cout<<bfs(shark);



}
