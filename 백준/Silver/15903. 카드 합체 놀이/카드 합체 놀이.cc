#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<queue>
using namespace std;
vector<int>sensor;
int n,m;
vector<int>card;
int main(){
    cin>>n>>m;
    priority_queue<long long, vector<long long>, greater<long long>>card;
    for(int i=0;i<n;i++){
       long long temp;
       cin>>temp;
       card.push(temp);
    }
    for(int i=0;i<m;i++){
        long long one = card.top();
        card.pop();
        long long two = card.top();
        card.pop();
        long long temp = one+two;
        card.push(temp);
        card.push(temp);
    }
    long long total = 0;
    while(!card.empty()){
        total +=  card.top();
        card.pop();

    }
    cout<<total;
}

