#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    vector<int>qw(a);
    for(int i=0;i<a;i++){
        cin>>qw[i];}
    int start=0,end=0;
    int count=0,sum=0;

    while(end<=a){
        if(sum<b){
            sum += qw[end++];
        }else if(sum>b){
            sum -= qw[start++];
        }else {
            count++;
            sum +=qw[end++];
        }
    }

    cout<<count;

 
}