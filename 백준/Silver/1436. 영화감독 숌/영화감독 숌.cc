#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int main(){
    int a;
    cin>>a;
    int count=0;
    int num = 665;
    while(1){
        num++;
        string as = to_string(num);
        if(as.find("666") != string::npos){
            count++;
        }
        if(count == a){
            break;
        }
    }
    cout<<num;
}