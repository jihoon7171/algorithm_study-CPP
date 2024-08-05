#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
#include<map>
#include<cstring>
using namespace std;


int main(){
    string a;
    cin>>a;
    int onecount=0, zerocount=0;
    string ans="";
    bool checking[500];
    for(int i=0;i<a.size();i++){
        if(a[i] == '0'){
            zerocount++;
        }else if(a[i] == '1'){
            onecount++;
        }
    }
    int one=0, zero=0;
    memset(checking, false, sizeof(checking));

    for(int i=0;i<a.size();i++){
        if(one == onecount/2){
            break;
        }else{
            if(a[i] == '1'){
                checking[i] = true;   
                one++;     }
        }
    }

        for(int i=a.size()-1;i>=0;i--){
        if(zero == zerocount/2){
            break;
        }else{
            if(a[i] == '0'){
                checking[i] = true;     
                zero++;       }
        }
    }
    for(int i=0;i<a.size();i++){
        if(!checking[i]){
            ans += a[i];
        }
    }
    cout<<ans;


}
