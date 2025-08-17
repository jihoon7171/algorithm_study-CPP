#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<queue>
using namespace std;
int n,m,h;
vector<vector<int>>space;
pair<int, int>home;
vector<pair<int, int>>mint;
int answer = 0;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
vector<vector<bool>>visited;
int dist(int x,int y, int nx, int ny){
    return abs(x-nx) + abs(y-ny);
    

}

void dfs(int x, int y, int hp , int count){
    for (auto q : mint){
        if(dist(x,y,q.second,q.first) <= hp && !visited[q.first][q.second]){
            visited[q.first][q.second] = true;
            if(dist(home.second, home.first, q.second, q.first) <= hp+h-dist(x,y,q.second,q.first)){
                answer = max(answer, count+1);
            }
            dfs(q.second, q.first, hp-dist(x,y,q.second,q.first)+h, count+1);
            visited[q.first][q.second] = false;
        }
    }
}

int main(){
    cin>>n>>m>>h;
    space.resize(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>space[i][j];
            if(space[i][j] == 1){
                home.first = i;
                home.second = j;
            }
            if(space[i][j] == 2){
                mint.push_back({i,j});
            }
        }
    }
    visited.resize(n, vector<bool>(n));
    dfs(home.second, home.first, m,0);
    cout<<answer;
    
    
}