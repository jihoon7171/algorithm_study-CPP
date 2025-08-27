#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<cmath>
#include<queue>
#include<tuple>
#include<string>
#include<deque>
using namespace std;
int n,q,s;
vector<vector<int>>space;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};
int bigice = 0;

void rotate(int sx, int ex, int sy, int ey){
    int m = ex-sx;
    vector<vector<int>> tmp(m, vector<int>(m));
    // 부분 영역 복사 + 회전
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            tmp[i][j] = space[sy + (m-1-j)][sx + i];
        }
    }
    // 결과 반영
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            space[sy+i][sx+j] = tmp[i][j];
        }
    }
}
void input(){
    for(int i=0;i<s;i++){
        for(int j=0;j<s;j++){
            cin>>space[i][j];
        }
    }
}

void run(int l){
    int sx = 0;
    int sy = 0;
    int stand = pow(2,l);
    int count = 0;
    while(1){
        //cout<<count<<"\n";
        count++;
        //cout<<sx<<" "<<sx+stand<<" "<<sy<<sy+stand<<"\n";
        rotate(sx,sx+stand, sy, sy+stand);
        sx += stand;
        if(sx == s){
            sy += stand;
            sx = 0;
            if(sy == s){
                return ;
            }
        }
    }
}

void output(){
    for(int i=0;i<s;i++){
        for(int j=0;j<s;j++){
            cout<<space[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void bfs(vector<vector<bool>>&visited, int y, int x, int &ice, int&box){
    visited[y][x] = true;
    queue<pair<int, int>>q;
    q.push({y,x});
    while(!q.empty()){
        int nowx = q.front().second;
        int nowy = q.front().first;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = nowx+dx[i];
            int ny = nowy + dy[i];
            if(nx>=0&&nx<s&&ny>=0&&ny<s&&!visited[ny][nx] && space[ny][nx] != 0){
                visited[ny][nx] = true;
                q.push({ny,nx});
                ice += space[ny][nx];
                box++;
            }
        }
    }
    bigice = max(bigice, box);

}

void decreaseice(){
    queue<pair<int, int>>q;
    for(int i=0;i<s;i++){
        for(int j=0;j<s;j++){
            if(space[i][j] == 0) continue;
            int count = 0;
            for(int k=0;k<4;k++){
                int nx = j+dx[k];
                int ny = i+dy[k];
                if(nx>=0&&nx<s&&ny>=0&&ny<s&&space[ny][nx] != 0){
                    count++;
                }
            }
            if(count <3){
                q.push({i,j});
            }
        }
    }
    while(!q.empty()){
        int x = q.front().second;
        int y = q.front().first;
        q.pop();
        space[y][x] -- ;
    }
}

void allice(){
    int count = 0;
    vector<vector<bool>>visited(s, vector<bool>(s));
    for(int i=0;i<s;i++){
        for(int j=0;j<s;j++){
            if(!visited[i][j] && space[i][j]!=0){
                //visited[i][j] = true;
                int ice = space[i][j];
                int box  = 1;
                bfs(visited, i, j, ice, box);
                count += ice;
            }
        }
    }
    cout<<count<<"\n"<<bigice;
}

int main(){
    cin>>n>>q;
    s = pow(2,n);
    space.resize(s, vector<int>(s));
    input();
    while(q--){
        int l;
        cin>>l;
        run(l);
        decreaseice();
    }
    //output();
    allice();






}