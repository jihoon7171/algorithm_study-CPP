#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int a;
    cin>>a;
    vector<int>s(a+1);
    for(int i=1;i<a+1;i++){
        cin>>s[i];
    }
    int dp[301];
    dp[1] = s[1];
    dp[2] = s[1]+s[2];
    dp[3] = max(s[1]+s[3], s[2]+s[3]);
    for(int i=4;i<a+1;i++){
        int count=0;
        dp[i] = max(dp[i-3] + s[i-1] + s[i], dp[i-2]+s[i]);
    }
    cout<<dp[a];




}