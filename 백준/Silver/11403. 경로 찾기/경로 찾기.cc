#include<vector>
#include<iostream>
#include<queue>
#include<set>
#include<string>
#include<algorithm>
#include<climits>
using namespace std;
int n;
vector<vector<int>>graph;


void dfs(int count, vector<int>&answer){
    if(count == n+1){
        return; 
    }
    for(int i=0;i<graph[count].size();i++){
        int now = graph[count][i];
        if(answer[now] != -1) continue;
        answer[now] = 1;
        dfs(now,answer);
        
    }
}


int main() {
    cin>>n;
    graph.resize(n+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int temp;
            cin>>temp;
            if(temp == 1){
                graph[i].push_back({j});
            }
        }
    }
    for(int i=1;i<=n;i++){
        vector<int>answer(n+1,-1);
        dfs(i, answer);
        for(int i=1;i<=n;i++){
            if(answer[i] == -1){
                cout<<0<<" ";
            }else{
                cout<<answer[i]<<" ";
            }
        }
        cout<<"\n";
        
    }

}