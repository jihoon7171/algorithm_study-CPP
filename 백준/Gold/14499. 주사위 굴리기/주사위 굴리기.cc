#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include<cmath>
using namespace std;

void movement(vector<int>&rec, int index){
    if(index == 1){
        int temp = rec[4];
        rec[4] = rec[3];
        rec[3] = rec[2];
        rec[2] = rec[6];
        rec[6] = temp;
    }else if(index == 2){
        int temp = rec[2];
        rec[2] = rec[3];
        rec[3] = rec[4];
        rec[4] = rec[6];
        rec[6] = temp;
    }else if(index == 4){
        int temp = rec[5];
        rec[5] = rec[3];
        rec[3] = rec[1];
        rec[1] = rec[6];
        rec[6] = temp;
    }else if(index == 3){
        int temp = rec[1];
        rec[1] = rec[3];
        rec[3] = rec[5];
        rec[5] = rec[6];
        rec[6] = temp;
    }
}


pair<int, int>direction[4] = {{0,1}, {0,-1}, {-1,0}, {1,0}}; // 입력 -1 이 명령

int main() {
    vector<int>rec(7,0);
    int n,m;
    cin>>n>>m;
    vector<vector<int>>map(n, vector<int>(m));
    int nowx, nowy;
    cin>>nowy>>nowx;
    int k;
    cin>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>map[i][j];
        }
    }
    for(int i=0;i<k;i++){
        int temp=0;
        cin>>temp;
        int newy = nowy+direction[temp-1].first;
        int newx = nowx+direction[temp-1].second;
        if(newy>=0 && newy<n && newx >=0 && newx<m ){
            nowx = newx;
            nowy = newy;
            movement(rec, temp);
            if(map[nowy][nowx]!=0){
                rec[6] = map[nowy][nowx];
                map[nowy][nowx] = 0;
            }else if(map[nowy][nowx]==0){
                map[nowy][nowx] = rec[6];
            }
            // for(int j=1;j<7;j++){
            //     cout<<rec[j]<<" ";
            // }
            // cout<<"\n";
            cout<<rec[3]<<"\n";
        }else{
            continue;
        }

    }
    
    
}