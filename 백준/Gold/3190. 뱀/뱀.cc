#include <iostream>
#include <vector>
#include<algorithm>
#include<unordered_set>
#include<queue>
#include<map>
#include<cstring>
#include<climits>
#include <string>
using namespace std;
int a,k,l;

pair<int, int> dr[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int main() {
    map<string, int>direction;
    direction["right"]=0;
    direction["down"]=1;
    direction["up"]=3;
    direction["left"]=2;
    cin>>a>>k;
    vector<vector<int>>map(a+1, vector<int>(a+1,0));
    vector<vector<int>>dist(a+1, vector<int>(a+1,0));
    dist[0][0] = 1;
    for(int i=0;i<k;i++){
        int q,w;
        cin>>q>>w;
        map[q][w] = 1;
    }
    cin>>l;
    queue<pair<int, char>>change;
    for(int i=0;i<l;i++){
        int q;
        char w;
        cin>>q>>w;
        change.push({q,w});
    }
    int nowDirection =0;
    pair<int, int>head = {1,1};
    bool rightleft = true;
    int count=0;
    deque<pair<int, int>>headPath;
    headPath.push_front(head);
    dist[head.first][head.second] = 1;
    while(1){
        count++; 
            head.first += dr[nowDirection].second;
            head.second +=dr[nowDirection].first;
            if(head.first>=1 && head.second>=1 &&head.first<=a&&head.second<=a){
                if(dist[head.second][head.first]==1){
                   break;
                }
                dist[head.second][head.first] = 1;
                headPath.push_back(head);
                if(map[head.second][head.first] != 1){
                    pair<int, int>tail = headPath.front();
                    dist[tail.second][tail.first] = 0;
                    headPath.pop_front();
                }else{
                   map[head.second][head.first] = 0;
                }
            }else{
               break;
            }
       
        if(!change.empty()&&change.front().first == count){
            if(change.front().second == 'D'){
                nowDirection = (nowDirection+1)%4;
            }else if(change.front().second == 'L'){
                nowDirection = (nowDirection+3)%4;
            }
            change.pop();
        }


    }
    cout<<count;

}
