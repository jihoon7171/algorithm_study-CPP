#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

bool find(int a){
    if(a == 1){
        return false;
    }
    for(int i=2;i<=sqrt(a);i++){
        if(a%i == 0){
            return false;
        }
    }
    return true;
}


int main(){
    int a,count=0;
    cin>>a;
    vector<int>qw(a);
    for(int i=0;i<a;i++){
        cin>>qw[i];
    }
    for(int i=0;i<a;i++){
        if(find(qw[i])){
            count++;
        }
    }
    cout<<count;


}