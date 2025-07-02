#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
vector<long long>dp;
int main(){
    long long n;
    cin>>n;
    dp.resize(n+1);
    dp[0] = 0;
    dp[1] = 1;
    if(n<=1){
        cout<<dp[n];
        return 0;
    }
    for(long long i=2;i<=n;i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    cout<<dp[n];
}

