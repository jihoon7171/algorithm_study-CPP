#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;




int main(){
    int a,b,c,count=0;
    cin>>a>>b>>c;
    vector<int>to(a+1);
    for(int i=1;i<=a;i++){
        to[i] = i;
    }
    while(to[b] != to[c]){
        for(int i=1;i<=a;i++){
            if(to[i]%2 != 0){
                to[i] = (to[i]+1)/2;
            }else{
                to[i] = to[i]/2;
            }
        }
        count++;
    }
    cout<<count;

}