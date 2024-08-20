#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int dp[501][501];
int maxthing[500];

int main(){
    int a;
    cin>>a;
    vector<vector<int>>dp(a);
    int j=1;
    for(int i=0;i<a;i++){
        for(int q=0;q<j;q++){
           int qw;
           cin>>qw;
           dp[i].push_back(qw);
        }
        j++;
    }
    for(int i=a-1;i>=1;i--){
        for(int j=0;j<i;j++){
            dp[i-1][j] +=max(dp[i][j], dp[i][j+1]);
        }
    }
    cout<<dp[0][0];
}