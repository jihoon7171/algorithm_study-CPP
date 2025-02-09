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
int n;

int main() {
    ios::sync_with_stdio(false);
    cin>>n;
    vector<int>num(n);
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    vector<int>dp = num;
    dp[0] = num[0];
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(num[i]>num[j]){
                dp[i] = max(dp[i], num[i]+dp[j]);
            }
        }
    }
    cout<<*max_element(dp.begin(), dp.end());

    
}
