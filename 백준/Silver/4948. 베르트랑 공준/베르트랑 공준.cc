#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include<math.h>
#include <algorithm>
#include<stack>
#include<set>
#include<map>
#include<limits.h>
using namespace std;

bool sosu(int a){
    for(int i=2;i<=sqrt(a);i++){
        if(a%i == 0)return true;
    }
    return false;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int dp[123456*2];
    dp[1] = 1;
    for(int i=2;i<=123456*2;i++){
        if(!sosu(i)) dp[i] = dp[i-1]+1;
        else dp[i] = dp[i-1];
    }
    while(1){
        int temp;
        cin>>temp;
        if(temp == 0) break;
        cout<<dp[temp*2] - dp[temp]<<"\n";
    }

}