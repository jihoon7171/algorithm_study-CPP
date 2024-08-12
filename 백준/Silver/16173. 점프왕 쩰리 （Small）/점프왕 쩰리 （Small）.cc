#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
int jump[3][3];
int a;
int dx[2]={1,0};
int dy[2] = {0,1};

int visited[3][3];


bool dfs(int tempa, int b){
    visited[tempa][b] = 1;
    if(tempa == a-1&& b == a-1){
        cout<<"HaruHaru";
       return true;
    }
    int dis = jump[tempa][b];
    for(int i=0;i<2;i++){
        int nextx = tempa + dx[i]*dis;
        int nexty = b + dy[i]*dis;
        if(nextx<a && nexty<a && visited[nextx][nexty] == 0){
            if(dfs(nextx, nexty))
            return true;
        }
    }
    return false;
    

}
int main() {
    cin>>a;
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            cin>>jump[i][j];
        }
    }
    if(!dfs(0,0)){
        cout<<"Hing";
    }

}
