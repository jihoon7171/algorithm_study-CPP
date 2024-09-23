#include <iostream>
#include <vector>
#include<algorithm>
#include<unordered_set>
#include<queue>
#include<cstring>
#include<climits>
using namespace std;

int main() {
    int a;
    cin>>a;
vector<pair<int, int>>fire(a+1);
    for(int i=1;i<=a;i++){
        cin>>fire[i].first>>fire[i].second;
    }
    int answer=0;
    vector<int>dp(a+2,0);
    int count=0;
    for(int i=2;i<=a+1;i++){
        for(int j=1;j<=i;j++){
             if(fire[j].first+j==i){
                dp[i] = max(dp[j]+fire[j].second,  dp[i]);
             }else{
                dp[i] = max(dp[j], dp[i]); 
             }
        }
    }
    cout<<dp[a+1];


} 