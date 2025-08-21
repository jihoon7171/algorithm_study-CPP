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
int u,v;
vector<pair<int, int>>sq;
int count = 0;
vector<pair<int, int>>space(101);
vector<int>visited(101,-1);
void going(int now, int goal){
    int dis = goal - now;
    while(dis != 0){
        if(dis >= 6 ){
            dis -= 6;
            ::count++;
        }else{
            dis -= dis;
            ::count++;
        }
    }
}

void bfs(){
    queue<int>q;
    q.push(1);
    visited[1] = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i=1; i<=6; i++){
            int next = now + i;
            if(next > 100) continue;

            // 뱀/사다리 이동
            if(space[next].second != 0) next = space[next].second;

            if(visited[next] == -1){
                visited[next] = visited[now] + 1;
                q.push(next);
            }
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>u>>v;
    for(int i=0;i<u+v;i++){
        int a,b;
        cin>>a>>b;
        sq.push_back({a,b});
    }
    //cout<<"\n";
    sort(sq.begin(), sq.end());
    // for(int i=0;i<sq.size();i++){
    //     cout<<sq[i].first<<" "<<sq[i].second<<"\n";
    // }
    for(int i=1;i<101;i++){
        space[i].first = i;
        space[i].second = 0;
    }
    for(int i=0;i<sq.size();i++){
        space[sq[i].first].second = sq[i].second;
    }

    // for(int i=1;i<101;i++){
    //     cout<<space[i].first<<" "<<space[i].second<<"\n";
    // }

    bfs();

    cout<<visited[100];

}
