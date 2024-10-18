#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;

int gcd(int a, int b){
    if(a%b==0){
        return b;
        
    }else{
        return gcd(b, a%b);
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int a,b; // a/b
    int n,m; // n/m
    cin>>a>>b>>n>>m;

    int son, mom;
    son = a*m+b*n;
    mom = b*m;
    int temp = gcd(mom, son);

    son = son/temp;
    mom = mom/temp;
    cout<<son<<" "<<mom;
}
