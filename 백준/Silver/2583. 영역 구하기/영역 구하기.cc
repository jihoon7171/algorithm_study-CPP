#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>
#include<stack>
#include<set>
#include<limits.h>
#include<queue>
using namespace std;
vector<vector<bool>>checking;
vector<vector<int>>paper;
int m,n,k;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
void block(int x, int y, int gox, int goy){
    int a = abs(x-gox);
    int b = abs(y - goy);
    for(int i=y;i<goy;i++){
        for(int j=x;j<gox;j++){
            paper[i][j] = 1;
        }
    }
}

void bfs(int x, int y, vector<int>&answer){
    queue<pair<int, int>>q;
    q.push({x,y});
    int count=0;
    while(!q.empty()){
        int nowx = q.front().first;
        int nowy = q.front().second;
        count++;
        q.pop();
        for(int i=0;i<4;i++){
            int newx = nowx+dx[i];
            int newy = nowy+dy[i];
            if(newx>=0&&newx<n&&newy>=0&&newy<m&&!checking[newy][newx] && paper[newy][newx]==0){
                checking[newy][newx] = true;
                q.push({newx, newy});
            }
        }
    }
    answer.push_back(count);

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>m>>n>>k;
    paper.resize(m,vector<int>(n,0));
    checking.resize(m,vector<bool>(n,false));
    for(int i=0;i<k;i++){
        int x,y, gox, goy;
        cin>>x>>y>>gox>>goy;
        block(x,y,gox,goy);
    }
    vector<int>answer;
    int aa = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!checking[i][j] && paper[i][j] == 0){
                                checking[i][j] = true;
                bfs(j,i, answer);

                aa++;
            }
        }
    }
    cout<<aa<<"\n";
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<paper[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    sort(answer.begin(), answer.end());
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }
    


}