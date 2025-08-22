#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;



int main(){

    int a;
    cin>>a;
    int count=0;
    while(a>=0){
        if(a%5==0){
            count +=a/5;
            cout<<count;
            return 0;
        }else{
            a -=3;
            count++;
        }
    }
    cout<<-1;


}