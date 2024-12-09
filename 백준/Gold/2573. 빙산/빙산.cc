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
vector<vector<int>>ice;
vector<vector<int>>checked;
const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,1,-1};
void melting(){
    queue<pair<int, int>>q;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(ice[i][j]>0){
                q.push({j,i});
            }
        }
    }
  queue<pair<int, int>>pasteq(q);
    queue<int>minus;
    while(!pasteq.empty()){
        int x = pasteq.front().first;
        int y = pasteq.front().second;
        pasteq.pop();
        int count=0;
        for(int i=0;i<4;i++){
            int newx = x+dx[i];
            int newy = y+dy[i];
            if(newx>=0&&newx<m&&newy>=0&&newy<n){
                if(ice[newy][newx] == 0){
                    count++;
                }
            }
        }
        minus.push(count);
    }
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        int temp = minus.front();
        minus.pop();
        ice[y][x] -= temp;
        if(ice[y][x] < 0) ice[y][x] = 0;
    }
    
}

void bfs(vector<vector<bool>>&checking, int x, int y){
    queue<pair<int, int>>q;
    q.push({x,y});
    checking[y][x] = true;
    while(!q.empty()){
        int nowx = q.front().first;
        int nowy = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int newx = nowx+dx[i];
            int newy = nowy+dy[i];
            if(newx>=0&&newx<m&&newy>=0&&newy<n&&ice[newy][newx]>0&&!checking[newy][newx]){
                q.push({newx, newy});
                checking[newy][newx] = true;
            }
        }
    }
}

bool allzero(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(ice[i][j] > 0){
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    ice.resize(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>ice[i][j];
        }
    }
    int count=0;
    while(1){
        count +=1;
        melting();
        // cout<<"\n";
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<ice[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        vector<vector<bool>>checking(n,vector<bool>(m,false));
        int piece =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ice[i][j] > 0 && !checking[i][j]){
                    piece +=1;
                    bfs(checking, j, i);
                }
            }
        }
        if(piece>1) {cout<<count; break;}
        if(allzero()){ cout << 0; break;}
    }
}
