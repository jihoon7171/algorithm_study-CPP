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
int a;
int answer;
vector<bool>checking;
vector<int>as;
vector<int>now(a);
int plusa(vector<int>qw){
    int sum=0;
    for(int i=0;i<qw.size()-1;i++){
        sum+=abs(qw[i]-qw[i+1]);
    }
    return sum;
}

void dfs( int count){
    if(count == a){
        int sum=0;
        for(int i=0;i<a-1;i++){
            sum+=abs(now[i]-now[i+1]);
        }
        answer = max(answer, sum);
        return ;
    }
    for(int i=0;i<a;i++){
        if(!checking[i]){
            checking[i] = true;
            now[count] = as[i];
            dfs(count+1);
            checking[i] = false;
        }
    }
}


int main() {
    cin>>a;
    answer = INT_MIN;
    as.resize(a);
    now.resize(a);
    checking.resize(a, false);

    for(int i=0;i<a;i++){
        cin>>as[i];
    }
    dfs(0);

    cout<<answer;
}