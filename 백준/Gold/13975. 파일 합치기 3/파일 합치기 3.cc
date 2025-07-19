#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<queue>
#include<climits>
#include<string>
using namespace std;
int t;

void run(int k){
    priority_queue<long long, vector<long long>, greater<long long>> q;
    for(int i=0;i<k;i++){
        int temp;
        cin>>temp;
        q.push(temp);
    }
    long long answer = 0;
    while(q.size() > 1){
        long long one = q.top();
        q.pop();
        long long two = q.top();
        q.pop();
        long long one_two = one+two;
        answer += one_two;
        q.push(one_two);
    }
    cout<<answer<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;

    for(int i=0;i<t;i++){
        long long k;
        cin>>k;   
        run(k);
    }
}


