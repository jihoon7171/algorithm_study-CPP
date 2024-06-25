#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int a;
    cin>>a;
    vector<int>as(a);
    for(int i=0;i<a;i++){
        cin>>as[i];
    }
    sort(as.begin(), as.end());
    as.erase(unique(as.begin(), as.end()), as.end());
    for(int i=0;i<as.size();i++){
        cout<<as[i]<<" ";
    }

}