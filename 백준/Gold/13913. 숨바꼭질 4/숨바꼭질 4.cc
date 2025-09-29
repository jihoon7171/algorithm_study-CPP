#include <iostream>
#include<queue>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
#include<set>
using namespace std;
vector<pair<int, int>>dist(100001, {-1,-1});
int n,k;
int answer;

void solve(){
    vector<int>v;
    v.push_back(k);
    int now =k;
    while(1){
        int go = dist[now].second;
        if(go == -1){
            break;
        }
        v.push_back(dist[now].second);
        now = dist[now].second;
    }

    //sort(v.begin(), v.end());
    //cout<<answer;
    cout<<"\n";
    for(int i=v.size()-1;i>=0;i--){
        cout<<v[i]<<" ";
    }
}

void bfs(){
    queue<int>q;
    q.push(n);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        int onego = now+1;
        if(onego>=0 && onego<100001 && dist[onego].first == -1){
            dist[onego].first = dist[now].first+1;
            dist[onego].second = now;
            if(onego == k){
               cout<<dist[onego].first;
               solve();
               return ;
            }
            q.push(onego);
        }
        int oneback = now-1;
        if(oneback>=0 && oneback<100001 && dist[oneback].first == -1){
            dist[oneback].first = dist[now].first+1;
            dist[oneback].second = now;
            if(oneback == k){
               cout<<dist[oneback].first;
               solve();
               return ;
            }
            q.push(oneback);
        }
        int jump = now*2;
        if(jump>=0 && jump<100001 && dist[jump].first == -1){
            dist[jump].first = dist[now].first+1;
            dist[jump].second = now;
            if(jump == k){
               cout<<dist[jump].first;
               solve();
               return ;
            }
            q.push(jump);
        }
    }
}

int main() {

    cin>>n>>k;
    answer=  -1;
    dist[n].first = 0;
    dist[n].second = -1;
    if( n == k){
        cout<<0<<"\n";
        cout<<n;
        return 0;
    }
    bfs();



}
