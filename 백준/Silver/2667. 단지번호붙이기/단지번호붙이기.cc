#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int home[25][25];
bool visited[25][25];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
int a;
int housecount;

void dfs(int x, int y){
    housecount++;
    visited[x][y] = true;
    for(int i=0;i<4;i++){
        int xx = x+dx[i];
        int yy = y+dy[i];
        if(xx >= 0 && yy >= 0 && xx < a && yy < a && !visited[xx][yy] && home[xx][yy] == 1){
            dfs(xx,yy);
        }
    }
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int count=0;
    cin>>a;
    vector<int>check;
    for(int i=0;i<a;i++){
        int j=0;
        string input;
        cin>>input;
        for (char c : input) {
        home[i][j] = c-'0';
        j++;  
    }
    }
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            if(!visited[i][j] && home[i][j] == 1){
            housecount=0;
            dfs(i,j);
            check.push_back(housecount);
            count++;
            }
        }
    }
    cout<<count<<"\n";
    sort(check.begin(), check.end());
    for(int i=0;i<check.size();i++){
        cout<<check[i]<<"\n";
    }

    return 0;
}