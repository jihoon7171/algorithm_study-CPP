#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <map>
#include <cstring>
#include <climits>
#include <string>
#include<cstring>
#include<deque>
using namespace std;

int main() {
    int a;
    cin>>a;
    vector<int>dp(a+1);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 5;
    if(a<=4){
        cout<<dp[a];
        return 0;
    }else{
        for(int i=5;i<=a;i++){
            dp[i] = (dp[i-1]+dp[i-2])%15746;
        }
    }
    cout<<dp[a];

}