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
#include<sstream>
using namespace std;
int n,m;
vector<int>num;

void dfs(int& count, int sum, int index){
    if(index == n){
        return ;
    }
    if(sum+num[index]== m){
    count++;
    }
    dfs(count, sum, index+1);
    dfs(count, sum+num[index], index+1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    num.resize(n);
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    int count =0;
    dfs(count, 0,0);
    cout<<count;

}
