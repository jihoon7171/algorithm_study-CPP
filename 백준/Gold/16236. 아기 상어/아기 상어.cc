#include <iostream>
#include <vector>
#include <algorithm>
#include<climits>
#include<queue>
#include<tuple>
#include<string>
using namespace std;

// 가로 세로 대각선 방향으로 3칸 이상 -> 가능할 수 없는 게임
// 게임판이 가득 


int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int n;
int count =0;
vector<vector<int>>space;
int nx,ny;
int nowsize = 2;
int noweat = 0;
void printing(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<space[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

bool eat(){
    queue<pair<int, int>>q;
    vector<vector<int>>visited(n, vector<int>(n,-1));
    visited[ny][nx] = 0;
    int dist = INT_MAX;
    int gox, goy;
    bool caneat = false;
    q.push({nx,ny});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i =0; i<4;i++){
            int newx = x+dx[i];
            int newy = y+dy[i];
            if(newx>=0&&newx<n&&newy>=0&&newy<n&&space[newy][newx] <= nowsize && visited[newy][newx] == -1){
                visited[newy][newx]  = visited[y][x] + 1;
                if(space[newy][newx] < nowsize && space[newy][newx] != 0){
                    caneat = true;
                }
                if(caneat && dist > visited[newy][newx]){
                    gox  = newx;
                    goy = newy;
                    dist = visited[newy][newx];
                }
                else if(caneat && dist == visited[newy][newx]){
                    if(newy < goy || (newy == goy && newx < gox)){
                        gox  = newx;
                        goy = newy;
                        dist = visited[newy][newx];                        
                    }
                }
                q.push({newx,newy});
                caneat = false;    
            }
        }
    }
    if(dist == INT_MAX){
        return false;
    }else{
        //space[ny][nx] = 0;
        ny = goy;
        nx = gox;
        ::count += visited[goy][gox];
        noweat ++;
        if(noweat == nowsize){
            noweat = 0;
            nowsize++;
        }
        space[goy][gox] = 0;

        //printing();
        return true;
    }
}

int main(){
    cin>>n;
    space.resize(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>space[i][j];
            if(space[i][j] == 9) {
                nx = j; ny = i;
                space[i][j]  = 0;
            }
        }
    }
    //cout<<"\n";
    while(1){
        if(!eat()){
            cout<<::count;
            return 0;
        }
    }
    cout<<::count;





}
