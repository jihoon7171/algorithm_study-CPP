#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int all[1000001];
int main(){
    int a;
    cin>>a;
    
    for(int i=2; i<a+1;i++){
        all[i] = all[i-1]+1;
        if(i%6 == 0){
            all[i] = min({all[i], all[i/2]+1,all[i/3]+1});
        }
        else if(i%3==0){
            all[i] = min(all[i], all[i/3]+1);
        }else if(i%2==0){
            all[i] = min(all[i], all[i/2]+1);
        }
    }
    cout<<all[a];
}