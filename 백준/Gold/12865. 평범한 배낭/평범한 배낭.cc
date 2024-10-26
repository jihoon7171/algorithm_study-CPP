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
    int n,k;


int main() {

    cin>>n>>k;
    vector<pair<int, int>>thing(n+1,{0,0});
    for(int i=1;i<=n;i++){
        cin>>thing[i].first>>thing[i].second;
    }
    vector<vector<int>>dp(n+1, vector<int>(k+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(j>=thing[i].first){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-thing[i].first]+thing[i].second);
            }else{
                dp[i][j] = dp[i-1][j];
            }
           
        }
    }
    cout<<dp[n][k];
}