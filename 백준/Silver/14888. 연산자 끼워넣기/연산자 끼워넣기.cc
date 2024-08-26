#include<iostream>
#include <limits.h>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#include<stack>
#include<unordered_set>
using namespace std;
int num[10];
int giho[4];
int maxans=INT_MIN, minans=INT_MAX,a;

void dfs(int result, int idx){
    if(idx == a){
        maxans = max(result, maxans);
        minans = min(result, minans);
        return;
    }
    for(int i=0;i<4;i++){
        if(giho[i]>0){
            giho[i]--;
            if(i == 0){
                dfs(result + num[idx], idx+1);
            }else if(i ==1){
                dfs(result - num[idx], idx+1);
            }else if(i==2){
                dfs( result * num[idx], idx+1);
            }else if(i==3){
                dfs(result / num[idx], idx+1);
            }
        giho[i] ++;
        }
    }
    return ;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>a;

    for(int i=0;i<a;i++){
        cin>>num[i];
    }
    for(int i=0;i<4;i++){
        cin>>giho[i];
    }
    dfs(num[0], 1);
   
    cout<<maxans<<"\n"<<minans;

    
}


