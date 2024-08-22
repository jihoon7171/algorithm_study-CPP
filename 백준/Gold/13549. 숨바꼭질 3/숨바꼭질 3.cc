#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
int dp[100001];
int a,b;

void dpsolution(int start){

    for(int i=start+1;i<=b;i++){
        if(i%2==0){
            dp[i] = min(dp[i/2], dp[i-1]+1);
        }else{
            dp[i] = min(dp[(i+1)/2]+1, dp[i-1]+1);
        }
    }
}

int main(){

    cin>>a>>b;
    dp[a] = 0;
    for(int i=a;i>=0;i--){
        dp[i] = a-i;
    }
    dpsolution(a);
    cout<<dp[b];

    
}