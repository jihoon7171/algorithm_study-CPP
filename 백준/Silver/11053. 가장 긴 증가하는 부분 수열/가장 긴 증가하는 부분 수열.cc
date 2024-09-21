#include <iostream>
#include <vector>
#include<algorithm>
#include<unordered_set>
#include<queue>
#include<cstring>
using namespace std;

int main() {
    int a;
    cin>>a;
    vector<int>su(a+1);
    for(int i=1;i<=a;i++){
        cin>>su[i];
    }
    vector<int>dp(a+1,1);
    int maxarray = su[1];
    for(int i=2;i<=a;i++){
        for(int j=1;j<i;j++){
            if(su[j]<su[i]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    sort(dp.begin(), dp.end());
    cout<<dp[a];

} 
