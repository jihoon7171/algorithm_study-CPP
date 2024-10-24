#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
int n;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};
vector<vector<char>>art;
void bfs(vector<vector<bool>>&checking, int x, int y, char now, int &count){
    count++;
    queue<pair<int, int>>q;
    q.push({x, y});
    while(!q.empty()){
        int nowx = q.front().first;
        int nowy = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int newx = nowx+dx[i];
            int newy = nowy+dy[i];
            if(newx>=0&&newx<n&&newy>=0&&newy<n&&art[newy][newx] == now&&!checking[newy][newx]){
                checking[newy][newx] = true;
                q.push({newx, newy});
            }
        }
    }
}

void jsbfs(vector<vector<bool>>&checking, int x, int y ,char now, int&count){
    count++;
    queue<pair<int, int>>q;
    q.push({ x,  y});
    while(!q.empty()){
        int nowx = q.front().first;
        int nowy = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int newx = nowx+dx[i];
            int newy = nowy+dy[i];
            if(newx>=0&&newx<n&&newy>=0&&newy<n&&!checking[newy][newx]){
                if(now == 'R'){
                    if(art[newy][newx]==now || art[newy][newx] == 'G'){
                        checking[newy][newx] = true;
                        q.push({newx, newy});
                    }
                }else if(now == 'G'){
                    if(art[newy][newx]==now || art[newy][newx] == 'R'){
                    checking[newy][newx] = true;
                    q.push({newx, newy});
                    }
                }else{
                    if(art[newy][newx] == now){
                    checking[newy][newx] = true;
                    q.push({newx, newy});
                    }
                }
            }
        }
    }
}

int main(){
    cin>>n;
    art.resize(n, vector<char>(n));
    for(int i=0;i<n;i++){
        string as;
        cin>>as;
        for(int j=0;j<as.size();j++){
            art[i][j] = as[j];
        }
    }
    int count =0;
    vector<vector<bool>>checking(n, vector<bool>(n, false));  
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(!checking[j][k]){
                    checking[j][k] = true;
                bfs(checking, k,j,art[j][k], count);
            }
        }
    }
    cout<<count<<" ";
    count =0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            checking[i][j] = false;
        }
    }

        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(!checking[j][k]){
                    checking[j][k] = true;
                jsbfs(checking, k,j,art[j][k], count);
            }
        }
    }
    cout<<count;



}



