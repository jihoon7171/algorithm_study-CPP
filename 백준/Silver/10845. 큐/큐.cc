#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;


int main(){
    int a;
    cin>>a;
    vector<int>stack;
    for(int i=0;i<a;i++){
        string qw;
        cin>>qw;
        if(qw == "push"){
            int num;
            cin>>num;
            stack.insert(stack.begin(),num);
        }else if(qw == "pop"){
            if(stack.size()>=1){
            cout<<stack.back()<<"\n";
            stack.pop_back();
            }else{
                cout<<-1<<"\n";
            }
        }else if(qw=="size"){
            cout<<stack.size()<<"\n";
            
        }else if(qw == "front"){
            if(stack.size() >=1){
                cout<<stack.back()<<"\n";
            }else{
                cout<<-1<<"\n";
            }
        }else if( qw == "back"){
             if(stack.size() >=1){
                cout<<stack.front()<<"\n";
            }else{
                cout<<-1<<"\n";
            }
        }else if(qw == "empty"){
            if(stack.size()>=1){
                cout<<0<<"\n";
            }else {
                cout<<1<<"\n";
            }
        }
    }

}