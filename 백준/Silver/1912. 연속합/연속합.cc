#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <map>
#include <cstring>
#include <climits>
#include <string>
#include<deque>
using namespace std;


int main() {
    int a;
    cin>>a;
    vector<int>number(a);
    for(int i=0;i<a;i++){
        cin>>number[i];
    }
    vector<int>dp(a);
    dp[0] = number[0];
    for(int i=1;i<a;i++){
        dp[i] = max(dp[i-1]+number[i],number[i]);
    }
    cout<<*max_element(dp.begin(), dp.end());


}