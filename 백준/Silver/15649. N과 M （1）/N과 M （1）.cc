#include<iostream>
#include<math.h>
#include<vector>

using namespace std;
int n,m;
int number[9];
bool visited[9];

void dfs(int depth){
    if(depth == m){
        for(int i=0;i<m;i++){
            cout<<number[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            visited[i] = true;
            number[depth] = i;
            dfs(depth+1);
            visited[i] = false;
        }
    }

    
}

int main(){
    cin>>n>>m;
    dfs(0);
    
}