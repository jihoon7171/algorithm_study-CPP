#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>
#include<stack>
#include<set>
#include<queue>
#include<limits.h>
#include<queue>
using namespace std;
int n,m;
vector<int>num;

void dfs(int count, int index, vector<int>answer){
    if(count == m){
        for(int i=0;i<m;i++){
            cout<<answer[i]<<" ";
        }
        cout<<"\n";
        return ;
    }

    for(int i=index; i<n;i++){
            answer[count] = num[i];
            dfs(count+1, i, answer);
        
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n>>m;
    num.resize(n);
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    vector<int>check(10,0);
    sort(num.begin(), num.end());
    vector<int>answer(m,0);
    dfs(0,0,answer);






}