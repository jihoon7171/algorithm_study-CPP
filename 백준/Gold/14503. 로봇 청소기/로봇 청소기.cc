#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
pair<int, int> godirection[4] = {{-1,0}, {0,-1}, {1,0}, {0,1}};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<vector<int>>clean(n, vector<int>(m));
    pair<int, int>now;
    cin>>now.first;
    cin>>now.second;
    int startdirection;
    cin>>startdirection;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>clean[i][j];
        }
    }
    int nowdirection;
    if(startdirection == 1){
        nowdirection = 3;
    }else if(startdirection == 3){
        nowdirection =1;
    }else{
        nowdirection = startdirection;
    }
    while(1){
        bool checking = false;
        if(clean[now.first][now.second] == 0){
            clean[now.first][now.second]=2;
        }
        int temp = nowdirection;
        for(int i=0;i<4;i++){
            temp = (temp+1)%4;
            int goy = now.first+godirection[temp].first;
            int gox = now.second+godirection[temp].second;
            if(goy>=0&&goy<n&&gox>=0&&gox<m&&clean[goy][gox]==0){
                now.first=  goy;
                now.second = gox;
                checking = true;
                nowdirection = temp;
                break;
            }
        }

        if(checking){
            continue;
        }
        int backy = now.first - godirection[nowdirection].first;
        int backx = now.second - godirection[nowdirection].second;
        if(backy>=0&&backy<n&&backx>=0&&backx<m&&clean[backy][backx] !=1){
            now = {backy, backx};
        }else{
            break;
        }
    }
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(clean[i][j] == 2){
                count++;
            }
        }
    }

    cout<<count;
}