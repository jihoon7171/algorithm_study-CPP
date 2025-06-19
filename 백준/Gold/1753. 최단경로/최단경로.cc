#include<vector>
#include<iostream>
#include<climits>
#include<queue>
#include<set>
#include<string>
#include<algorithm>
using namespace std;

int v,e;


vector<vector<pair<int,int>>>graph;

vector<int> dijkstra(int start){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
    q.push({0,start});
    vector<int>answer(v+1, INT_MAX);
    answer[start] = 0;
    while(!q.empty()){
        pair<int, int>t = q.top();
        int d= t.first;
        int now = t.second;
        q.pop();
        for(int i=0;i<graph[now].size();i++){
            int go = graph[now][i].first;
            int distance = graph[now][i].second;
            int temp = distance+d;
            if(temp < answer[go]){
                answer[go] = temp;
                q.push({temp,go});
            }
        }
    }
    return answer;
}

int main() {
    cin>>v>>e;
    int start;
    cin>>start;
    graph.resize(v+1);
    for(int i=0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
        
    }
    vector<int>answer = dijkstra(start);
    for(int i=1;i<=v;i++){
        if(answer[i] == INT_MAX){
            cout<<"INF\n";
        }else{
            cout<<answer[i]<<"\n";
        }
    }

}