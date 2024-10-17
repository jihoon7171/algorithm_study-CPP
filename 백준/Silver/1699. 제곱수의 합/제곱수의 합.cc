#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int a;
    cin>>a;
    vector<int>dp(a+1,10000);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 1;
    int temp = 2;
    if(a<=4){
        cout<<dp[a];
        return 0;
    }else{
        for(int i=5;i<=a;i++){
            for(int j=1;j*j<=i;j++){
                dp[i] = min(1+dp[i-j*j], dp[i]);
            }
        }
    }

    cout<<dp[a];




}
