#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;

int main(){
    string a,b;
    getline(cin, a);
    getline(cin, b);
    int point=0;
    int count=0;
    while(1){
          int temp = a.find(b,point);
        if(temp  != string::npos ){
            count++;
            point = temp+b.size();
        }else{
            break;
        }
    }
    cout<<count;
}