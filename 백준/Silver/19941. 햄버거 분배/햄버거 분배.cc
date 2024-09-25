#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<stack>
using namespace std;

int main(){
    int n,k,count=0;
    cin>>n>>k;
    string as;
    cin>>as;
    vector<char>hp(n+1);
    for(int i=1;i<=n;i++){
        hp[i] = as[i-1];
    }
    for(int i=1;i<=n;i++){
        if(hp[i] == 'P'){
        for(int j=i-k;j<=i+k;j++){
            if(j>0 && j<=n){
            if(hp[j] == 'H'){
                hp[j] = 'N';
                count++;
                break;
            }
        }}
        }
    }
    cout<<count;


}