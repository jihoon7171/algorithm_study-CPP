#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>distance(n-1);
    vector<int>price(n);
    vector<int>dp(n-1);
    for(int i=0;i<n-1;i++){
        cin>>distance[i];
    }
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    dp[0] = distance[0] * price[0];
    dp[1] = min(price[0]*(distance[0]+distance[1]), dp[0]+(distance[1]*price[1]));
    for(int i=2;i<n-1;i++){
        dp[i] = min(dp[i-1]+(distance[i]*price[i]), dp[i-2]+price[i-1]*(distance[i]+distance[i-1]));
    }

    cout<<dp[n-2];
    




}