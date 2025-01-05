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
int n,m,k;
vector<int>num;
set<vector<int>>s;
void dfs(int count, vector<int>v, int index, vector<bool>checking){
    if(count == m){
        s.insert(v);
        return ;
    }

    for(int i=0;i<n;i++){
        if(!checking[i]){
            v[count] = num[i];
            checking[i] = true;
            dfs(count+1, v, i+1,checking);
            checking[i] = false;

        }

    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    num.resize(n);
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    sort(num.begin(), num.end());
    vector<int>v(m,0);
    vector<bool>checking(n,false);
    dfs(0,v,0,checking);
    for(auto t : s){
        for(int n : t){
            cout<<n<<" ";
        }
        cout<<"\n";
    }


    
}
