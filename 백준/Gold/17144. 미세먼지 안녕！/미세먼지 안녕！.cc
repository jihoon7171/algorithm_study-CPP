#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>
#include<stack>
#include<set>
#include<limits.h>
#include<queue>
using namespace std;
int r,c,t;
vector<vector<int>>mapp;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
pair<int, int> gomove[4] = {{0,1}, {-1,0}, {0,-1}, {1,0}};
void print(){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<mapp[i][j]<<" " ;
        }
        cout<<"\n";
    }
    cout<<"\n";
}
void answer(){
    int count=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(mapp[i][j]>0){
                count+=mapp[i][j];
            }
        }
    }
    cout<<count;
}


void bfs() {
    queue<pair<int, int>> q;
    vector<vector<int>> newmap(r, vector<int>(c, 0));
    queue<pair<int, int>>start;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (mapp[i][j] > 0) {
                q.push({i, j});
            }
            if(mapp[i][j] == -1){
                start.push({i,j});
            }
        }
    }

    while (!q.empty()) {
        int y = q.front().first;   
        int x = q.front().second;  
        q.pop();

        int count = 0; 

        for (int i = 0; i < 4; i++) {
            int newx = x + dx[i];
            int newy = y + dy[i];
            if (newx >= 0 && newx < c && newy >= 0 && newy < r && mapp[newy][newx] >= 0) {
                count++;
                newmap[newy][newx] += mapp[y][x] / 5; 
            }
        }

        newmap[y][x] += mapp[y][x] - (mapp[y][x] / 5) * count;
    }

    mapp = newmap;
    mapp[start.front().first][start.front().second] = -1;
    start.pop();
    mapp[start.front().first][start.front().second] = -1;  
}
//미세먼지 이동 // 위층
void upmove(int x, int y){
    int nowx = x;
    int nowy = y-1;
    int machinex = x;
    int machiney = y;
    while(nowy>0){
        mapp[nowy][nowx] = mapp[nowy-1][nowx];
        nowy = nowy-1;
    }
   
    while(nowx<c-1){
        mapp[nowy][nowx] = mapp[nowy][nowx+1];
        nowx = nowx+1;
    }
   
    while(nowy < machiney){
        mapp[nowy][nowx] = mapp[nowy+1][nowx];
        nowy = nowy+1;
    }
   
    while(nowx > machinex+1){
        mapp[nowy][nowx] = mapp[nowy][nowx-1];
        nowx = nowx-1;
    }
       
    mapp[y][x+1] = 0;
}

void downmove(int x, int y){
    int nowx = x;
    int nowy = y+1;
    int machinex = x;
    int machiney = y;

    while(nowy < r-1){
        mapp[nowy][nowx] = mapp[nowy+1][nowx];
        nowy = nowy+1;
    }
    while(nowx<c-1){
        mapp[nowy][nowx] = mapp[nowy][nowx+1];
        nowx = nowx+1;
    }

    while(nowy>machiney){
        mapp[nowy][nowx] = mapp[nowy-1][nowx];
        nowy = nowy-1;
    }


    while(nowx > machinex+1){
        mapp[nowy][nowx] = mapp[nowy][nowx-1];
        nowx = nowx-1;
    }
    mapp[y][x+1] = 0;

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>r>>c>>t;
    queue<pair<int, int>>start;
    mapp.resize(r,vector<int>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>mapp[i][j];
            if(mapp[i][j] == -1)
            start.push({i,j});
        }
    }

    pair<int, int>upxy = {start.front().first, start.front().second};
    start.pop();
    pair<int, int>downxy = {start.front().first, start.front().second};
    for(int i=0;i<t;i++){
        bfs();
        upmove(upxy.second, upxy.first);
        downmove(downxy.second, downxy.first);
    }
    // print();
    answer();



}