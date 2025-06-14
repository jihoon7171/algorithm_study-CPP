#include<vector>
#include<iostream>
#include<queue>
#include<set>
#include<string>
#include<algorithm>
using namespace std;


vector<vector<int>>original;
int n,m;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int answer;
void input(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>original[i][j];
        }
    }
}


void bfs(int y, int x, vector<vector<int>>&ccopy, vector<vector<bool>>&visited){
    queue<pair<int, int>>q;
    q.push({y,x});
    while(!q.empty()){
        int nowx = q.front().second;
        int nowy = q.front().first;
        q.pop();
        for(int i=0;i<4;i++){
            int newx = nowx+dx[i];
            int newy = nowy+dy[i];
            if(newx>=0 && newx <m && newy >=0 &&newy<n && !visited[newy][newx] && ccopy[newy][newx] == 0){
                visited[newy][newx] = true;
                ccopy[newy][newx] = 2;
                q.push({newy,newx});
            }
        }
    }
}

void dfs(int count, vector<vector<int>>&copy){
    if(count == 3){
        int counting = 0;
        vector<vector<int>>ccopy(copy);
        vector<vector<bool>>visited(n, vector<bool>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ccopy[i][j] == 2 && !visited[i][j]){
                    visited[i][j] = true;
                    bfs(i,j,ccopy, visited);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ccopy[i][j] == 0){
                    counting++;
                }
            }
        }
        answer = max(answer, counting);
        return ;
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(copy[i][j] == 0){
                copy[i][j] = 1;
                dfs(count+1, copy);
                copy[i][j] = 0;
            }

        }
    }
}


int main(){
    cin>>n>>m;
    original.resize(n, vector<int>(m));
    input();
    answer = 0;
    vector<vector<int>>copy(original);
    dfs(0,copy);
    cout<<answer;




    
}