#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
cin.tie(nullptr);

    int a,b;
    cin>>a>>b;
    vector<int>number(a);

    cin>>number[0];
    for(int i=1;i<a;i++){
        cin>> number[i];
         number[i] +=number[i-1];
    }
    for(int i=0;i<b;i++){
        int c,d;
        cin>>c>>d;
        c--;
        d--;
        if(c != 0 ){
        cout<<number[d] - number[c-1]<<"\n";}
        else{
            cout<<number[d] <<"\n";
        }
    }

    //5 9 12 14 15
}