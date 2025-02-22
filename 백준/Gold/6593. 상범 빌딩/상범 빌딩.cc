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
int l,r,c;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
pair<pair<int, int>, int> start;
pair<pair<int, int>, int> goal;
int dimension[2] = {1,-1};
vector<vector<vector<char>>>bd;
void input(){
    for(int i=0;i<l;i++){
        for(int j=0;j<r;j++){
            string temp;
            cin>>temp;
            for(int k=0;k<temp.size();k++){
                bd[i][j][k] = temp[k];
                if(bd[i][j][k] == 'S'){
                    start.first.first = i;
                    start.first.second = j;
                    start.second = k;
                }
                if(bd[i][j][k] == 'E'){
                    goal.first.first = i;
                    goal.first.second = j;
                    goal.second = k;
                }
            }
        }
    }
}

void bfs(vector<vector<vector<int>>>&visited){
    visited[start.first.first][start.first.second][start.second] = 0;
    queue<pair<pair<int, int>, int>>q;
    q.push({{start.first.first, start.first.second}, start.second});
    while(!q.empty()){
        int z = q.front().first.first;
        int y = q.front().first.second;
        int x = q.front().second;
        q.pop();
        for(int j=0;j<4;j++){
            int newz = z;
            int newy = y+dy[j];
            int newx = x+dx[j];
            if(newz>=0 && newz<l && newy >=0 && newy <r && newx >=0 && newx < c && bd[newz][newy][newx] != '#' && visited[newz][newy][newx] == -1){
                visited[newz][newy][newx] = visited[z][y][x] +1;
                q.push({{newz,newy}, newx});
            }
        }
        for(int i=0;i<2;i++){
            int newz = z+dimension[i];
            if(newz>=0 && newz<l && y >=0 && y <r && x >=0 && x < c && bd[newz][y][x] != '#' && visited[newz][y][x] == -1){
                visited[newz][y][x] = visited[z][y][x] +1;
                q.push({{newz,y}, x});
            }
        }
    }
    
}

void result(vector<vector<vector<int>>>&visited){
    if(visited[goal.first.first][goal.first.second][goal.second] != -1){
        cout<<"Escaped in "<<visited[goal.first.first][goal.first.second][goal.second]<<" minute(s)."<<"\n";
    }else{
        cout<<"Trapped!"<<"\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while(1){
        cin>>l>>r>>c;
        if(l==0 && r == 0 && c == 0){
            return 0;
        }
        bd.clear();
        bd.resize(l, vector<vector<char>>(r, vector<char>(c)));
        vector<vector<vector<int>>>visited(l, vector<vector<int>>(r, vector<int>(c,-1)));

        input();
        bfs(visited);
        // for(int i=0;i<l;i++){
        //     for(int j=0;j<r;j++){
        //         for(int k=0;k<c;k++){
        //             cout<<visited[i][j][k]<<" ";
        //         }
        //         cout<<"\n";
        //     }
        //     cout<<"\n";
        // }
        result(visited);
    }

}
