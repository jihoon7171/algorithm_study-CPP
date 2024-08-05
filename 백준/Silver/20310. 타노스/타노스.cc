#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
#include<map>
using namespace std;


int main(){
    string a;
    cin>>a;
    string answer = "";
    int zerocount=0, onecount=0;
    vector<int>number(a.size());
    for(int i=0;i<a.size();i++){
        if(a[i] == '0'){
            zerocount++;
        }else if(a[i] == '1'){
            onecount++;
        }
    }
    zerocount = zerocount/2;
    onecount = onecount/2;
    for(int i=0;i<a.size()/2;i++){
        if(zerocount != 0){
            answer += '0';
            zerocount--;
        }else if(onecount != 0){
            answer += '1';
            onecount--;
        }
    }
    cout<<answer;

    




}
