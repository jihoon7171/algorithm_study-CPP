#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include<cmath>
#include<queue>
#include<utility>
#include<climits>
#include<algorithm>
using namespace std;
int n,l,r;
vector<vector<int>>map;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int bfs(int x, int y,vector<vector<bool>>&check){
    vector<pair<int, int>>move;
    check[y][x] = true;
    int human =0;
    int count =1;
    queue<pair<int,int>>q;
    q.push({x,y});
    while(!q.empty()){
        int nowx = q.front().first;
        int nowy = q.front().second;
        human += map[nowy][nowx];
        move.push_back({nowx,nowy});
        q.pop();
        for(int i=0;i<4;i++){
            int newx = nowx+dx[i];
            int newy = nowy+dy[i];
            if(newx < n && newx >=0 && newy<n &&newy >=0 && abs(map[nowy][nowx] - map[newy][newx])>=l &&abs(map[nowy][nowx] - map[newy][newx])<=r &&!check[newy][newx]){
                check[newy][newx] = true;
                count++;
                q.push({newx, newy});
            }
        }
    }

    int gochange;
    if(count>1){
        gochange = human/count;

        for(auto moving : move){
            int gox = moving.first;
            int goy = moving.second;
            map[goy][gox] = gochange;
        } 
    }


    return count;
}


int main(){
   
    cin>>n>>l>>r;
    map.resize(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }
    int count=0;
    while(1){
        vector<vector<bool>>check(n, vector<bool>(n, false)); 
        int e=0;
        bool chch = false;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(!check[i][j]){
                        int human = 0;
                        e= bfs(j,i, check);
                        if(e>1){
                            chch = true;
                        }
                        check[i][j] = true;
                    }
                }
            }
            if(chch){
                count++;
            }else{
                break;
            }
        


        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<map[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }

    }
    cout<<count;



}


    