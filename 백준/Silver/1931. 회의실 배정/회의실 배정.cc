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
vector<pair<int, int>>meeting;
bool compare(pair<int, int> a, pair<int, int> b){
        if(a.second<b.second){
            return true;
        }else if(a.second == b.second){
            if(a.first<b.first) return true;
        }
        return false;
}
int answer;
int a;



int main() {
    cin>>a;
    meeting.resize(a);
    answer = 0;
    for(int i=0;i<a;i++){
       
        cin>>meeting[i].first>>meeting[i].second;
    }
    sort(meeting.begin(), meeting.end(), compare);
    int end = meeting[0].second;
    int count=1;
    for(int i=1;i<a;i++){
       if(end <= meeting[i].first){
          count++;
          end = meeting[i].second;
       }
    }

    // for(int i=0;i<a;i++){
    // cout<<meeting[i].first<<" "<<meeting[i].second<<"\n";
    // }
    
    cout<<count;
}