#include <iostream>
#include<queue>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
#include<set>
using namespace std;

int main() {
    int n,k;
    cin>>n>>k;
    vector<int>coin(n);
    vector<bool>checking(10001);
    vector<int>dp(k+1);
    for(int i=0;i<n;i++){
        cin>>coin[i];
    }
    dp[0] = 1;
    sort(coin.begin(), coin.end());
    for(int i=0;i<n;i++){
        for(int j=coin[i]; j<=k;j++){
            dp[j] += dp[j-coin[i]];
        }
    }
    cout<<dp[k];



}
