#include <iostream>
#include <vector>
#include <algorithm>
#include<climits>
#include<cmath>
#include<queue>
#include<tuple>
#include<string>
#include<deque>
using namespace std;
int n;
priority_queue<int, vector<int>, greater<int>>pq;
int answer = 0;
void run(){
    while(!pq.empty()){
        int one = pq.top();
        pq.pop();
        int two = pq.top();
        pq.pop();
        int temp = one+two;
        answer += temp;
        if(pq.size()==0){
            break;
        }
        pq.push(temp);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    if(n==1){
        cout<<0;
        return 0;
    }
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        pq.push({temp});
    }
    run();
    cout<<answer;
}
