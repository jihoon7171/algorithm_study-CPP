#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;


int main(){
    int a;
    cin>>a;
    vector<int>deque;
    string as;
    for(int i=0;i<a;i++){
        cin>>as;
        if(as == "push_front"){
            int num;
            cin>>num;
            deque.insert(deque.begin(),num);
        }else if( as == "push_back"){
            int num;
            cin>>num;
            deque.push_back(num);
        }else if(as == "pop_front"){
            if(!deque.empty()){
                cout<<deque.front()<<"\n";
                deque.erase(deque.begin());
            }else{
                cout<<-1<<"\n";
            }
        }else if(as == "pop_back"){
            if(!deque.empty()){
                cout<<deque.back()<<"\n";
                deque.pop_back();
            }else{
                cout<<-1<<"\n";
            }
        }else if(as=="empty"){
            if(deque.empty()){
                cout<<1<<"\n";
            }else{
                cout<<0<<"\n";
            }
        }else if(as == "size"){
            cout<<deque.size()<<"\n";
        }else if(as == "front"){
            if(!deque.empty()){
            cout<<deque.front()<<"\n";
            }else{
                cout<<-1<<"\n";
            }
        }else if(as=="back"){
            if(!deque.empty()){
                cout<<deque.back()<<"\n";
            }else{
                cout<<-1<<"\n";
            }
        }
    }
   

}