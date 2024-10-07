#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <map>
#include <cstring>
#include <climits>
#include <string>
#include<deque>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
cin.tie(nullptr);
cout.tie(nullptr);
    int a;
    cin>>a;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0;i<a;i++){
        int temp;
        cin>>temp; 
        if(!pq.empty() && temp == 0){
            cout<<pq.top()<<"\n";
            pq.pop();
        }else if(pq.empty() && temp == 0){
            cout<<0<<"\n";
        }else{
            pq.push(temp);
        }
    }

}