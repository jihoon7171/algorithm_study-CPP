#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<queue>
#include<climits>
#include<string>
using namespace std;
int n;
int answer = 0;
int longdis;
vector<vector<pair<int, int>>>tree; //목적지, 가중치
void run(int start, int now, int count,vector<bool> &visited){
    if(count > answer){
        answer = count;
        longdis = now;
    }
    visited[now] = true;
    for(int i=0;i<tree[now].size();i++){
        if(!visited[tree[now][i].first]){
            run(start, tree[now][i].first, count+tree[now][i].second, visited);
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    tree.resize(n+1);
    //트리의 간선은 n-1 개임
    for(int i=0;i<n;i++){
            int s;
            cin>>s;
        while(1){
            int e;
            cin>>e;
            if(e==-1){
                break;
            }
            int v;
            cin>>v;
            tree[s].push_back({e,v});
            tree[e].push_back({s,v});           
        }
    }
    vector<bool>visited(n+1);
    visited[1] = true;
    run(1,1,0,visited);

    answer = 0;
    for(int i=0;i<n+1;i++){
        visited[i] = false;
    }
    visited[longdis] = true;
    run(longdis, longdis, 0,visited);



    
    // for(int i=1;i<=n;i++){
    //     vector<bool>visited(n+1);
    //     visited[i] = true;
    //     run(i,i,0,visited);
    // }
    cout<<answer;
}


