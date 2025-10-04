#include <iostream>
#include<queue>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
#include<set>
using namespace std;
vector<vector<int>>v;
int n;
int result = INT_MAX;
vector<int>answer;
void bfs(int now){
    queue<int>q;
    q.push(now);
    vector<int>visited(n+1, -1);
    visited[now] = 0;
    while(!q.empty()){
        int start = q.front();
        q.pop();
        for(int i=0;i<v[start].size();i++){
            int newgo = v[start][i];
            if(visited[newgo] == -1){
                visited[newgo] = visited[start]+1;
                q.push(newgo);
            }
        }
    }
    int temp = 0;
    for(int i=1;i<visited.size();i++){
        temp = max(visited[i], temp);
    }
    //cout<<temp<<"\n";
    // for(int i=1;i<=n;i++){
    //     cout<<visited[i]<<" ";
    // }
    if(temp == result){
        answer.push_back(now);
        //cout<<now<<"push_back\n";
    }else if(temp < result){
        answer.clear();
        answer.push_back(now);
        //cout<<now<<"push_back\n";
        result = temp;
    }else{
        
    }
    // cout<<now<<" answer\n";
    // for(int i=0;i<answer.size();i++){
    //     cout<<answer[i]<<" ";
    // }
    // cout<<"\n";
}

int main() {
    cin>>n;
    v.resize(n+1);
    while(1){
        int a,b;
        cin>>a>>b;
        if(a==-1 && b==-1){
            break;
        }
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        bfs(i);
    }
    sort(answer.begin(), answer.end());
    cout<<result<<" "<<answer.size()<<"\n";
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }


}
