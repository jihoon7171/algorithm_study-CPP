#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<queue>
#include<climits>
#include<string>
using namespace std;

int n,m;
int th;
vector<int>hum;
vector<vector<int>>game;
vector<vector<int>>party;
vector<bool>visited;

void run(int now){
    visited[now] = 1;
    hum[now] = 1;
    for(int i=0;i<party[now].size();i++){
        int now_game = party[now][i];
        for(int j=0;j<game[now_game].size();j++){
            if(visited[game[now_game][j]]) continue;
            run(game[now_game][j]);
        }
    }
}

void get_answer(){
    int answer = m;
    for(int i=1;i<=m;i++){
        for(int j=0;j<game[i].size();j++){
            if(hum[game[i][j]]) {
                answer = answer-1;
                break;
            }

        }
    }
    cout<<answer;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    hum.resize(n+1);
    party.resize(n+1);
    game.resize(m+1);
    cin>>th;
    for(int i=0;i<th;i++){
        int temp;
        cin>>temp;
        hum[temp] = 1; // 진실을 알고있는 사람
    }
    for(int i=1;i<=m;i++){
        int h;
        cin>>h;
        for(int j=0;j<h;j++){
            int temp;
            cin>>temp;
            game[i].push_back(temp);
            party[temp].push_back(i);
        }
    }
    visited.resize(n+1);

    for(int i=1;i<=n;i++){
        if(hum[i] == 1 && !visited[i]){
            visited[i] = true;
            run(i);
        }
    }
    get_answer();
    

}


