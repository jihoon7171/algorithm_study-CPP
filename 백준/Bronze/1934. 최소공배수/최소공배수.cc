#include<vector>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;

int min(int a, int b){
    if(a%b==0){
        return b;
    }else{
        return min(b, a%b);
    }
}

int main(){
    int a;
    cin>>a;
    for(int i=0;i<a;i++){
        int q,w;
        cin>>q>>w;
        cout<<(q*w)/min(q,w)<<endl;
    }
}