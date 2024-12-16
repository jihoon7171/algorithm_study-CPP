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

struct cmp{
    bool operator()(int a, int b){
        if(abs(a) == abs(b)){
            return a>b;
        }else{
            return abs(a)>abs(b);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int a;
    cin>>a;
    priority_queue<long long, vector<long long>,cmp>pq;
    vector<long long>v;
    for(int i=0;i<a;i++){
        int temp;
        cin>>temp;
        if(temp == 0){
            if(pq.empty()){
                cout<<0<<"\n";
            }else{
                cout<<pq.top()<<"\n";
                pq.pop();
            }
        }else{
            pq.push(temp);
        }


    }


}
