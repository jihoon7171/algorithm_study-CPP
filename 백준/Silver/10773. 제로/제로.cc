#include <iostream>
#include <string>
#include<vector>
using namespace std;



int main() {
    int a,ans=0;
    cin>>a;
    vector<int>num;
    for(int i=0;i<a;i++){
        int qw;
        cin>>qw;
        if(qw==0){
            num.pop_back();
        }
        else{
            num.push_back(qw);
        }
    }
    for(int i=0;i<num.size();i++){
        ans+=num[i];
    }
    cout<<ans;
}
