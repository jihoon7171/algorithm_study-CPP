#include <iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;


int main() {
    int n,k;
    cin>>n>>k;
    vector<int>dp(k+1, INT_MAX);
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        dp[temp] = 1;
    }
    dp[0] = 0;
    for(int i=1;i<=k;i++){
		if(dp[i] == 1) continue;
        for(int j=0;j<=i;j++){
            if(dp[j]!=INT_MAX && dp[i-j]!=INT_MAX){
                dp[i] = min(dp[j]+dp[i-j], dp[i]);
            }
        }
    }
	if(dp[k] == INT_MAX){
		cout<<-1;
	}else{
		cout<<dp[k];
	}
}
