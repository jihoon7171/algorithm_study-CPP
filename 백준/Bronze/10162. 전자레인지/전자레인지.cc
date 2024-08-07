#include <iostream>
#include <string>
using namespace std;

int dp[16];

int main() {
 
    int a;
    cin>>a;
    int acount=0, bcount=0, ccount=0;
    while(a>0){
        if(a>=300){
            a = a-300;
            acount++;
        }else if(a<300 && a>=60){
            a = a-60;
            bcount++;
        }else if(a<60){
            a = a-10;
            ccount++;
        }

    }
    if(a == 0){
        cout<<acount<<" "<<bcount<<" "<<ccount;
    }else{
        cout<<"-1";
    }



}
