#include<vector>
#include<iostream>
using namespace std;
int dp[100001];

int findmax(int a, int b, int c){
    int temp = a>b ? a: b;
    temp = temp > c ? temp : c;
    return temp;
}

int main(){
    int a;
    cin>>a;
    vector<int>wine(a+1);
    for(int i=1;i<=a;i++){
        cin>>wine[i];
    }
    dp[1] = wine[1];
    if(a==1){
        cout<<dp[1];
        return 0;
    }
    dp[2] = dp[1]+wine[2];
    if(a==2){
        cout<<dp[2];
        return 0;
    }
    if(a>2){
        for(int i=3;i<=a;i++){
            dp[i] = findmax(dp[i-3]+wine[i-1]+wine[i], dp[i-2]+wine[i], dp[i-1]);
    }
    cout<<dp[a];
    }
}