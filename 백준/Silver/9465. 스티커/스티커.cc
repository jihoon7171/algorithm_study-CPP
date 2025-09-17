#include <iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>>sticker(2, vector<int>(n));
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                cin>>sticker[i][j];
            }
        }
        vector<vector<int>>dp(2, vector<int>(n));
        dp[0][0] = sticker[0][0];
        dp[1][0] = sticker[1][0];
        for(int i=1;i<n;i++){
            for(int j=0;j<2;j++){
                int s;
                if(j == 0){
                    s = 1;
                }else{
                    s = 0;
                }
                dp[j][i] = max(dp[j][i-1],dp[s][i-1]+sticker[j][i]);
            }
        }
        cout<<max(dp[0][n-1], dp[1][n-1])<<"\n";;
    }
}
