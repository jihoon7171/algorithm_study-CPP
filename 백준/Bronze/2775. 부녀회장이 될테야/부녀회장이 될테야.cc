#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int dp[15][15];
int main() {
    int a,j,q;
    cin>>a;
    for(int i=0;i<a;i++){
        memset(dp, 0, sizeof(dp));
        int k,n;
        cin>>k>>n;

        for(int j=0;j<n;j++){
            dp[0][j] = j+1;
        }

        for( j=1;j<=k;j++){
            for(q=0;q<n;q++){
                dp[j][q] = dp[j-1][q] + dp[j][q-1];
            }
        }
        cout<<dp[k][n-1]<<endl;
    }

    
}
