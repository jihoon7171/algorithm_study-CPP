#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<limits.h>
#include<queue>
using namespace std;
int n,m,k,x;
vector<vector<int>>city;
vector<int>result;
void bfs(int now){
    queue<int>q;
    q.push(now);
    while(!q.empty()){
        int location = q.front();
        q.pop();
        for(int i=0;i<city[location].size();i++){
            if(result[city[location][i]] == INT_MAX){
                result[city[location][i]] = result[location]+1;
                q.push(city[location][i]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin>>n>>m>>k>>x;
    result.resize(n+1, INT_MAX);
    result[x] = 0;
    city.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        city[a].push_back(b);
    }
    bfs(x);
    vector<int>answer;
    for(int i=1;i<=n;i++){
        if(result[i] == k){
            answer.push_back(i);
        }
    }
    if(answer.size()==0){
        cout<<-1;
    }else{
        sort(answer.begin(), answer.end());
        for(int i=0;i<answer.size();i++){
            cout<<answer[i]<<"\n";
        }
        
    }

    
    
}
