#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
vector<vector<int>>maze;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
   int a;
   cin>>a;
   int dp[a+1];
   dp[1] = 3;
   dp[2] = 7;
   dp[3] = 17;
   dp[4] = 41;
   if(a<=4){
    cout<<dp[a];
    return 0;
   }else{
    for(int i=4;i<=a;i++){
        dp[i] = (dp[i-1]*2+dp[i-2])%9901;
    }
    cout<<dp[a];
   }
 

}
