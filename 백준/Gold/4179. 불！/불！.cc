#include<vector>
#include<iostream>
#include<queue>
#include<set>
#include<string>
#include<algorithm>
#include<climits>
using namespace std;
int r,c;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
vector<vector<char>>matrix;
vector<vector<int>>jvisited;
vector<vector<int>>fvisited;
//한번 불 이동함
void movefire(){
    queue<pair<int, int>>fire;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(fvisited[i][j] == 0){
                fire.push({j,i});
            }
        }
    }
    while(!fire.empty()){
        int x = fire.front().first;
        int y = fire.front().second;
        fire.pop();
        for(int i=0;i<4;i++){
            int newx = x+dx[i];
            int newy = y+dy[i];
            if(newx>=0 && newx <c && newy>=0 && newy <r && matrix[newy][newx] != '#' && fvisited[newy][newx] == -1 ){
                fvisited[newy][newx] = fvisited[y][x]+1;
                fire.push({newx,newy});
            }
        }
    }
}
//한번 이동하고 다음에 이동할 좌표들 반환
void run(){
    queue<pair<int, int>>rq;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(jvisited[i][j] == 0){
                rq.push({j,i});
            }
        }
    }
    while(!rq.empty()){
        int x = rq.front().first;
        int y = rq.front().second;
        rq.pop();
        for(int i=0;i<4;i++){
            int newx = x+dx[i];
            int newy = y+dy[i];
            if(newx>=0 && newx <c && newy>=0 && newy <r && matrix[newy][newx] == '.' && jvisited[newy][newx] == -1){
                jvisited[newy][newx] = jvisited[y][x] + 1;
                rq.push({newx,newy});
            }
        }
    }
}

void checking(){
    int temp = INT_MAX;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(i == 0 || i == r-1 || j == 0 || j==c-1){
                if(jvisited[i][j] != -1){
                    if(fvisited[i][j] == -1){
                        temp = min(temp, jvisited[i][j]+1);
                    }else{
                        if(jvisited[i][j] < fvisited[i][j]){
                            temp = min(temp, jvisited[i][j]+1);
                        }
                    }
                }
            }
        }
    }
    if(temp == INT_MAX){
        cout<<"IMPOSSIBLE";
    }else{
        cout<<temp;
    }
    return;
}
void coutfire(){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<fvisited[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void coutjihoon(){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<jvisited[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void runq(){

    movefire();
    run();
    checking();
    //cout<<"\n";
    //coutjihoon();
    //cout<<"\n";
    //coutfire();

}


int main() {
    cin>>r>>c;
    matrix.resize(r, vector<char>(c));
    jvisited.resize(r,vector<int>(c,-1));
    fvisited.resize(r,vector<int>(c,-1));
    int startx,starty;
    for(int i=0;i<r;i++){
        string temp;
        cin>>temp;
        for(int j=0;j<temp.size();j++){
            matrix[i][j] = temp[j];
            if(matrix[i][j] == 'J'){
                jvisited[i][j] = 0;
                startx = j;
                starty = i;
            }else if (matrix[i][j] == 'F'){
                fvisited[i][j] = 0;
            }
        }
    }

    runq();


}