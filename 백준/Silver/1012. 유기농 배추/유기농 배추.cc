#include<vector>
#include<iostream>
#include<cstring>
using namespace std;

int map[50][50];
bool visited[50][50];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int w,h;
void dfs(int x, int y){
    visited[x][y] = true;
    for(int i=0;i<4;i++){
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(xx>=0 && yy >=0&& xx<w && yy < h &&map[xx][yy] == 1  && !visited[xx][yy]){
            dfs(xx,yy);

        }
    }
}

int main(){
   
    int n;
    cin>>n;
    for(int q=0;q<n;q++){
        int f,count=0;
        cin>>w>>h>>f;
            memset(map, 0, sizeof(map));
            memset(visited, false, sizeof(visited));
        for(int i=0;i<f;i++){  

            int a,b;
            cin>>a>>b;
            map[a][b] = 1;
        }

        for(int i=0;i<w;i++){
            for(int j=0;j<h;j++){
                if(map[i][j] ==1 && !visited[i][j]){
                    count++;
                    dfs(i,j);
                }
            }
        }
        cout<<count<<endl;
    }
    return 0;
}