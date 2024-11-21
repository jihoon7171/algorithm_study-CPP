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
int m,n;
queue<int>q;

void dfs(vector<vector<int>>&trip, int index, vector<bool>&visited){
    visited[index] = true;
    for(int i=0;i<n;i++){
        if(trip[index][i] == 1&&!visited[i]){
            dfs(trip, i, visited);
        }
    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    vector<vector<int>>trip(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>trip[i][j];
        }
    }
    vector<int>gotrip(m);
    vector<bool>visited(m);
    for(int i=0;i<m;i++){
        int temp;
        cin>>temp;
        gotrip[i] = temp-1;
    }
    dfs(trip, gotrip[0], visited);
    for(int i=0;i<m;i++){
        if(!visited[gotrip[i]]){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";

    


    




}