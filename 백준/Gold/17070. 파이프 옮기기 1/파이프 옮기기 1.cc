#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <map>
#include <cstring>
#include <climits>
#include <string>
#include<cstring>
#include<deque>
using namespace std;
vector<vector<int>>pipe;
vector<vector<bool>>checked;
int a;
pair<int, int> garomove[2] = {{0,1}, {1,1}}; // temp = true;
pair<int, int>seromove[2] = {{1,0}, {1,1}}; // temp = false;
pair<int, int>crossmove[3] = {{1,0},{0,1}, {1,1}}; 
void dfs(pair<int, int>now[], int &count){
    if(now[1].second == a-1 && now[1].first== a-1){
        count++;
        return ;
    }
    if(now[0].second +1 == now[1].second && now[0].first == now[1].first){ // 현재 가로여서 가로이동만 가능
        for(int i=0;i<2;i++){
            pair<int, int>tail = now[1];
            int newx = now[1].second + garomove[i].second;
            int newy = now[1].first + garomove[i].first;
            if(i==1 && newx<a&&newx>=0&&newy<a&&newy>=0 && pipe[newy][newx] == 0 && pipe[newy-1][newx]==0 && pipe[newy][newx-1]==0){
            pair<int, int> temp[2] = {tail, {newy, newx}}; 
            dfs(temp, count); 
            }
            else if(i==0&&newx<a&&newx>=0&&newy<a&&newy>=0 && pipe[newy][newx] == 0){
            pair<int, int> temp[2] = {tail, {newy, newx}}; 
            dfs(temp, count); 
            }
        }
    }else if(now[0].first +1 == now[1].first &&now[0].second == now[1].second){
            for(int i=0;i<2;i++){
            pair<int, int>tail = now[1];
            int newx = now[1].second + seromove[i].second;
            int newy = now[1].first + seromove[i].first;
            if(i==1 && newx<a&&newx>=0&&newy<a&&newy>=0 && pipe[newy][newx] == 0 && pipe[newy-1][newx]==0 && pipe[newy][newx-1]==0){
            pair<int, int> temp[2] = {tail, {newy, newx}}; 
            dfs(temp, count); 
            }
            else if(i==0&&newx<a&&newx>=0&&newy<a&&newy>=0 && pipe[newy][newx] == 0){
            pair<int, int> temp[2] = {tail, {newy, newx}}; 
            dfs(temp, count); 
            }
        }
    }else if(now[0].first +1 == now[1].first && now[0].second+1==now[1].second){
            for(int i=0;i<3;i++){
            pair<int, int>tail = now[1];
            int newx = now[1].second + crossmove[i].second;
            int newy = now[1].first + crossmove[i].first;
            if(i==2 && newx<a&&newx>=0&&newy<a&&newy>=0 && pipe[newy][newx] == 0 && pipe[newy-1][newx]==0 && pipe[newy][newx-1]==0){
            pair<int, int> temp[2] = {tail, {newy, newx}}; 
            dfs(temp, count); 
            }
            else if(i!=2&&newx<a&&newx>=0&&newy<a&&newy>=0 && pipe[newy][newx] == 0){
            pair<int, int> temp[2] = {tail, {newy, newx}}; 
            dfs(temp, count); 
            }
        }
    }


}

int main() {
    cin>>a;
    pipe.resize(a, vector<int>(a));
    checked.resize(a, vector<bool>(a));
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            cin>>pipe[i][j];
        }
    }
    int count=0;
    pair<int, int>now[2] = {{0,0}, {0,1}};
    dfs(now,count);
    cout<<count;


}
