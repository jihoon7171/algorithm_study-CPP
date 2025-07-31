#include<queue>
#include <iostream>
#include <vector>
#include <algorithm>
#include<climits>
using namespace std;
vector<vector<char>>field(12,vector<char>(6));
vector<vector<bool>>visited(12, vector<bool>(6));
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int count=0;

void down();
void input(){
    for(int i=0;i<12;i++){
        for(int j=0;j<6;j++){
            cin>>field[i][j];
        }
    }
}
void bomb(vector<pair<int, int>>v){
    for(int i=0;i<v.size();i++){
        int x = v[i].first;
        int y = v[i].second;
        field[y][x] = '.';
        visited[y][x] = false; // 터트린곳은 다시 기도 됨
    }
    down();
    ::count++;
}
bool bombcheck(int x, int y){
    queue<pair<int, int>>q;
    vector<pair<int, int>>v;
    q.push({x,y});
    v.push_back({x,y});
    vector<vector<bool>>nowvisited(12, vector<bool>(6));
    nowvisited[y][x] = true;
    int tempcount = 1;

    while(!q.empty()){
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int newx = nx+dx[i];
            int newy = ny+dy[i];
            if(newx>=0 && newx < 6 && newy >=0 && newy < 12 && !nowvisited[newy][newx] ){
                if(field[newy][newx] == field[y][x]){
                    tempcount++;
                    nowvisited[newy][newx] = true;
                    q.push({newx, newy});
                    v.push_back({newx,newy});
                }
            }
        }
    }

    if(tempcount>=4){
        for(auto p : v){
            field[p.second][p.first] = '.';
        }
        return true;
    }
    return false;
}

void down(){
    for(int j=0;j<6;j++){
        int empty_row = 11;
        for(int i=11;i>=0;i--){
            if(field[i][j] != '.'){
                if(i != empty_row){
                    field[empty_row][j] = field[i][j];
                    field[i][j] = '.';
                }
                empty_row--;
            }
        }
    }
}


void run(){
    while(true){
        bool exploded = false;
        visited = vector<vector<bool>>(12, vector<bool>(6, false)); // 필요시 유지
        for(int i=0;i<12;i++){
            for(int j=0;j<6;j++){
                if(field[i][j] != '.'){
                    if(bombcheck(j, i)){
                        exploded = true;
                    }
                }
            }
        }
        if(!exploded) break;
        ::count++;
        down();
    }
}

int main(){
    input();
    run();
    cout<<::count;
}

 