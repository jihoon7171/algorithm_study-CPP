#include <iostream>
#include <vector>
#include<algorithm>
#include<unordered_set>
#include<queue>
using namespace std;
 

int main() {
    int n,w,l,now=0,count=0;
    cin>>n>>w>>l;
    queue<int>truck;
    queue<pair<int, int>>bridge;
    for(int i=0;i<n;i++){
       int a;
       cin>>a;
       truck.push(a);
    }
    while(!truck.empty() || !bridge.empty()){
        if(!bridge.empty()&&bridge.front().second>=w){
            now -= bridge.front().first;
            bridge.pop();
        }

        if(!truck.empty() &&now + truck.front() <= l){
            now +=truck.front();
            bridge.push({truck.front(), 0});
            truck.pop();
        }
        
        for(int i=0;i<bridge.size();i++){
            pair<int, int>current = bridge.front();
            current.second++;
            bridge.pop();
            bridge.push(current);
        }


        count++;
    }
    cout<<count;
}
