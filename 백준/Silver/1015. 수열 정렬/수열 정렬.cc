#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#include<stack>
#include<unordered_set>
using namespace std;
unordered_set<string>name;


int main(){
    int a;
    cin>>a;
    vector<int>aa(a);
    vector<int>answer(a,0);
    for(int i=0;i<a;i++){
        cin>>aa[i];
    }
    for(int i=0;i<a;i++){
        int temp = aa[i];
        if(i>=1){
        for(int j=i-1;j>=0;j--){
            if(temp>=aa[j]) { answer[i]++;}
        }
        }
        for(int j=i+1;j<a;j++){
            if(temp>aa[j]) { answer[i]++;}
        }
    }
    for(int i=0;i<a;i++){
        cout<<answer[i]<<" ";
    }
    

}


