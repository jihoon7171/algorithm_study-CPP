#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<limits.h>
#include<queue>
using namespace std;
int n,m;
int main() {
    ios::sync_with_stdio(false);
    cin>>n>>m;
    vector<int>th(n+1,-1);
    vector<int>dp(n+1);
    dp[0] = 1;
    dp[1] = 1;
    int answer = 1;
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    int back = 0;
    for(int i=0;i<m;i++){
        int temp;
        cin>>temp;
        answer *= dp[temp-back-1];
        back = temp;

    }
    answer *=dp[n-back];
    cout<<answer;








    
}
