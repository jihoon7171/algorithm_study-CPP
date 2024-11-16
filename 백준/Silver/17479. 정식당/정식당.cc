#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>
#include<stack>
#include<set>
#include<map>
#include<limits.h>
using namespace std;
long long a,b,c;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>a>>b>>c;
    map<string, long long>basic;
    map<string, long long>special;
    set<string>service;
    for(int i=0;i<a;i++){
        string temp;
        long long price;
        cin>>temp>>price;
        basic.insert({temp, price});
    }
    for(int i=0;i<b;i++){
        string temp;
        long long price;
        cin>>temp>>price;
        special.insert({temp, price});
    }
    for(int i=0;i<c;i++){
        string temp;
        cin>>temp;
        service.insert(temp);
    }
    int qw;
    cin>>qw;
    vector<string>cust(qw);
    for(int i=0;i<qw;i++){
        cin>>cust[i];
    }
    long long bp=0;
    long long idx=0;
    for(int i=0;i<qw;i++){
        if(basic.find(cust[i])!=basic.end()){
            bp+=basic[cust[i]];
        }
    }
    long long sp=0;
    for(int i=0;i<qw;i++){
        if(special.find(cust[i])!=special.end()){
            if(bp>=20000){
                sp+=special[cust[i]];
            }else{
                cout<<"No";
                return 0;
            }
        }
    }
    
    int check=0;
    for(int i=idx;i<qw;i++){
        if(service.find(cust[i])!=service.end()){
            if(bp+sp>=50000){
                check++;
                if(check>1){
                    cout<<"No";
                return 0;
                }
            }else{
                cout<<"No";
                return 0;
            }
        }
    }
    cout<<"Okay";


    




}