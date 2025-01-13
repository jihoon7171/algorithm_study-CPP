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
int n,m;
set<vector<int>>ans;
vector<int>inputnum(m);
void dfs(int count, int index, vector<int>res, vector<bool>checking){
    if(count == m){
        ans.insert(res);
        return ;
    }
    for(int i=index;i<n;i++){
        if(!checking[i]){
            res[index] = inputnum[i];
            checking[i] = true;
            dfs(count+1, index+1, res, checking);
        }
    }

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    inputnum.resize(n);
    for(int i=0;i<n;i++){
        cin>>inputnum[i];
    }
    vector<int>res(m);
    vector<bool>checking(n, false);
    sort(inputnum.begin(), inputnum.end());
    dfs(0,0,res, checking);
    for(vector<int>q : ans){
        for(int i=0;i<q.size();i++){
            cout<<q[i]<<" ";
        }
        cout<<"\n";
    }
}
