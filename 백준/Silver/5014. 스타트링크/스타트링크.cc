#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#include<stack>
#include<unordered_set>

using namespace std;
int f,s,g,u,d;
vector<int>dx;
vector<bool>visited(1000001,false);
vector<int>answer(1000001, -1);
void bfs(int a){
    queue<int>q;
    q.push(a);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i=0;i<2;i++){
            int nx = x+dx[i];
            if(nx>0&&nx<=f&&!visited[nx]){
                visited[nx] = true;
                answer[nx] = answer[x]+1;
                q.push(nx);
                // cout<<nx<<" "<<answer[nx]<<"\n";
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cin>>f>>s>>g>>u>>d;
    dx.push_back(u);
    dx.push_back(d*-1);
    visited[s] = true;
    answer[s] = 0;
    bfs(s);
    if(visited[g]){
        cout<<answer[g];
    }else{
        cout<<"use the stairs";
    }



    

    


    

}


