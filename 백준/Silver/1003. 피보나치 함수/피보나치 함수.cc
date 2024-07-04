#include<vector>
#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
vector<pair<int, int>>dp(41);





int main(){
    int a;
    cin>>a;
    vector<int>inp(a);
    for(int i=0;i<a;i++){
        cin>>inp[i];
    }
    int bigone = *max_element(inp.begin(), inp.end());

    dp[0].first=1;
    dp[0].second=0;
    dp[1].first=0;
    dp[1].second=1;
    for(int i=2;i<=bigone;i++){
        dp[i].first = dp[i-1].first+dp[i-2].first;
        dp[i].second = dp[i-1].second+ dp[i-2].second;
    }
    for(int i=0;i<a;i++){
        cout<<dp[inp[i]].first<<" " <<dp[inp[i]].second<<"\n";
    }

}

