#include <iostream>
#include<queue>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
#include<set>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int>card(n+1);
    for(int i=1;i<=n;i++){
        cin>>card[i];
    }
    vector<int>dp(card); 
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++){
            dp[i] = max(dp[i], dp[j]+card[i-j]);
        }
    }
    cout<<dp[n];

}
