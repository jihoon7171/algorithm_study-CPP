#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <map>
#include <cstring>
#include <climits>
#include <string>
#include<cstring>
#include<deque>
using namespace std;


int main() {
    int a;
    cin>>a;
    vector<pair<long long, long long>>room(a);
    for(int i=0;i<a;i++){
        cin>>room[i].first>>room[i].second;
    }
    sort(room.begin(), room.end());
    priority_queue<long long, vector<long long>, greater<long long>>endtime;
    endtime.push(room[0].second);
    for(int i=1;i<a;i++){
        if(endtime.top() <= room[i].first){
            endtime.pop();
            endtime.push(room[i].second);
        }else{
            endtime.push(room[i].second);
        }
    }
    cout<<endtime.size();
}