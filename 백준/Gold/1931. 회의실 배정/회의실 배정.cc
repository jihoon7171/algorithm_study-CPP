#include <iostream>
#include <vector>
#include <algorithm>
#include<climits>
#include<queue>
#include<tuple>
#include<string>
using namespace std;
vector<pair<int, int>>room;
int n;
int main(){
    cin>>n;
    room.resize(n);
    for(int i=0;i<n;i++){
        cin>>room[i].second>>room[i].first;
    }
    sort(room.begin(), room.end());

    int count = 1;
    int end = room[0].first;
    for(int i=1;i<n;i++){
        if(end <= room[i].second){
            count++;
            end = room[i].first;
        }
    }
    //cout<<end<<"\n";

    cout<<count;
}
