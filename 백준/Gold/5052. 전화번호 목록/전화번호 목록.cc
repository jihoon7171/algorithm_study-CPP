#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>
#include<stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
cin.tie(nullptr);
cout.tie(nullptr);
    int a;
    cin>>a;
    for(int i=0;i<a;i++){
        int m;
        cin>>m;
        vector<string>fresh(m);
        for(int j=0;j<m;j++){
            cin>>fresh[j];
        }
        sort(fresh.begin(), fresh.end());
        bool tag = false;
        for(int j=0;j<m-1;j++){
            string a = fresh[j];
            string b = fresh[j+1];
            if(a.size()>b.size()) continue;
            string temp = b.substr(0,a.size());
            if(a==temp){
                tag = true;
                break;
            }
        }
        if(tag){
            cout<<"NO"<<"\n";
        }else{
            cout<<"YES"<<"\n";
        }
    }
    return 0;



}