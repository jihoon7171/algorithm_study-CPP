#include<iostream>
#include<vector>

using namespace std;

int num[7]={64,32,16,8,4,2,1};

int main(){
    int a,index=0,count=0;
    cin>>a;
    while(a!=0 && index<7){
        if(a<num[index]){
            index++;
        }else if(a==num[index]){
            count++;
            a -=num[index];
        }else {
            a -=num[index];
            index++;
            count ++;
        }
    }
    cout<<count;

}