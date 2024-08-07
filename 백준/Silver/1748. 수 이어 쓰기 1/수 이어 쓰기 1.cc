#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

int main(){
    int a;
    cin>>a;
    if(a<10){
        cout<<a;
        return 0;
    }
    int count=0;

    for(int i=1;i<=a;i*=10){
        count += a-i+1;
    }
    cout<<count;

}