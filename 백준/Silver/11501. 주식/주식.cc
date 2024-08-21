#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;



long long benefit(const vector<int>& as) {
    long long count=0;
    int big=as[as.size()-1];
    for(int i=as.size()-2;i>=0;i--){
        if(big < as[i]){
            big = as[i];
        }else{
            count += big-as[i];
        }

    }
    return count;
}



int main(){
    int a;
    cin>>a;
    for(int i=0;i<a;i++){
        int qw;
        cin>>qw;
        vector<int>stock(qw);
        for(int j=0;j<qw;j++){
            cin>>stock[j];
        }
        long long result = benefit(stock);
        cout<<result<<"\n";
        
    }
}