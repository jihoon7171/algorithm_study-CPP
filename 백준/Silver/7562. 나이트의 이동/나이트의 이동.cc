#include <iostream>
#include <vector>
#include <climits>
#include<queue>
#include <string>
#include <algorithm>
#include<stack>
#include<set>
#include<map>
#include<limits.h>
using namespace std;
int l;
int dx[8] = {-1,-2,-2,-1,1,2,2,1};
int dy[8] = {-2,-1,1,2,2,1,-1,-2};
int goalx, goaly;
void bfs(vector<vector<int>>&map, int x , int y){
    queue<pair<int, int>>q;
    q.push({x,y});
    vector<vector<int>>checking(l, vector<int>(l,-1));
    checking[y][x] = 0;
    while(!q.empty()){
        int nowx = q.front().first;
        int nowy = q.front().second;
        q.pop();
        if(nowx == goalx && nowy == goaly){
             cout<<checking[goaly][goalx]<<"\n";
             return ;
        }
        for(int i=0;i<8;i++){
            int newx = nowx+dx[i];
            int newy = nowy+dy[i];
            if(newx>=0&&newx<l&&newy>=0&&newy<l&&checking[newy][newx] == -1){
                checking[newy][newx] = checking[nowy][nowx]+1;
                q.push({newx, newy});
            }
        }
    }
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int a;
    cin>>a;
    for(int i=0;i<a;i++){
        int x,y;
        cin>>l>>x>>y>>goalx>>goaly;
        vector<vector<int>>map(l, vector<int>(l,0));
        bfs(map, x,y);
    }




}