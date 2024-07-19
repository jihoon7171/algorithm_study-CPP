#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>distance(n-1);
    vector<int>price(n);
    vector<int>dp(n-1);
    for(int i=0;i<n-1;i++){
        cin>>distance[i];
    }
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    dp[0] = distance[0] * price[0];
    int minprice = price[0];
    dp[1] = min(price[0]*(distance[0]+distance[1]), dp[0]+(distance[1]*price[1]));
    minprice = minprice<price[1] ? minprice : price[1]; 
    for(int i=2;i<n-1;i++){
         minprice = minprice<price[i] ? minprice : price[i]; 
         dp[i] = dp[i-1]+minprice*distance[i];
    }

    cout<<dp[n-2];
    




}