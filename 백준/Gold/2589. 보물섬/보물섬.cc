#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<queue>
#include<climits>
#include<string>
using namespace std;
int x,y;
queue<pair<int, int>>start;
vector<vector<char>>space;
int answer = 0;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};
void bfs(int bx, int by){
    vector<vector<int>>visited(y, vector<int>(x, -1));
    visited[by][bx] = 0;
    queue<pair<int, int>>q;
    q.push({by,bx});
    while(!q.empty()){
        int nowx = q.front().second;
        int nowy = q.front().first;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = nowx+dx[i];
            int ny = nowy+dy[i];
            if(nx>=0&&nx<x&&ny>=0&&ny<y&&space[ny][nx] == 'L' && visited[ny][nx] == -1){
                visited[ny][nx] = visited[nowy][nowx] + 1;
                answer = max(visited[ny][nx], answer);
                q.push({ny, nx});
            }
        }
    }
}

void run(){
    while(!start.empty()){
        int sx = start.front().second;
        int sy = start.front().first;
        start.pop();
        bfs(sx,sy);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>y>>x;
    space.resize(y, vector<char>(x));
    for(int i=0;i<y;i++){
        string temp;
        cin>>temp;
        for(int j=0;j<temp.size();j++){
            space[i][j] = temp[j];
            if(space[i][j] == 'L'){
                start.push({i,j});
            }
        }
    }
    run();
    cout<<answer;







}


