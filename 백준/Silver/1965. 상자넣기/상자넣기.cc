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
    vector<int>box(a+1);
    for(int i=1;i<=a;i++){
        cin>>box[i];
    }
    vector<int>dp(1001,1);
    for(int i=2;i<=a;i++){
        for(int j=1;j<i;j++){
            if(box[i]>box[j]){
                dp[i] = max(dp[j]+1, dp[i]);
            }
        }
    }
    cout<<*max_element(dp.begin(), dp.end());
   
} 
