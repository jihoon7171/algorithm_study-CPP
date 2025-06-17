#include<vector>
#include<iostream>
#include<queue>
#include<set>
#include<string>
#include<algorithm>
using namespace std;
vector<vector<int>>sns(1000001);
vector<vector<int>>dp;
int n;
int answer;
vector<vector<int>>square;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

//퍼센트
int per[9] = {1,1,2,2,7,7,10,10,5};
//좌우 모래움직임
int l_dx[9] = {1,1,0,0,0,0,-1,-1,-2};
int r_dx[9] = {-1,-1,0,0,0,0,1,1,2};
int lr_dy[9] = {-1,1,-2,2,-1,1,-1,1,0};
//상하 모래움직임
int ud_dx[9] = {-1,1,-2,2,-1,1,-1,1,0};
int u_dy[9] = {1,1,0,0,0,0,-1,-1,-2};
int d_dy[9] = {-1,-1,0,0,0,0,1,1,2};



void movesand(int d, int x, int y){

    int sand = square[y][x];
    int msand = sand;
    if(sand <= 0){
        return ;
    }
    square[y][x] = 0;
    //cout<<sand<<"\n";
    // 1,2,3,4 순서대로 좌 하 우 상
    if( d == 0){
        for(int i=0;i<9;i++){
            int newx = x+l_dx[i];
            int newy = y+lr_dy[i];
            if(newx>=0 && newx<n&&newy>=0&&newy<n){
                float cal = per[i] * 0.01;
                int gosand = cal*sand;
                msand -= gosand;
                //cout<<gosand<<"\n";
                square[newy][newx] += gosand;
            }else{
                float cal = per[i] * 0.01;
                int gosand = cal*sand;
                msand -= gosand;
                answer += gosand;
            }
        }
    }else if(d == 1){
        for(int i=0;i<9;i++){
            int newx = x+ud_dx[i];
            int newy = y+d_dy[i];
            if(newx>=0 && newx<n&&newy>=0&&newy<n){
                float cal = per[i] * 0.01;
                int gosand = cal*sand;
                msand -= gosand;
                square[newy][newx] += gosand;
            }else{
                float cal = per[i] * 0.01;
                int gosand = cal*sand;
                msand -= gosand;
                answer += gosand;
            }
        }        
    }else if(d == 2){
        for(int i=0;i<9;i++){
            int newx = x+r_dx[i];
            int newy = y+lr_dy[i];
            if(newx>=0 && newx<n&&newy>=0&&newy<n){
                float cal = per[i] * 0.01;
                int gosand = cal*sand;
                msand -= gosand;
                square[newy][newx] += gosand;
            }else{
                float cal = per[i] * 0.01;
                int gosand = cal*sand;
                msand -= gosand;
                answer += gosand;
            }
        }        
    }else if(d == 3){
        for(int i=0;i<9;i++){
            int newx = x+ud_dx[i];
            int newy = y+u_dy[i];
            if(newx>=0 && newx<n&&newy>=0&&newy<n){
                float cal = per[i] * 0.01;
                int gosand = cal*sand;
                msand -= gosand;
                square[newy][newx] += gosand;
            }else{
                float cal = per[i] * 0.01;
                int gosand = cal*sand;
                msand -= gosand;
                answer += gosand;
            }
        }        
    }
    int gox = x+dx[d];
    int goy = y+dy[d];
    if(gox>=0 && gox<n && goy>=0 && goy<n){
        square[goy][gox] += msand;
    }else{
        answer += msand;
    }
    //cout<<d<<" "<<y<<" "<<x<<" "<<sand<<"\n";
}

void print(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<square[i][j]<<" ";
        }
        cout<<"\n";
    }
}


void run(){
    int len = 1;
    int dir = 0;
    int x = n/2, y = n/2;
    while (true) {
        for (int d = 0; d < 2; d++) { // 두 번 반복: 방향쌍
            for (int i = 0; i < len; i++) {
                x += dx[dir];
                y += dy[dir];
                movesand(dir, x, y);
            if (x == 0 && y == 0) {
                cout << answer;
                return;
            }
            }
            dir = (dir + 1) % 4;
        }
        len++; // 이동 길이 증가
    }
}

int main(){
    cin>>n;
    answer=0;
    square.resize(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>square[i][j];
        }
    }
    run();
    

} 
