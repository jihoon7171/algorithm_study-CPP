#include <iostream>
#include <vector>
#include<algorithm>
#include<unordered_set>
#include<queue>
#include<cstring>
#include<climits>
using namespace std;
vector<vector<int>>rain(100, vector<int>(100));
int a;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
void bfs(int threshold, vector<vector<bool>>&check, int y, int x){
    queue<pair<int, int>>q;
    q.push({y,x});
    check[y][x] = true;
    while(!q.empty()){
        int nowy = q.front().first;
        int nowx = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int newy = nowy+dy[i];
            int newx = nowx+dx[i];
            if(newy>=0&&newy<a&&nowx>=0&&newx<a&&check[newy][newx]==false&&rain[newy][newx]>threshold){
                check[newy][newx] = true;
                q.push({newy, newx});
            }
        }
    }

}
int main() {
    cin>>a;
    int mina=101,maxa=1;
    rain.resize(a, vector<int>(a));
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            cin>>rain[i][j];
            mina = min(mina, rain[i][j]);
            maxa= max(maxa, rain[i][j]);
        }
    }
    int answer = INT_MIN;
    for(int i=0;i<=maxa;i++){
        int count=0;
        vector<vector<bool>>check(a, vector<bool>(a,false));
        for(int k=0;k<a;k++){
            for(int j=0;j<a;j++){
                if(check[k][j] == false && rain[k][j]>i){
                    bfs(i, check,k,j);
                    count++;
                }
            }
        }
        answer = max(count, answer);
    }
    cout<<answer;


}