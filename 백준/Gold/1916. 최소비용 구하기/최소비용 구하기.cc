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
int n,m,start, dep;
vector<vector<pair<int, int>>>city;
int answer=INT_MAX;
// void dfs(int now, int count, vector<bool>checking){
//     if(now == dep){
//         answer = min(answer, count);
//         return ;
//     }
//     for(int i=0;i<city[now].size();i++){
//         int tempnow = city[now][i].first;
//         if(!checking[tempnow]){
//             checking[tempnow] = true;
//             dfs(tempnow, count+city[now][i].second, checking); 
//             checking[tempnow] = false;

//         } 

       
//     }
// }
void dijkstra(int start, int dep){
    vector<int>dist(n+1, INT_MAX);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0,start});
    while(!pq.empty()){
        int current_cost = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();
        if(current_cost > dist[current_node]) continue;
        for(int i=0;i<city[current_node].size();i++){
            int next_node = city[current_node][i].first;
            int next_cost = current_cost + city[current_node][i].second;
            if(next_cost < dist[next_node]){
                dist[next_node] = next_cost;
                pq.push({next_cost, next_node});
            }
        }
    }
    answer = dist[dep];
}
int main() {
    ios::sync_with_stdio(false);
    cin>>n>>m;
    city.resize(n+1);
    for(int i=0;i<m;i++){
        int q,w,c;
        cin>>q>>w>>c;
        city[q].push_back({w,c});
    }
    cin>>start>>dep;
    vector<bool>checking(n+1, false);
    checking[start] = true;
    // dfs(start, 0, checking);
    dijkstra(start, dep);
    cout<<answer;



    
}
