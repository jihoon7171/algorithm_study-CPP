#include<vector>
#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    queue<int>yp;
    for(int i=1;i<=a;i++){
        yp.push(i);
    }
    cout<< "<";
    while(!yp.empty()){
        for(int i=0;i<b-1;i++){
            int temp = yp.front();
            yp.pop();
            yp.push(temp);
        }
        int temp1 = yp.front();
        cout<<temp1;
        
        yp.pop();
                if(!yp.empty()){
            cout<<", ";
        }
    }
    cout<<">";


}

