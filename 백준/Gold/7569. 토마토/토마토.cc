#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#include<stack>
#include<unordered_set>

using namespace std;
int n,m,h;
vector<vector<vector<int>>>tmt;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};


bool checking(){
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                if(tmt[i][j][k] == 0){
                    return false;
                }
            }
        }
    }
    return true;
}



void bfs(){
    queue<tuple<int, int, int>>q;
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                if(tmt[i][j][k] == 1){
                    q.push({i,j,k});
                }
            }
        }
    }
    int days = 0;
    //q 에는 지금 토마토의 위치가 들어가있음
    while(!q.empty()){
        int size = q.size();
        bool ripe = false;
        for(int s=0;s<size;s++){
            int nh = get<0>(q.front());
            int nx = get<2>(q.front());
            int ny = get<1>(q.front());
            q.pop();
            //앞
            if((nh-1)>=0&&tmt[nh-1][ny][nx]==0){
                tmt[nh-1][ny][nx] =1;
                q.push({nh-1, ny, nx});
                ripe = true;
            }
            //뒤
            if((nh+1)<h&&tmt[nh+1][ny][nx]==0){
                tmt[nh+1][ny][nx] =1;
                q.push({nh+1, ny, nx});
                ripe = true;
            }
            for(int i=0;i<4;i++){
            int newx = nx+dx[i];
            int newy = ny+dy[i];
            if(newx>=0&&newx<m&&newy>=0&&newy<n&&tmt[nh][newy][newx] == 0){
                tmt[nh][newy][newx] = 1;  
                q.push({nh, newy, newx});
                ripe = true;
                }
            }
        }
        if(ripe) days++;
    }
    checking() ? cout<<days : cout<<-1;
    

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>m>>n>>h;
    tmt.resize(h,vector<vector<int>>(n, vector<int>(m)));
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                cin>>tmt[i][j][k];
            }
        }
    }


    int count =0;
    bfs();

}


