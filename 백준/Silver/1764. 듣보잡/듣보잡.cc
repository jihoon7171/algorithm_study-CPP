#include<vector>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

map<string,int>asd;
int main(){
   
    int a,b,count=0;
    cin>>a>>b;
    for(int i=0;i<a;i++){
        string as;
        cin>>as;
        asd[as]=1;
    }
    for(int i=0;i<b;i++){
        string as;
        cin>>as;
        if(asd.find(as) != asd.end()){
            count++;
            asd[as]++;
        }
    }
    cout<<count<<endl;
    for (const auto& pair : asd) {
        if (pair.second > 1) {
            cout << pair.first << endl;
        }
    }
}