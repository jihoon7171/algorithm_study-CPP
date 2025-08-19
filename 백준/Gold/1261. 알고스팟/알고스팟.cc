#include <iostream>
#include <vector>
#include <algorithm>
#include<climits>
#include<cmath>
#include<queue>
#include<tuple>
#include<string>
#include<deque>
using namespace std;
int n,m;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
vector<vector<int>>space;
vector<vector<int>>answer;
void bfs(){
    answer[0][0] = 0;
    deque<pair<int, int>>dq;
    dq.push_back({0,0});
    while(!dq.empty()){
        int x = dq.front().second;
        int y = dq.front().first;
        dq.pop_front();
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0&&nx<m&&ny>=0&&ny<n && answer[ny][nx] == -1){
                if(space[ny][nx] == 1){
                    answer[ny][nx] = answer[y][x] + 1;
                    dq.push_back({ny,nx});
                }else{
                    answer[ny][nx] = answer[y][x];
                    dq.push_front({ny,nx});
                }
            }
        }
    }

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>m>>n;
    answer.resize(n, vector<int>(m, -1));
    space.resize(n, vector<int>(m));
    for(int i=0;i<n;i++){
        string temp;
        cin>>temp;
        for(int j=0;j<temp.size();j++){
            space[i][j] = temp[j]-'0';
        }
    }
    bfs();
    cout<<answer[n-1][m-1];
}
