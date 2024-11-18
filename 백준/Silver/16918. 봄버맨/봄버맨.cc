#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>
#include<stack>
#include<set>
#include<map>
#include<limits.h>
#include<queue>
using namespace std;
int r,c,n;
vector<vector<char>>mapp;
void print(){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<mapp[i][j];
        }
        cout<<"\n";
    }
    cout<<"\n";
}


int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};


void remain(){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(mapp[i][j] == '.'){
                mapp[i][j] = '1';
            }
        }
    }
}
void bomb(){
    queue<pair<int, int>>q;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(mapp[i][j] == 'O'){
                q.push({i,j});
            }
        }
    }
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        mapp[y][x] = '.';
        for(int j=0;j<4;j++){
            int newx = x+dx[j];
            int newy = y+dy[j];
            if(newx>=0&&newx<c&&newy>=0&&newy<r){
                mapp[newy][newx] = '.';
            }
        }

    }
    
}

void onetotwo(){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(mapp[i][j] == '1'){
                mapp[i][j] = 'O';
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>r>>c>>n;
    mapp.resize(r,vector<char>(c));
    for(int i=0;i<r;i++){
        string temp;
        cin>>temp;
        for(int j=0;j<temp.size();j++){
            mapp[i][j] = temp[j];
        }
    }

int count =1;
    while(count<n){
        remain();
        count++;
        if(count>=n) break;
        bomb();
        count++;
        if(count>=n) break;
        onetotwo();
    }

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(mapp[i][j] == '1') cout<<'O';
            else cout<<mapp[i][j];
            
        }
        cout<<"\n";
    }

}