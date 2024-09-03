#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
vector<vector<int>>comp(1001);
bool visited[1001];
int checked[1001];

void dfs(int a){
    visited[a] = true;
    for(int i=0;i<comp[a].size();i++){
        int y = comp[a][i];
        if(!visited[y]){
            dfs(y);
        }
    }

}

int main(){
    int a,b,count=0;
    cin>>a>>b;

    for(int i=0;i<b;i++){
        int q,w;
        cin>>q>>w;
        comp[q].push_back(w);
        comp[w].push_back(q);
        checked[q]=1;
        checked[w]=1;
    }
    for(int i=1;i<=a;i++){
        if(!visited[i]){
            count++;
            dfs(i);
        }
    }
    cout<<count;
    
}

