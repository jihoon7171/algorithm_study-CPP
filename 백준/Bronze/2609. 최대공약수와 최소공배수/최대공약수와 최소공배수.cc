#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int gcd(int a, int b){
    int temp;
    while(b){
        temp = a%b;
        a = b;
        b = temp;
    }
    return a;
}

int main(){
    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b)<<"\n"<<(a*b)/gcd(a,b);

}