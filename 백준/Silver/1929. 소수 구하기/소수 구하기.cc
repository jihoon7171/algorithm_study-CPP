#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

bool check(int n){
    if(n==1){
        return false;
    }else{
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int a,b;
    cin>>a>>b;
    int count =0;
    int as = b-a+1;
    for(int i=0;i<as;i++){
        if(check(a)){
            cout<<a<<"\n";
        }
    a++;


    }


}