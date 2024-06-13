#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,k,set,i=n-1;
    int count=0;
    cin>>n>>k;
    vector<int>coin(n);
    for(int i=0;i<n;i++){
        cin>>coin[i];
    }

    for(int i=n-1;i>=0;i--){
    if(coin[i]<=k){
        count += k/coin[i];
        k = k%coin[i];
    }
    
    }
    cout<<count;


}