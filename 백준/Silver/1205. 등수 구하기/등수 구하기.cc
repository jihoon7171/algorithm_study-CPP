#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
#include<map>
using namespace std;

int main(){
    int n,score, p,result=1,same=0;
    cin>>n>>score>>p;
    vector<int>now(n);
    for(int i=0;i<n;i++){
        cin>>now[i];
    }


    for(int i=0;i<n;i++){
        if(now[i]>score){
            result++;
        }
        else if(now[i] == score){
            same++;
        }else{
            break;
        }
    }

    if( n==p && result > p || same + result > p){
        cout<<"-1";

    }else{
        cout<<result;
    }
}
