#include<vector>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;


int main(){
    ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int a,b;
    cin>>a>>b;
    unordered_map<string, string>asd;
    unordered_map<string, string>reverse_asd;

    for(int i=1;i<=a;i++){
        string as;
        cin>>as;
        asd[as] = to_string(i);
        reverse_asd[to_string(i)] = as;
    }
    for(int i=0;i<b;i++){
        string qw;
        cin>>qw;
        if(asd.find(qw) != asd.end()){
            cout<<asd[qw]<<"\n";
        }else if(reverse_asd.find(qw) != reverse_asd.end()){
            cout<<reverse_asd[qw]<<"\n";
        }
    }


}